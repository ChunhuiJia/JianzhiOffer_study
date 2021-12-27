// unique_ptr学习

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void foo_construct()
{
    //这样构造是可以的
    unique_ptr<int> p(new int(3));

    //空构造
    unique_ptr<int> p4;

    //下面三种写法会报错，这三个用法都给禁止使用了
    // unique_ptr<int> p2 = p;  //需要拷贝构造
    // unique_ptr<int> p3(p);   //需要拷贝构造
    // p4 = p;        //需要=运算符重载
}

// reset的用法和auto_ptr是一致的
void foo_reset()
{
    //释放
    int *pNew = new int(3);
    int *p = new int(5);
    {
        unique_ptr<int> uptr(pNew);
        uptr.reset(p); //pNew被释放掉(到底是置空还是释放？？)，该智能指针重新指向p
    }
}

//release与reset一样，也不会释放原来的内部指针，只是简单的将自身置空
void foo_release()
{
    //释放
    int *pNew = new int(3);
    int *p = nullptr;
    {
        unique_ptr<int> uptr(pNew);
        p = uptr.release();
    }
}

//但是多了个move的用法
// 因为unique_ptr不能将自身对象内部指针直接赋值给其他unique_ptr，所以这里可以使用std::move()函数，
// 让unique_ptr交出其内部指针的所有权，而自身置空，内部指针不会释放。
void foo_move()
{
    int *p = new int(3);

    std::unique_ptr<int> uptr(p);
    std::unique_ptr<int> uptr2 = std::move(uptr); //uptr交出其内部指针，且销毁uptr，uptr2接手p
    int a = 10;
}

void foo_ary()
{
    std::vector<std::unique_ptr<int>> Ary;
    std::unique_ptr<int> p(new int(3));
    Ary.push_back(std::move(p));

    printf("%d\r\n", *p);
}

int main(int argc, char *argv[])
{
    foo_construct();
    foo_reset();
    foo_release();
    foo_move();
    foo_ary();
    return 0;
}