// 测试通过浅拷贝的资源被两个对象拥有时，资源被一个对象释放时，另一个对象访问该资源异常的问题
//

// #include "stdafx.h"  //visual studio才用到这个文件
#include <iostream>
#include <cstring>

using namespace std;

class CStudent
{
public:
    CStudent(const char *pszName);
    CStudent(CStudent &obj);

    CStudent &operator=(CStudent &obj);

    void release();

    void Show()
    {
        cout << hex << (int &)m_pszName << m_pszName << endl; //打印出变量的地址，以及里面的内容
    }

private:
    char *m_pszName;
};

CStudent::CStudent(const char *pszName)
{
    m_pszName = new char[256];

    strcpy(m_pszName, pszName); // 深拷贝
}

CStudent::CStudent(CStudent &obj)
{ //这里没有申请内存
    // 这里是浅拷贝
    m_pszName = obj.m_pszName;

    //strcpy(m_pszName, obj.m_pszName);
}

CStudent &CStudent::operator=(CStudent &obj)
{
    // 浅拷贝
    m_pszName = obj.m_pszName;

    return *this;
}

void CStudent::release()
{
    if (m_pszName != nullptr)
    {
        delete m_pszName;
        m_pszName = nullptr;
    }
}

int main(int argc, char* agrv[])
{
    CStudent stu1("Zhang san");

    CStudent stu2("li si");

    CStudent stu3 = stu2;


    stu1.Show();
    stu2.Show();
    stu3.Show();

    stu2.release();

    stu3.Show();
    return 0;
}