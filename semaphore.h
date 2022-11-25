//
// Created by Ycq on 2022/7/29.
//信号量PV操作

#ifndef CLIONTEST_SEMAPHORE_H
#define CLIONTEST_SEMAPHORE_H
#include <mutex>
#include <condition_variable>

using namespace std;

//不是很理解v操作
class Semaphore
{
private:
    int count;
    mutex m;
    condition_variable cv;
public:
    Semaphore(int count_) : count(count_) {}

    // p操作：count 减1，如果count<0，则资源不足，把线程放入阻塞队列
    void p() {
        unique_lock<mutex> loc(m);

        if (--count < 0) {
            cv.wait(loc);
        }
    }

    // v操作：count加1，如果 count <= 0 ，则有线程阻塞，在阻塞队列里唤醒一个线程
    void v() {
        unique_lock<mutex> loc(m);
        if (++count <= 0) {
            cv.notify_one();
        }
    }
};

//这个好理解一些
class Semaphore_ {
public:
    Semaphore_(long count = 0) :count_(count) {}
    void v() {
        unique_lock<mutex> lock(mutex_);
        ++count_;
        cv_.notify_one();
    }
    void p() {
        unique_lock<mutex> lock(mutex_);
        //第二个参数为false时才会阻塞，
        //为使用Lambda表达式创建匿名函数
        cv_.wait(lock, [=] { return count_ > 0; });
        --count_;
    }
    void setCount(long count = 0) {
        count_ = count;
    }

private:
    mutex mutex_;
    condition_variable cv_;
    long count_;
};


#endif //CLIONTEST_SEMAPHORE_H


//Semaphore_ s(0);	 // 信号量初始化count为0
//
//void first() {
//    for (int i = 0; i < 10; i++) {
//        cout << "first" << endl;   // 期望先执行的代码
//        s.v();    // 期望先执行的代码 后面 写上v
//    }
//}
//
//void second() {
//    for (int i = 0; i < 5; i++)
//    {
//        s.p();	// 期望后执行的代码 前面写上p
//        cout << "second" << endl;  // 期望后执行的代码
//    }
//
//}
//
//void thrid() {
//    for (int i = 0; i < 5; i++)
//    {
//        s.p();	// 期望后执行的代码 前面写上p
//        cout << "second" << endl;  // 期望后执行的代码
//    }
//
//}
//
//int main() {
//    thread t2(second);
//
//    thread t3(thrid);
//    this_thread::sleep_for(chrono::milliseconds(500));
//    thread t1(first);
//    t1.detach();
//    t2.detach();
//    t3.detach();
//    this_thread::sleep_for(chrono::milliseconds(500));
//}