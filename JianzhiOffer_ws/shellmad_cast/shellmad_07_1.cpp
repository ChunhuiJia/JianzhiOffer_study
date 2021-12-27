//在发生隐式转换的时候，加上这个 作为代码的强调
#include <iostream>
#include <cstring>

class CInt
{
public:
    operator int() // 类里面可以提供一种转换运算符的方式，让外界把它当为一种类型来使用
    {
        return m_nInt;
    }

    int m_nInt;
};
//test1
void test1()
{
    int n = 5;
    float f = 10.2f;

    //本质上，发生了隐式转换,但是可能会对程序员产生疑惑
    f = n; //隐式数据类型转换，把n从int隐式转换为float

    //static_cast，明确了隐式转换，作用等同于隐式转换
    f = static_cast<float>(n);

    //低风险的转换：
    //整型与浮点型
    float db1 = 10.3;
    n = static_cast<int>(db1);

    //字符与整型
    char ch = 'a';
    n = static_cast<int>(ch);

    //void*指针的转换
    void *p = nullptr;
    int *pN = static_cast<int *>(p);

    //转换运算符的方式
    CInt nObj;
    int kk = nObj;
    int k = static_cast<int>(nObj);
}

//test2 高风险的转换
void test2()
{
    int kk;
    char *p;

    //整型与指针类型转换
    // p = kk;  //会报错
    // char *k = static_cast<char *>(kk);  //会报错
}

//基类与派生类之间的转换
//test3
class CFather
{
public:
    CFather()
    {
        m_nTest = 3;
    }

    virtual void foo()
    {
        std::cout << "CFather()::void foo()" << std::endl;
    }

    int m_nTest;
};

class CSon : public CFather
{
    virtual void foo()
    {
        std::cout << "CSon::void foo()" << std::endl;
    }
};

void test3()
{
    CFather *pFather = nullptr;
    CSon *pSon = nullptr;

    //父类转子类（不安全），因为子类的比父类的内容多，很可能访问到不该访问到的地方
    // pSon = pFather;                      //转换通过不了编译
    pSon = static_cast<CSon *>(pFather); //能够通过编译，但是不安全，没有提供运行时的检测

    //子类转父类（安全）
    pFather = pSon;                         // 能通过编译，且安全
    pFather = static_cast<CFather *>(pSon); // 能通过编译，且安全
}

int main(int argc, char *argv[])
{
    test1();

    test2();

    test3();
}