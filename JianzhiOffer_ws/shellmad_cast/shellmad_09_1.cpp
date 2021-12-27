// reinterpret_cast

#include <iostream>
#include <cstring>

using namespace std;

class CFather
{
};

class CSon : public CFather
{
};

//test1()
void test1()
{
    //显示强转
    int n = 1;

    //用于各种高危险的转换方式
    //这两个转换方式是等价的
    int *p = (int *)n;
    int *rein_p = reinterpret_cast<int *>(n);

    //各种类型的指针转换
    char *pCh = reinterpret_cast<char *>(p);

    //父类，子类指针的转换
    CSon *pSon;
    CFather *pFather = nullptr;
    pSon = reinterpret_cast<CSon *>(pFather);  //不存在检查
}
int main()
{
    test1();

    return 0;
}