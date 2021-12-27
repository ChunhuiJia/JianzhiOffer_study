// 一旦其中一个对象释放了资源，那么所有的其他对象的资源也被释放了
// 解决方法：增加一个变量，记录 **资源使用的次数**
// 但是这个计数器和类绑的比较死，如果有一个新的类使用这个计数器，用起来不方便
#include <iostream>
#include <cstring>

using namespace std;

class CStudent
{
public:
    CStudent(const char *pszName);
    CStudent(CStudent &obj);

    ~CStudent();

    CStudent &operator=(CStudent &obj);

    void release();

    void Show()
    {
        if (*m_pCount > 0)
        {
            cout << hex << (int &)m_pszName << m_pszName << endl; //这里这个hex是什么意思？
        }
    }

private:
    char *m_pszName;
    int *m_pCount; //资源计数器，当资源计数器减为0时，那么表示该资源可以被释放，从而避免资源重复被释放的问题。
};

CStudent::CStudent(const char *pszName)
{
    m_pszName = new char[256];
    m_pCount = new int; //创建资源的时候也创建资源计数器
    strcpy(m_pszName, pszName);

    *m_pCount = 1;
}

CStudent::CStudent(CStudent &obj)
{
    // 这是浅拷贝
    m_pszName = obj.m_pszName;

    m_pCount = obj.m_pCount; //同时使用该资源的时候都是使用的同一个计数器
    (*m_pCount)++;           //对该资源的计数器进行操作，所以计数器只能是指针类型的
}

CStudent::~CStudent()
{
    release();
}

CStudent &CStudent::operator=(CStudent &obj)
{
    int a = 10;
    //这里的作用是把另一个对象的资源覆盖原来的资源，但是还是通过浅拷贝的方式，如果原来的资源没人用了，就释放原来的资源
    //如果原来的和现在的资源是一样的，就不用拷贝了
    if (obj.m_pszName == m_pszName)
    {
        return *this;
    }
    //否则就会剥离本对象对该资源的使用，把原来资源的计数器减1,发现计数器等于0,说明原来的资源没人用了，就会释放该资源
    if (--(*m_pCount) == 0) // *m_pCount减1的原因是，这个对象不用该资源了，所以该资源的使用方计数就减1
    {                       // 释放原来的资源
        delete m_pszName;
        m_pszName = nullptr;
        delete m_pCount;
    }
    m_pszName = obj.m_pszName; //重新赋值新的资源（浅拷贝）
    m_pCount = obj.m_pCount;
    (*m_pCount)++;

    return *this;
}

void CStudent::release()
{ //释放时就会判别如果计数器没减为0就不释放该资源
    if (m_pszName != nullptr && --*m_pCount == 0)  //*m_pCount会减1
    {
        //通过计数器来避免资源的重复释放的问题
        delete m_pszName;
        m_pszName = nullptr;

        delete m_pCount;
    }
}

int main(int argc, char *argv[])
{
    CStudent stu1("zhang san");
    CStudent stu2("li si");
    CStudent stu3 = stu2;

    stu1.Show();
    stu2.Show();
    stu3.Show();

    stu2.release();
    stu3.release();

    stu3.Show();

    return 0;
}