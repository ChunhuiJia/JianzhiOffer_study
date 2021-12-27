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

class CTest
{
public:
    CTest() {}
};

template <typename T>
class CSmartPtr; //CSmartPtr在CRefCount中用到了，所以需要提前声明一下，否则编译报错

template <typename T>
class CRefCount // 这个引用计数器，专门用来对我们的对象使用的情况进行计数
{
    friend class CSmartPtr<T>;

public:
    CRefCount(T *pStu)
    {
        m_pObj = pStu;
        m_nCount = 1;
    }

    ~CRefCount()
    {
        delete m_pObj;
        m_pObj = nullptr;
    }

    void AddRef()
    {
        m_nCount++;
    }

    void Release()
    {
        if (--m_nCount == 0)
        { // 这么写就表示自己一定要是一个堆对象
            delete this;
        }
    }

private:
    T *m_pObj;
    int m_nCount;
};

//致命问题，CSmartPtr中表示的类型是固定的，是CStudent，需要添加模板
template <typename T>
class CSmartPtr
{
public:
    CSmartPtr()
    {
        m_pRef = nullptr;
    }

    CSmartPtr(T *pStu)
    {
        m_pRef = new CRefCount<T>(pStu);
    }

    ~CSmartPtr()
    {
        m_pRef->Release();
    }

    CSmartPtr(CSmartPtr &obj)
    {
        if (m_pRef != nullptr)
        {
            m_pRef->Release();
        }
        m_pRef = obj.m_pRef;
        m_pRef->AddRef();
    }

    CSmartPtr &operator=(CSmartPtr &obj)
    {
        if (m_pRef == obj.m_pRef)
        {
            return *this;
        }

        if (m_pRef != nullptr)
        {
            m_pRef->Release();
        }

        m_pRef = obj.m_pRef;
        m_pRef->AddRef();

        return *this;
    }

    void test2()
    {
        cout << "test2" << endl;
    }

    T *operator->()
    {
        return m_pRef->m_pObj;
    }

    T **operator&()
    {
        return &m_pRef->m_pObj;
    }

    T &operator*()
    {
        return *m_pRef->m_pObj;
    }

    operator T *() // ??????
    {
        return m_pRef->m_pObj;
    }

private:
    CRefCount<T> *m_pRef;
};

int main(int argc, char *argv[])
{
    CStudent *pStu = new CStudent();

    CSmartPtr<CStudent> sp1(pStu);
    CSmartPtr<CStudent> sp2(new CStudent()); // 调用拷贝构造，相当于初始化吧

    // sp2 = sp1; // 调用运算符重载

    CSmartPtr<CTest> sp3(new CTest);
    return 0;
}
