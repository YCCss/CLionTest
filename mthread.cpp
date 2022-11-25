// 多线程和锁
// Created by Ycq on 2022/7/22.
//https://www.cnblogs.com/zizbee/p/13520823.html

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <Windows.h>
using namespace std;


//void proc1(int a) {
//    for (int i = 0; i < a; i++)
//        cout << "child1: " << i << endl;
//}
//void proc2(int a) {
//    for (int i = 0; i < a; i++)
//        cout << "child2: " << i << endl;
//}
//int main()
//{//简单多线程用例, 两个线程和主线程交替运行
//    thread th1(proc1, 10);
//    thread th2(proc2, 10);
//    for (int i = 0; i < 5; i++)
//        cout << "main: " << i << endl;
//    th1.join();
//    th2.join();
//    cout << "finish!" << endl;
//    return 0;
//}


//mutex m;
//void proc1(int a) {
//    m.lock();
//    for (int i = 0; i < a; i++)
//        cout << "child1: " << i << endl;
//    m.unlock();
//}
//void proc2(int a) {
//    m.lock();
//    //lock_guard<mutex> g1(m);可以替换上面语句，并且不用调用ulock,在离开作用域时会自动解锁
//    //unique_lock类似于lock_guard,使用unique_lock后可以手动lock()与手动unlock();
//    for (int i = 0; i < a; i++)
//        cout << "child2: " << i << endl;
//    m.unlock();
//}
//int main()
//{//多线程 + 互斥量用例, 线运行主线程，再按照线程的建立顺序执行
//    thread th1(proc1, 10);
//    thread th2(proc2, 10);
//    m.lock();
//
//    for (int i = 0; i < 5; i++)
//        cout << "main: " << i << endl;
//    m.unlock();
//    th1.join();
//    th2.join();
//    cout << "finish!" << endl;
//    return 0;
//}

//mutex m;
//int kk = 0;
//condition_variable cv;
//void proc1(int a) {
//    unique_lock<mutex> p1(m);//结束自动会解锁
//    for (int i = 0; i < a; i++){
////        while (kk != 0) cv.wait(p1); //k不等于0就阻塞， 下面的语句好理解些
//        cv.wait(p1, [&](){return kk == 0;}); //满足条件就向下执行，不满足就阻塞
//        cout << "child1: " << i << endl;
//        kk++;
//        cv.notify_all();//唤醒所有等待线程
//    }
//}
//void proc2(int a) {
//    //lock_guard<mutex> g1(m);可以替换上面语句，并且不用调用ulock,在离开作用域时会自动解锁
//    //unique_lock类似于lock_guard,使用unique_lock后可以手动lock()与手动unlock();
//    unique_lock<mutex> p2(m);//结束自动会解锁
//    for (int i = 0; i < a; i++){
////        while (kk != 1) cv.wait(p2);
//        cv.wait(p2, [&](){return kk == 1;});
//        cout << "child2: " << i << endl;
//        kk = 0;
//        cv.notify_all();
//        }
//}
//int main()
//{//多线程 + 互斥量用例, 线运行主线程，在按照线程的建立顺序交替执行
//    thread th1(proc1, 10);
//    thread th2(proc2, 10);
//    th1.join();
//    th2.join();
//    cout << "finish!" << endl;
//    return 0;
//}


//deque<int> q;
//mutex mu;
//condition_variable cond;
//int c = 0;//缓冲区的产品个数
//
//void producer() {
//    int data1;
//    while (1) {//通过外层循环，能保证生成用不停止
//        if(c < 3) {//限流
//            {
//                data1 = rand();
//                unique_lock<mutex> locker(mu);//锁
//                q.push_front(data1);
//                cout << "product: " << data1 << endl;
//                cond.notify_one();  // 通知取
//                ++c;
//            }
//            Sleep(500);
//        }
//    }
//}
//
//void consumer() {
//    int data2;//data用来覆盖存放取的数据
//    while (1) {
//        {
//            unique_lock<mutex> locker(mu);
//            while(q.empty())
//                cond.wait(locker); //wati()阻塞前先会解锁,解锁后生产者才能获得锁来放产品到缓冲区；生产者notify后，将不再阻塞，且自动又获得了锁。
//            data2 = q.back();//取的第一步
//            q.pop_back();//取的第二步
//            cout << "get: " << data2<<endl;
//            --c;
//        }
//        Sleep(1500);
//    }
//}
//int main() {
//    //生产者消费者问题
//    thread t1(producer);
//    thread t2(consumer);
//    t1.join();
//    t2.join();
//    return 0;
//}