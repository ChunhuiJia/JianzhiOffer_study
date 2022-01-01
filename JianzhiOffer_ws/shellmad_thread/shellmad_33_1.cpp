//死锁
//线程（程序）在等待一个永远都不能成功的条件成立，从而进入到陷入休眠，永远不能被唤醒的状态

// 定义控制台应用程序的入口点

#include <iostream> //std::cout
#include <thread>
#include <mutex>

using namespace std;

// 锁资源1
mutex mtx1;

// 锁资源2
mutex mtx2;

/*
执行过程：
    线程A获取锁1
    线程A睡眠2s，在此期间锁1没有被释放，在第1s时，线程B获取锁2,之后线程B尝试获取锁1,
    但是由于锁1没有被线程A释放，所以线程B被阻塞在当前语句
    在第2s时，线程A尝试获取锁2,但是由于锁2还没有被线程B释放，所以线程A也被阻塞在当前位置
*/

// 线程A的函数
void taskA() //锁1是线程A获取的，锁1的释放到等待线程A执行完毕
{
    // 保证线程A先获取锁1
    lock_guard<mutex> lockA(mtx1);
    cout << "线程A获取锁1" << endl;

    //线程A睡眠2s再获取锁2,保证锁2先被线程B获取，模拟死锁问题的发生
    this_thread::sleep_for(chrono::seconds(2));

    //线程A先获取锁2
    lock_guard<mutex> lockB(mtx2); //获取锁2之前，要检查是否能获取锁2,如果不能，则进行等待
    cout << "线程A获取锁2" << endl;

    cout << "线程A释放所有锁资源，结束运行！" << endl;
}

// 线程B的函数
void taskB() //锁2是线程B获取的，锁2的释放到等待线程B执行完毕
{
    // 线程B先睡眠1s 保证线程A先获取锁1
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lockB(mtx2);
    cout << "线程B获取锁2" << endl;

    // 线程B尝试获取锁1
    lock_guard<mutex> lockA(mtx1);
    cout << "线程B获取锁1" << endl;

    cout << "线程B释放所有锁资源，结束运行！" << endl;
}

int main(int argc, char *argv[])
{
    thread t1(taskA);
    thread t2(taskB);

    // main主线程等待所有子线程执行完
    t1.join();
    t2.join();

    return 0;
}