//mutex和lock_guard的使用

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int g_nData = 0;

// 创建临界区对象 -- 等价于锁
mutex g_mtx;

void foo()
{
    {
        // //进来上锁
        // g_mtx.lock();  //这种方式可以，但是需要配合unlock()使用

        lock_guard<mutex> lg(g_mtx);  //注意是模板的形式，可以参考shellmad_31_1.cpp中传入的锁的类

        for (int i = 0; i < 100000; i++)
        {
            g_nData++;
        }

        // //出去解锁
        // g_mtx.unlock();
    }
}

int main(int argc, char *argv[])
{
    thread t(foo);

    {
        // //进来上锁
        // g_mtx.lock();  //这种方式可以

        lock_guard<mutex> lg(g_mtx);

        for (int i = 0; i < 100000; i++)
        {
            g_nData++;
        }

        // //出去解锁
        // g_mtx.unlock();
    }

    t.join();

    cout << g_nData << endl;

    return 0;
}