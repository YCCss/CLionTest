//
// Created by Ycq on 2022/7/24.
//https://blog.csdn.net/zdarks/article/details/46994607
//https://github.com/progschj/ThreadPool



#ifndef ILOVERS_THREAD_POOL_H
#define ILOVERS_THREAD_POOL_H

#include <iostream>
#include <functional>
#include <thread>
#include <condition_variable>
#include <future>
#include <atomic>
#include <vector>
#include <queue>

//// 命名空间
//namespace ilovers {
//    class TaskExecutor;
//}

//class ilovers::TaskExecutor{
class TaskExecutor{
    //用于包装函数等   //https://blog.csdn.net/weixin_44378800/article/details/115210731
    using Task = std::function<void()>;
private:
    // 线程池
    std::vector<std::thread> pool;
    // 任务队列
    std::queue<Task> tasks;
    // 同步
    std::mutex m_task;
    std::condition_variable cv_task;
    // 是否关闭提交
    std::atomic<bool> stop;

public:
    // 构造
    TaskExecutor(size_t size = 4): stop {false}{
        size = size < 1 ? 1 : size;
        for(size_t i = 0; i< size; ++i){
            pool.emplace_back(&TaskExecutor::schedual, this);    // push_back(std::thread{...})
        }
    }

    // 析构
    ~TaskExecutor(){
        for(std::thread& thread : pool){
            thread.detach();    // 让线程“自生自灭”, 但是主线程执行完了，不会等待子线程
//            thread.join();        // 等待任务结束， 前提：线程一定会执行完， 执行后主程序不会自动结束
        }
    }

    // 停止任务提交
    void shutdown(){
        this->stop.store(true); //原子操作的赋值
    }

    // 重启任务提交
    void restart(){
        this->stop.store(false);
    }
    //延时s
    void sleep(int sec){
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    // 提交一个任务
    template<class F, class... Args>
    auto commit(F&& f, Args&&... args) ->std::future<decltype(f(args...))> { //delctype(expr) 用来推断 expr 的类型, &&是C++ 11新特性，代表右值引用。
        if(stop.load()){    // stop == true ??
            throw std::runtime_error("task executor have closed commit.");
        }

        using ResType =  decltype(f(args...));    // typename std::result_of<F(Args...)>::type, 函数 f 的返回值类型
        auto task = std::make_shared<std::packaged_task<ResType()>>(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...) //函数绑定参数
        );    // wtf !
        {    // 添加任务到队列
            std::lock_guard<std::mutex> lock {m_task};
            tasks.emplace([task](){   // push(Task{...})
                (*task)();
            });
        }
        cv_task.notify_all();    // 唤醒线程执行

        std::future<ResType> future = task->get_future();
        return future;
    }

private:
    // 获取一个待执行的 task
    Task get_one_task(){
        std::unique_lock<std::mutex> lock {m_task};
//        cv_task.wait(lock, [this](){ return !tasks.empty(); });    // wait 直到有 task
        cv_task.wait(lock, [this](){ return stop || !tasks.empty(); });    // wait 直到有 task
        if (stop && tasks.empty()) return nullptr;
        Task task {std::move(tasks.front())};    // 取一个 task
        tasks.pop();
        return task;
    }

    // 任务调度
    void schedual(){
        while(true){
            if(Task task = get_one_task()){
                task();    //
            }else{
                // return;    // done
            }
        }
    }
};

#endif
//std::mutex t_m;
//void f()
//{
//    std::unique_lock<std::mutex> ul(t_m);
//    std::cout << "hello, f !" << std::endl;
//}
//
//struct G{
//    int operator()(){
//        std::unique_lock<std::mutex> ul(t_m);
//        std::cout << "hello, g !" << std::endl;
//        return 42;
//    }
//};
//
//void ff(int a)
//{
//    std::unique_lock<std::mutex> ul(t_m);
//    std::cout << "a : " << a << std::endl;
//}

////传入函数就可以，比较方便
//int main()
//try{
////    ilovers::TaskExecutor executor {5};
//
//    TaskExecutor executor {5};
//    std::future<void> f1 = executor.commit(ff, 5);
//    std::future<void> f2 = executor.commit(f);
//    std::future<int> fg = executor.commit(G{});
//    std::future<std::string> fh = executor.commit([&]()->std::string { std::unique_lock<std::mutex> ul(t_m);  std::cout << "hello, h !" << std::endl; return "hello,fh !";});
//    executor.shutdown();
//
//    std::cout << fg.get() << " " << fh.get() << std::endl;
//
//    executor.restart();    // 重启任务
//    for (int i = 0; i < 4; i++)
//    { //使用detech(),主线程会执行完，然而子线程还没执行完就退出了
//        f2 = executor.commit(ff, i);
//    }
//    executor.commit(f);   //
//
//    std::this_thread::sleep_for(std::chrono::seconds(5));//延时需要大于上面程序执行的时间，不然主线程会退出，子线程执行不完
//    std::cout << "end..." << std::endl;
//    return 0;
//}
//catch(std::exception& e){
//    std::cout << "some unhappy happened... " << e.what() << std::endl;
//}

//Forexample
//void f() {
//    for (int i(0); i < 10000; i++)
//    {
//        count_++;
//    }
//}
//
//int main()
//{
//    Solution so; //解决问题类
//    Package p; //调用接口类
//    TaskExecutor te(5);
//    te.commit(f);
//    te.commit(f);
//
//    te.sleep(3);
//    p.print(count_);
//
//    cout<<" 你好 "<<endl;
//
//    return 0;
//}