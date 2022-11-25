// 任务是以类的方式传递
// Created by Ycq on 2022/7/23.
//https://www.bilibili.com/video/BV1A34y1J7RM

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

std::mutex m;
class Task{
public:
    virtual void run(){
        //do something
        std::unique_lock<std::mutex> ul(m);
        std::cout << "hello world!" << std::endl;
    }
};

class ThreadPool{
public:
    /*!
     *
     * @param count 线程池中的线程数量
     */
    ThreadPool(int count)
    :running_flag_(false){
        //添加线程
        for (int i = 0; i < count; i++){
            threads_.emplace_back(&ThreadPool::work, this);
        }
    }

    ~ThreadPool(){
        for (auto& th : threads_){
                th.detach(); //分离线程
//                th.join();
        }
    }
    void start(){
        running_flag_ = false;
    }
    void stop(){
        running_flag_ = true;
    }
    void push_task(Task* task) { //将任务添加到队列
        if (running_flag_){
            std::cout << "pooling stoping...!" << std::endl;
            return ;
        }

        {
            std::unique_lock<std::mutex> ulock(this->mtx_);
            this->tasks_.push(task);
        }
        //唤醒一个线程
        this->cv_.notify_all();
    }

private:
    std::vector<std::thread> threads_; //线程集合
    std::queue<Task*> tasks_; //任务队列
    std::atomic_bool running_flag_; //判断当前是否在运行，true表示运行
    std::condition_variable cv_; //条件变量
    std::mutex mtx_; //等待任务的锁

    Task* get_onte_task(){
        std::unique_lock<std::mutex> ulock(this->mtx_);
        cv_.wait(ulock, [this](){ return running_flag_ || !tasks_.empty(); });    // wait 直到有 task
        if (running_flag_ && tasks_.empty()) return nullptr;

        Task* task = this->tasks_.front();
        this->tasks_.pop();
        return task;
    }

    void work(){
        while (true){//如果线程池在运行
            Task* task = get_onte_task();
            if (task){
                task->run();
            }
            else{
                ;
            }
        }
    }

};

//需要继承Task类，重写run函数
//int main()
//{//修改了之后，需要在主程序中留够足够长的时间
//    try {
//        ThreadPool pool(6);
//        Task t[10];
//        for (auto &ta : t) {
//            pool.push_task(&ta);
//        }
//
//        std::this_thread::sleep_for(std::chrono::seconds(5));//延时需要大于上面程序执行的时间，不然主线程会退出，子线程执行不完
//        pool.stop();
//        pool.push_task(t);
//
//        pool.start();
//        for (auto &ta : t) {
//            pool.push_task(&ta);
//        }
//        std::this_thread::sleep_for(std::chrono::seconds(5));//延时需要大于上面程序执行的时间，不然主线程会退出，子线程执行不完
//        std::cout << "end..." << std::endl;
//
//        return 0;
//    }
//
//    catch(std::exception& e){
//        std::cout << "some unhappy happened... " << e.what() << std::endl;
//    }
//}