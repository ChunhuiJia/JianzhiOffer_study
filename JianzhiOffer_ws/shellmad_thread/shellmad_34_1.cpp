// 互斥量重入问题
#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

//1.同一个进程是不能多次重复进入mutex
//2.recursive_mutex 是指同一个线程允许重复进入，但是注意释放问题

class CTest
{
public:
    void foo1()
    {
        m_mtx.lock();
        m_mtx.lock(); //recursive_mutex时可重复上锁
        m_mtx.lock(); //recursive_mutex时可重复上锁
        // m_mtx.lock();  // mutex重复(还未解锁就又对同一把锁上锁)上锁同一把锁时，运行时会报错
        // foo2(); // 这样也会mutex重复上锁，运行时会报错
        cout << "foo1" << endl;
        m_mtx.unlock();
        m_mtx.unlock(); //recursive_mutex解锁
        m_mtx.unlock(); //recursive_mutex解锁
    }

    void foo2()
    {
        m_mtx.lock();
        cout << "foo2" << endl;
        m_mtx.unlock();
    }

private:
    // mutex m_mtx;           //独占的互斥量，不能递归使用
    recursive_mutex m_mtx; //递归互斥量，不带超时功能
};

int main(int argc, char *argv)
{
    CTest t;
    t.foo1();
    t.foo2();

    return 0;
}