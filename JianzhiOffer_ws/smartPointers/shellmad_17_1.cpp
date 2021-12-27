// 智能指针的简易实现
// 前面，我们学会了如何使用引用计数及写时拷贝，这是理解智能指针必不可少的方法。但是，在实际写代码中，我们其实更倾向于让程序员
// 对于资源的管理没有任何感知，也就是说，最好让程序员只需要考虑资源的何时申请，对于何时释放以及资源内部如何计数
// 等问题，统统交给编译器内部自己处理
// 智能指针另外一点就是在使用上要像真正的指针一样可以支持 <取内容*>,<指针访问成员-> >等操作，
// 因此，就需要对这些运算符进行重载。

// 智能指针：
// 1. 用起来像指针
// 2. 会自己对资源进行释放

#include <iostream>

using namespace std;

class CStudent
{
public:
    CStudent() {}

    void test()
    {
        cout << "CStudent" << endl;
    }

private:
    char *m_pszBuf;
    int m_nSex;
};

class CRefCount
{
private:
    /* data */
public:
    CRefCount(/* args */);
    ~CRefCount();
};

// 创建一个类，利用该类的构造和析构（进出作用域自动被编译器调用）的机制
// 来解决资源自动释放的问题

// 智能指针雏形 需要管理资源
class CSmartPtr
{

public:
    // 传进来的一定要是一个堆对象
    CSmartPtr(CStudent *pObj)
    {
        m_pObj = pObj;
    }
    ~CSmartPtr()
    {
        if (m_pObj != nullptr)
        {
            delete m_pObj;
        }
    }

    //禁止使用=号，当用=号时，让编译器编译不过
    // CSmartPtr &operator=(CSmartPtr &) = delete; // =delete表示禁止使用该函数，否则编译时报错
    CSmartPtr &operator=(CSmartPtr &sp)
    {
        if (m_pObj != nullptr)
        {
            delete m_pObj;
        }
        m_pObj = sp.m_pObj;  // 给当前的重新赋值
        sp.m_pObj = nullptr; //把原来的销毁掉？但是好像没有回收原来的sp的资源吧

        return *this;
    }
    CSmartPtr(CSmartPtr &) = delete;

    //需要想办法让其对象用起来像是一个指针
    // 像一个指针的写法
    CStudent *operator->()
    {
        return m_pObj;
    }

    CStudent &operator*()
    {
        return *m_pObj;
    }

    //bool
    operator bool()
    {
        return m_pObj != nullptr;
    }

    //&

private:
    CStudent *m_pObj; //将资源放入智能指针类中，管理起来
};

int main(int argc, char *argv[])
{
    // 这里可以完成资源的自动释放
    CSmartPtr sp(new CStudent());
    // CSmartPtr sp2 = sp;
    CSmartPtr sp3(new CStudent());
    sp3 = sp;

    // 逐渐改进的写法：
    // 1. 不允许=号运算符重载，拷贝构造（=默认是浅拷贝，指向同一个对象，在析构时析构统一块内存空间，会报错）
    // 2. 使用拷贝移动语法，是auto_ptr 98的形式
    // 3. 结合前面的引用计数以及写时拷贝 新的智能指针的写法

    //但是，用起来不像是一个指针
    // sp->m_pObj->test();
    sp->test();
    (*sp).test();

    // CStudent *pStu = new CStudent();

    // if(pStu != nullptr)
    // {
    //     delete pStu;
    //     pStu = nullptr;
    // }

    return 0;
 }
