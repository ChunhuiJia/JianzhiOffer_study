// 写时拷贝（COW copy on write), 在所有需要改变值的地方，重新分配内存。
// 问题：如果共享资源中的值发生了变化，那么其他使用该共享资源的值如何保持不变？
// 解决思路：使用引用计数时，当发生共享资源值改变的时候，需要对其资源进行重新的拷贝，这样改变的时拷贝的值，而不影响原有的对象中的共享资源。
// 涉及到资源的拷贝和资源计数器的加减

// 直接做一个struct数据结构，申请内存空间在struct，这个struct作为多个指针指向的一个内存空间，
// 并且这个struct有计数，记录有多少个指针指向这个struct

//这个做法能在一定程度上解决资源多次重复申请的浪费，但是仍然存在两个核心的问题
// * 如果对其中某一个类对象中的资源进行了修改，那么所有引用该资源的对象全部会被修改，这显然是错误的
// * 当前的计数器作用于Student类，在使用时候，需要强行加上引用计数类，这样服用性不好，使用不方便

#include <iostream>
#include <cstring>

using namespace std;

struct RefValue
{
    RefValue(const char *pszName);
    ~RefValue();

    void AddRef();
    void Release();

    char *m_pszName;
    int m_nCount;
};

RefValue::RefValue(const char *pszName)
{
    m_pszName = new char[256];

    strcpy(m_pszName, pszName);
    m_nCount = 1;
}

RefValue::~RefValue()
{
    if (m_pszName != nullptr)
    {
        delete m_pszName;
        m_pszName = nullptr;
    }
}

void RefValue::AddRef()
{
    m_nCount++;
}

void RefValue::Release()
{
    if (--m_nCount == 0)
    {
        delete this;
    }
}

class CStudent
{
public:
    CStudent(const char *pszName);
    CStudent(CStudent &obj);

    ~CStudent();

    CStudent &operator=(CStudent &obj);

    void release();

    void SetName(const char *pszName);

    void Show()
    {
        if (m_pValue->m_nCount > 0)
        {
            cout << hex << (int &)m_pValue->m_pszName << m_pValue->m_pszName << endl; //这里这个hex是什么意思？
        }
    }

private:
    RefValue *m_pValue;
};

void CStudent::SetName(const char *pszName)  //*******这里是实现的关键***********
{   // 写时深拷贝
    m_pValue->Release();
    m_pValue = new RefValue(pszName);
}

CStudent::CStudent(const char *pszName)
{
    m_pValue = new RefValue(pszName);
}

CStudent::CStudent(CStudent &obj)
{
    m_pValue = obj.m_pValue;
    m_pValue->AddRef();
}

CStudent::~CStudent()
{
    m_pValue->Release();
}

CStudent &CStudent::operator=(CStudent &obj)
{
    if (obj.m_pValue = m_pValue)
    {
        return *this;
    }
    m_pValue->Release();

    m_pValue = obj.m_pValue;
    m_pValue->AddRef();

    return *this;
}

void CStudent::release()
{
    m_pValue->Release();
}

int main(int argc, char *argv[])
{
    CStudent stu1("Zhang san");
    CStudent stu2("li si");
    CStudent stu3 = stu2;

    stu1.Show();
    stu2.Show();
    stu3.Show();

    stu2.SetName("li shi2");

    stu2.Show();
    stu3.Show();


    return 0;
}