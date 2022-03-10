## C++学习参考资料

1.[腾讯云：C++教程](https://cloud.tencent.com/developer/doc/1024) , 很多C++的标准库函数，应该是英文翻译过来的，还不错

## 1. C++传递数组给函数

  C++传递数组给函数，数组类型自动转换为指针类型，因而传的实际是地址，在函数内修改这个数组，在函数调用后这个数组也就被改变了。参考链接：[C++ 传递数组给函数](https://www.runoob.com/cplusplus/cpp-passing-arrays-to-functions.html)

传给函数的***数组名***和***&数组名***不一样

**以int a[5]为例，数组首元素的地址是数组名a，整个数组元素的地址是&a** . [参考链接：数组名和数组名取地址](https://www.cnblogs.com/lqn1992/p/4659489.html)]



![image-20211210093057918](Cpp_知识点.assets/image-20211210093057918.png)

## 2.求数组的长度

int numbers[] = {2, 3, 4, 1, 3};

int length = **sizeof(numbers)/sizeof(int);**

sizeof()求的结果是字节长度

## 3.对于传入的参数是指针的要判断是不是空指针

if(ptr==nullptr)

## 4.strcpy()

使用C++字符数组与使用string对象的不同的一个方式是除了在定义时初始化它，其它时候不能直接给字符数组赋值，要为字符数组赋值，必须要使用strcpy的函数，将一个字符串的内容复制到另外一个字符串中。参考链接：[http://c.biancheng.net/view/1349.html]

## 5.二维数组

二维数组    **类型说明符 数组名[行标] [列标]**;

我发现未初始化的数组好像有点问题，它里面的内容可能和别的数组相同，指针地址也相同，所以**二维数组一定要初始化**。

初始化的几个方法：

``` cpp
// 定义及初始化
int a[2][3] = {{1,2,3},{4,5,6}};
int a[2][3] = {1,2,3,4,5,6};
int b[3][4] = {{1},{4,3},{2,1,2}};  // 只为数组b中的部分元素进行了赋值，对于没有赋值的元素，系统会自动赋值为0

// 赋值
a[1][1]=5;
int k = a[1][2];   // 访问的是元素
auto kk = a[1]  // 访问的是第1行元素（得到的也就是一维数组）
```

[参考链接：C++二维数组的定义和用法](https://www.itheima.com/news/20200508/155103.html)

## 6.(int *) name

将name转换为指向int型变量的指针

## 7.i++和++i

i++, 先引用后增加，先在i所在的表达式中使用i的当前值，后让i加1

++i，先增加后引用，让i先加1，然后在i所在的表达式中使用i的新值

[参考链接：【c++】i++和++i 详解](https://blog.csdn.net/u012679707/article/details/80313425)

for循环里的i++和++i的效果一样，例如for(i=0;i<10;i++)，我认为这是三个执行语句，第三句为i++，所以无论先引用后增加或先增加后引用，在这一句话的效果是一样的。

## 8.strcmp(str,expected)比较字符串是否相同

## 9.C++ STL stack

std::stack 是先进后出的容器

![image-20211211224204074](Cpp_知识点.assets/image-20211211224204074.png)

[参考链接：C++ stack(STL stack)用法详解](http://c.biancheng.net/view/478.html)

## 10.printf()

printf()函数在c++里的<cstdio>，在c语言中是在<stdio.h>

## 11.二叉搜索树

二叉搜索树，左子节点<=根(父)节点<=右子节点。

## 12.C++函数模板

```cpp
template <class T> void Swap(T &x,T &y)   // c++11中class可以用typename，也就是可以写成template <typename T>
{
	T tmp = x;
	x = y;
	y = tmp;
}
```

我理解template <class T> 这句话就相当于是定义了一种数据类型T，当某个用到这个数据类型的函数或类调用时，就替换该数据类型为具体的数据类型，进行实例化。

## 13.递归的优缺点

优点：代码简洁

缺点：

* 递归是函数调用本身，而函数调用是有时间和空间的消耗的
* 每一次函数调用在内存栈中分配空间，而每个进程的栈的容量是有限的，当递归调用的层级太多时，就会超出栈的容量，从而导致调用栈溢出。

## 14.快速排序

选取序列中的一个数作为pivot(中心点)，把小于pivot的数都放到pivot左边作为数组left[]，把大于pivot的数都放到右边right[]，分别对left[]和right[]通过递归的方式执行上述操作。

[视频讲解：快速排序算法，推荐](https://www.bilibili.com/video/BV1at411T75o?from=search&seid=6101345618712787987&spm_id_from=333.337.0.0)

## 15.push()方法和push_back()方法

push()是queue和stack的方法

push_back()是vector的方法

## 16.内存分区

内存分为四个区域：栈区（堆栈），堆区，全局静态区，只读区（常量区和代码区）。

![image-20211214190601861](Cpp_知识点.assets/image-20211214190601861.png)

1、栈区

 	1) 存放的数据：局部变量，形参，被调用函数的地址（这个可以不用管）等等。
 	2) 特点：
 	 * 读取速度快，存储和释放的思路是按照数据结构中的栈进行的，存数据就是压栈，释放就是弹栈。
 	 * 空间小，基本类型的数据占用空间的大小不会随着值的改变而改变，而且占用空间小。

2、堆区

1. 存放的数据：new出来的数据
2. 特点：
   * 读取速度慢
   * 空间大，引用类型的数据大小是动态的，会随着数据的增加而改变大小

3、全局静态区

1. 存放的数据：全局变量和静态变量
2. 特点：
   * 在程序运行过程中，数据会一直在内存中

4、只读区

1. 存放的数据：常量区存放常量，代码区存放程序的代码（程序运行时是需要载入到内存中运行的）
2. 特点
   * 此区域的数据在程序运行过程中肯定不能改变

## 17.基本类型和引用类型在内存上存储的区别

**基本数据类型的特点**：<u>直接存储在栈(stack)中的数据</u>。

**引用数据类型的特点**：<u>存储的是该对象在栈中引用，真实的数据存放在堆内存里</u>。也可以理解引用类似链接。

引用数据类型在栈中存储了指针，该指针指向堆中该实体的起始地址。当解释器讯号引用值时，会首先检索其在栈中的地址，取得地址后从堆中获得实体。

现在只看栈区和堆区，不管其它区域，也假定只是局部变量。

![image-20211215145101750](Cpp_知识点.assets/image-20211215145101750.png)

以上函数test()在调用时，

1. 定义局部变量age，由于age是局部变量，所以在栈中申请内存空间，起名为age，又由于**给age赋的值250是基本类型，所以值直接存储在栈中**。
2. 定义局部变量arr，由于arr是局部变量，所以在栈中申请空间，但是arr的内存中存储的是什么？由于**给arr赋的值不是基本类型**，而是**引用类型(new出来的)**，所以，先在堆中申请空间存放数据12,23,24。再把堆区的地址赋给arr。

## 18.深拷贝和浅拷贝

[参考链接：面试题：深拷贝和浅拷贝(超级详细，有内存图)](https://blog.csdn.net/jiang7701037/article/details/98738487?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.essearch_pc_relevant&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.essearch_pc_relevant)

所谓拷贝，就是赋值。把一个变量赋给另外一个变量，就是把变量的内容进行拷贝。把一个对象的值赋给另外一个对象，就是把一个对象拷贝一份。

**深拷贝和浅拷贝是只针对**Object（对象）和Array（数组）这样的**引用数据类型**的。

浅拷贝只复制指向某个对象的指针，而不复制对象本身，新旧对象还是共享同一块内存，修改新对象会改动原对象。

但深拷贝会另外创造一个一模一样的对象，新对象跟旧对象不共享内存，修改新对象不会改动到原对象。

1. 基本类型没有问题

   基本类型赋值时，赋的是数据（所以，不存在深拷贝和浅拷贝的问题）

2. 引用类型有问题

   引用类型赋值时，赋的值地址（就是引用类型变量在内存中保存的内容）

   **浅拷贝**，例如这个示例，只是把arr1的地址拷贝一份给了arr2，并没有把arr1的数据拷贝，所以，**拷贝的深度不够**。修改arr2也会修改arr1。

   ```cpp
   var arr1 = new Array(12,23,34)
   Var arr2 = arr1;//这就是一个最简单的浅拷贝
   ```

**浅拷贝：对于基本类型进行普通拷贝（新分配内存存储），对于引用类型只拷贝地址**。浅拷贝只是拷贝了一层，深拷贝是拷贝了最底层的基本类型数据。

![image-20211215152814560](Cpp_知识点.assets/image-20211215152814560.png)

**深拷贝：对于基本类型进行普通拷贝（分配内存赋值），对于引用类型，通过指针找到对应的数据，如果是基本类型则进行普通拷贝，如果还是引用类型，还向下一层找，直到找到基本类型，进行普通拷贝。**这样的话一般就是通过递归的方式进行赋值。

![image-20211215152846930](Cpp_知识点.assets/image-20211215152846930.png)

## 19.c++强制转换

## 20.多态

[参考链接：MOOC 郭炜](https://www.icourse163.org/learn/PKU-1002029030?tid=1465718464#/learn/content?type=detail&id=1245449007&sm=1)

多态的表现形式一

* 派生类的指针可以**赋给基类指针**。
* **通过基类指针调用**基类和派生类中的同名**虚函数**时：

​	(1) 若该指针指向一个基类的对象，那么被调用是基类的虚函数;

​	(2) 若该指针指向一个派生类的对象，那么被调用的是派生类的虚函数

这种机制就叫做 **“多态”**



## 21.智能指针

[有一套很好的课程(推荐学习)：shellmad-14_C++新特性 智能指针与RAII(连着好几集)](https://www.bilibili.com/video/BV1GK4y1s7qR?spm_id_from=333.999.0.0)

用到的头文件 `#include <memory>` [参考链接：c++ memory 头文件详细介绍](https://blog.csdn.net/CHYabc123456hh/article/details/109350925)

**.get()返回对象的地址**。

### unique_ptr

为什么会有unique_ptr？

动态内存忘记delete，导致内存泄漏。比如：

```cpp
p = new();
if(...)
{
	return;
}
delete p;
```

因此我们需要一种方式来解决这个问题，不管我们怎么折腾，能够避免内存不释放的问题。

于是我们引入了auto_ptr，但目前auto_ptr有很多缺点，目前在c++11以上已经停用了。

auto_ptr的进阶版unique_ptr就被引入进来。

unique_ptr的特点：

unique_ptr继承了auto_ptr的部分优点，对缺点进行改进。

unique_ptr是一个独享所有权的智能指针，它提供了严格意义上的所有权，包括：

特点1：拥有它指向的对象

特点2：无法进行复制构造，无法进行复制赋值操作。即无法使两个unique_ptr指向同一个对象。但是可以进行**移动构造和移动赋值**操作

特点3：保存指向某个对象的指针，当它本身被删除释放的时候，会**使用给定的删除器释放它指向的对象**

官方文档：

std::unique_ptr是**通过指针占有并管理另一对象**，并**在unique_ptr离开作用域时释放该对象的智能指针**。

在下列两者之一发生时用关联的删除器释放对象：

**销毁了管理**的**unique_ptr对象**

通过`operator=`或`reset()` 赋值另一指针给管理的unique_ptr对象。

通过调用get_delete()(ptr), 用潜在为用户提供的删除器释放对象。默认删除器用delete运算符，它销毁对象并分解分配内存。

unique_ptr亦可以不占对象，该情况下称它为空(empty)。

std::unique_ptr有两个版本：

(1) 管理个对象(例如以new 分配)

(2) 管理动态分配的对象数组 (例如以 new[] 分配)

类满足可移动构造和可移动赋值的要求，但不满足可复制构造或可复制赋值的要求。

总结起来就是：=或者reset都会转移unique_ptr的控制权，并调用析够函数。

```cpp
#include <iostream>
#include <memory>

class Mars
{
    public:
    ~Mars()
    {
        std::cout << this << "~Mars" << std::endl;
    }
    void prin()
    {
        std::cout << this << ",I am Mars" << std::endl;
    }
};

int main()
{
    {
        Mars* mars = new Mars;
        std::unique_ptr<Mars> pMars(mars);
        std::cout << "pMars->prin:        ";
        pMars->prin();
        std::cout << "pMars.get()->prin:   ";
        pMars.get()->prin();
        std::cout << "(*pMars).prin:     ";
        (*pMars).prin();

        std::cout << "pMars:" << pMars.get() << std::endl;
        pMars.reset(new Mars);
        std::cout << "pMars.reset.prin:     ";
        pMars->prin();

        std::unique_ptr<Mars> pMars2;
        pMars2 = std::move(pMars);
        std::cout << "pMars2.move.prin:       ";
        std::cout << "pMars2:" << pMars2.get() << std::endl;
        pMars2->prin();
    }

    return 0;
}
```

> .get()函数

[参考链接: c++——智能指针学习（unique_ptr）](https://blog.csdn.net/weixin_30892763/article/details/97764534)

[参考链接：官方文档std::unique_ptr](https://zh.cppreference.com/w/cpp/memory/unique_ptr)

## 22.子类重写方法时可以不加virtual，推荐加override用于编译器检查

不推荐在子类重写方法时加 virtual 。这并不能让读者意识到这是重写的方法，也无益于编译器的检查。 要指明这是重写的方法，应该用 override [参考链接：](https://bbs.csdn.net/topics/391901728)

## 23.strlen()和sizeof()的区别

[参考链接：C/C++中strlen的用法](https://blog.csdn.net/lht_521/article/details/105928323)

strlen() 是string+length缩写，含义是字符串有多少个字符

> strlen所做的仅仅是一个计数器的工作，它从内存的某个位置(可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域)开始扫描，直到碰到第一个字符串结束符"\0"为止，然后返回计数器值。

sizeof() 返回的是变量声明后所占的内存数，而不是实际长度

## 24.C++中Struct与Class的区别与比较

C++中Struct和Class很像，也有构造函数，成员函数之类的，什么publich,private的，区别还是有一些，比如struct的默认成员变量是public的，而Class默认成员变量是private的。

[参考链接：C++中Struct与Class的区别与比较](https://blog.csdn.net/weixin_39640298/article/details/84349171)

## 25.map

map是STL的一个关联容器，它提供了一对一的hash。

* 第一个可以称为关键字(key)，**每个关键字只能在map中出现一次**
* 第二个可以称为该关键字的值(value)

map以模板(泛型)方式实现，可以存储任意类型的数据，包括使用者自定义的数据类型。map主要用于资料一对一映射(one-to-one)的情况，**map内部的实现自建一颗红黑树**，这棵树具有对数据**自动排序**的功能。在map内部所有的数据都是有序的，后边我们会见识到有序的好处。比如一个班级中，每个学生的学号跟他的姓名就存在着一对一映射的关系。

![image-20211226121036194](Cpp_知识点.assets/image-20211226121036194.png)

[参考链接：C++ map用法总结](https://blog.csdn.net/weixin_42513339/article/details/89179655?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7Eessearch%7Evector-1.fixedcolumn&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7Eessearch%7Evector-1.fixedcolumn)

## 26.=delete和=default

=delete,表示禁止使用编译器默认生成的函数，禁止使用该函数

=default, 表示无论程序员是否重载了该同名函数，都要求编译器生成一个默认函数，不使用=default，若程序员重载了该函数，则不会生成该函数的默认函数。

[参考链接：C++中 =defaule 和 =delete 使用](https://blog.csdn.net/lmb1612977696/article/details/80035487)

## 27.在A中加语句：friend class B

能够让其他类**B，访问A中的成员变量**.

[参考链接：C++中的friend class 用法总结](https://blog.csdn.net/weixin_38293850/article/details/80191242)

## 28.explicit关键字

explicit用来防止由构造函数定义的隐式转换

[参考链接：C++中explicit关键字的作用](https://www.cnblogs.com/winnersun/archive/2011/07/16/2108440.html)

## 29.段错误

**段错误应该就是访问了不可访问的内存，这个内存要么是不存在的，要么是受系统保护的**。

[参考链接：Segmentation Fault错误原因总结](https://blog.csdn.net/u010150046/article/details/77775114)

## 30.线程thread的使用

抽时间一定要好好学一学

[参考链接：shellmad-27_C++新特性 线程thread的使用](https://www.bilibili.com/video/BV12k4y117gA?spm_id_from=333.999.0.0)

## 31.强制类型转换

强制类型转换有一定风险的，有的转换并不一定安全，如把**整型数值转换成指针**，把**基类指针转换成派生类指针**，把**一种函数指针转换成另一种函数指针**，把**常量指针转换成非常量指针**等。

**强制类型转换符：**

C++引入了四种功能不同的强制类型转换运算符以进行强制类型转换：（通过编译器检查强制类型转换是否正确）

* **const_cast**：常用
* **static_cast**：常用
* **reinterpret_cast**：用的比较少
* **dynamic_cast**：虚函数用的比较多

**C语言强制类型转换缺点：**

主要是为了克服C语言强制类型转换的一下三个缺点。

* 没有从形式上体现转换功能和风险的不同。

​		例如，将int强制转换成double是没有风险的，而将常量指针转换成非常量指针，将基类指针转换成派生类指针都是高风险的，而且后两者带来的风险不同（即可能引起不同种类的错误），C语言的强制类型转换形式对这些不同并不加以区分。

* 将多态基类指针转换成派生类指针时不检查安全性，即无法判断转换后的指针是否确实指向一个派生类对象。
* 难以在程序中寻找到底什么地方进行了强制类型转换

强制类型转换是引发程序运行时错误的一个原因，因此在程序出错时，可能就会想到是不是有哪些强制类型转换出了问题。



### const_cast

仅用于进行去除const属性的转换，它也是四个强制类型转换运算符中唯一能够去除const属性的运算符。

***常量对象或者是基本数据类型不允许转换为非常量对象，只能通过指针和引用来修改：***



### static_cast

基本等价于隐式转换的一种类型转换运算符，可使用于需要明确隐式转换的地方。

**可以用于低风险的转换**

* 整型和浮点型
* 字符与整型
* 转换运算符
* ***空指针转换为任何目标类型的指针***

**不可以用于风险较高的转换**

* 不同类型的指针之间互相转换
* 整型和指针之间的互相转换
* 不同类型的引用之间的转换



### dynamic_cast

用于具有**虚函数的基类**与**派生类**之间的**指针或引用**的转换。

* **基类必须具备虚函数**

​		原因：dynamic_cast是**运行时类型检查**，需要运行时类型信息(RTTI)，而这个信息是存储与类的**虚函数表**关系紧密，只有一个类定义了虚函数，才会有虚函数表。

* **运行时检查，转型不成功则返回一个空指针**
* **非必要不要使用dynamic_cast，有额外的函数开销**

常见的转换方式：

* 基类指针或引用转派生类指针(**必须使用**dynamic_cast)
* 派生类指针或引用转基类指针(可以使用dynamic_cast，但是**更推荐使用static_cast**)



### reinterpret_cast

* **用于进行各种不同类型的转换**
  - 不同类型指针之间
  - 不同类型引用之间
  - 指针和能容纳指针的整型类型之间的转换
* **编译器处理，执行的是逐字节复制的操作**
* **类似于显示强制转换，后果自负**

## 32.const

```c++
const int* p;  //const放在前面代表指针指向的内容不能发生改变
*p = 123;  // 修改指针指向的内容会报错
```



```cpp
int n = 5;
int* const p = &n;  //const放在后面代表指针本身不能发生改变
p = 0x123;          //修改指针地址会报错
```

```c++
int GetNumber() const;  //决定了在该成员函数中，任意修改它所在的类的成员的操作都是不允许的，因为隐含了对this指针的const引用。
```



## 33.字符的双引号和单引号

字符型用单引号

```cpp
'a'
```

字符串型用双引号

```cpp
“HELLO WORLD”
```

[参考链接：C++ 单引号和双引号区别](https://blog.csdn.net/yyfaith/article/details/80225825)



## 34.lambda表达式/匿名函数

Lambda表达式是一个源自阿隆佐×邱奇(Alonzo Church) -- 艾伦×图灵(Alan Turing)的老师---的术语。

邱奇创立了lambda演算，后来被证明和图灵机是等价的。

Lambda表达式是c++11中最重要的新特性之一，而Lambda表达式，实际上就是提供了一个类似匿名函数的特性，而匿名函数则是在需要一个函数，但是又不想费力去命名一个函数的情况下去使用的。这样的场景其实有很多很多，所以匿名函数几乎是现代编程语言的标配。

**(1) Lambda表达式基础**

Lambda表达式的基本语法如下：

```cpp
[捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型{
	// 函数体
}
[caputrue](params)opt->ret{body;};
```

* Lambda 表达式以一对**中括号**开始。
* 跟函数定义一样，我们有**参数列表**
* 跟正常的函数定义一样，我们会**有一个函数体，里面会有return语句**
* Lambda表达式**一般不需要说明返回值(相当于auto)**；**有特殊情况需要说明时，则应使用箭头语法的方式**
* 每个Lambda表达式都有一个全局唯一的类型，要精确捕捉lambda表达式到一个变量中，只能通过auto声明的方式

## 35.线程与同步

对标准库的扩充：语言级线程支持

* std::thread
* std::mutex/std::unique_lock
* std::future/std::packaged_task
* std::condition_variable

### 线程的概念及使用

线程：进程内一个相对独立的、可调度的执行单元，是系统独立调度和分派CPU的基本单元指运行中的程序的调度单位。

​	(1) 线程内核对象。操作系统用它来管理线程，存放线程统计信息。

​	(2) 线程堆栈，用于维护线程在执行代码时，需要的所有函数参数和局部变量。



时间片：某一间A教室（1班，2班），把时间划分，划分成上午（1班）和下午（2班）。

​				cpu（听歌代码，游戏代码），把cpu时间划分，划分给片段20ms，由线程1（听歌）和线程2（游戏代码）交替运行。 

![image-20211230194630528](Cpp_知识点.assets/image-20211230194630528.png)

### join()函数

* **谁调用的这个函数？**调用了这个函数的线程对象，一定要等这个线程对象的方法（在构造时传入的方法）执行完毕后（或者理解为这个线程的活干完了！），这个join()函数才能得到返回。
* **在什么线程环境下调用了这个函数？**上面说了必须要等线程方法执行完毕后才能返回，那必然是阻塞调用线程的，也就是说如果一个线程对象在一个线程环境调用了这个函数，那么这个线程环境就会被阻塞，直到这个线程对象在构造时传入的方法执行完毕后，才能继续往下走，另外如果线程对象在调用join()函数之前，就已经完成了自己的事情（在构造时传入的方法执行完毕），那么这个函数不会阻塞线程环境，线程环境正常执行。

[参考链接：C++ std::thread join()的理解](https://www.cnblogs.com/adorkable/p/12722209.html)

举例：

```cpp
int main()
{
    cout << "主线程开始运行\n";
    std::thread d2(download2);
    download1();
    d2.join();
    process();
}
```

* **谁调用的这个函数？**d2这个线程对象调用了join()函数，因此必须d2的下载任务结束了，d2.join()函数才能得到返回。
* **d2在哪个线程环境下调用了join()函数？**d2是在主线程的环境下调用了join()函数，因此主线程要等待d2的线程工作做完，否则主线程将一直处于block状态；这里不要搞混的是d2真正做的任务（下载）是在另一个线程做的，但是d2调用join()函数的动作是在主线程环境下做的。



### 线程同步的方法

* 原子操作：

​	是指线程在访问资源时能够确保所有其他线程都不在同一时间内访问相同的资源



* 临界区

​	临界区是指一个小代码段，在代码能够执行前，它必须独占对某些共享资源的访问权，在线程退出临界区之前，系统将不给想要访问相同资源的其他任何线程进行调度。



### 死锁

线程（程序）在等待一个永远都不能成功的条件成立，从而进入到陷入休眠，永远不能被唤醒的状态。

**举例1：两个线程互相等待**

* 原理：

```
线程1：
	获取锁1, 等待锁2
线程2：
	获取锁2, 等待锁1
```

### 互斥量

C++11 中提供以下4种语义的互斥量(mutex)：

* std::mutex：独占的互斥量，不能递归使用
* std::recursive_mutex：递归互斥量，不带超时功能

* std::timed_mutex：带超时的独占互斥量，不能递归使用
* std::recursive_timed_mutex：带超时的递归互斥量

#### 递归锁std::recursive_mutex

使用建议：

 	1. 递归锁的递归是有计数器，超过了计数器最大值会失败，抛异常
 	2. 比非递归锁效率低
 	3. 递归进入占用递归锁，使得代码逻辑不清晰，引发其他问题。

​	因此，建议酌情使用。

#### 超时互斥锁std::timed_mutex

* 可以为锁的等待设置一个超时值，一旦超过可以做其他事情
* timed_mutex比mutex主要是多了
  * try_lock_for() 尝试锁定互斥，若互斥在指定的时限时期中不可用则返回
  * try_lock_until() 尝试锁定互斥，直至抵达指定时间点互斥不可用则返回

## 36.explicit构造函数关键字

explicit：明确的，清楚的，不隐晦的，不含糊的。

C++中的**explicit关键字**只能用于**修饰只有一个参数的类构造函数**，它的作用是表明该构造函数是显式的，而非隐式的，跟它相对应的另一个关键字是implicit，意思是隐藏的，类构造函数默认情况下即声明为implicit（隐式）

隐含的意思是不会明确地告诉它要做什么，所以有点像自动，通过上下文知道意思

C++允许编译器对代码执行一次隐式转换。

**构造函数不加explicit关键字时：**

```cpp
#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		: m_Name(name),m_Age(-1){}
	
	Entity(int age)
		: m_Name("Unknown"),m_Age(age){}
};

void PrintEntity(const Entity& entity)
{
    // Printing
}

int main()
{
	Entity a1("Cherno");//ok
	Entity b1(22);//ok
    Entity a2 = Entity("Cherno");//ok
	Entity b2 = Entity(22);//ok
    Entity a3 = "Cherno";  //ok 做了一次隐式转换，相当于Entity a2 = Entity("Cherno");
    Entity b3 = 22;   //ok 做了一次隐式转换，相当于Entity b2 = Entity(22);
    PrintEntity(22);  //ok 做了一次隐式转换，相当于PrintEntity(Entity(22));
    PrintEntity("Cherno"); //报错，需要做两次隐式转换，1.char[]类型的"Cherno"转换成std::string,2.在转换为Entity类型，由于C++只能做一次隐式转换所以报错
    PrintEntity(std::string("Cherno")); //ok 做了一次隐式转换，相当于PrintEntity(Entity(std::string("Cherno"))); 
    PrintEntity(Entity("Cherno")); //ok 做了一次隐式转换，相当于PrintEntity(Entity(std::string("Cherno"))); 
	std::cin.get();
}
```

**构造函数加explicit关键字时：**

```cpp
#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(const std::string& name)
		: m_Name(name),m_Age(-1){}
	
	explicit Entity(int age)
		: m_Name("Unknown"),m_Age(age){}
};

void PrintEntity(const Entity& entity)
{
    // Printing
}

int main()
{
	Entity a1("Cherno");//ok
	Entity b1(22);//ok
    Entity a2 = Entity("Cherno");  //ok
	Entity b2 = Entity(22);//ok
    Entity a3 = "Cherno";  //会报错，因为其Entity构造函数用explicit关键字禁止了隐式转换
    Entity b3 = 22;   //会报错，因为Entity其构造函数用explicit关键字禁止了隐式转换
    PrintEntity(22);  //会报错，因为Entity其构造函数用explicit关键字禁止了隐式转换
    PrintEntity("Cherno"); //报错，需要做两次隐式转换，1.char[]类型的"Cherno"转换成std::string,2.在转换为Entity类型，由于C++只能做一次隐式转换所以报错
    PrintEntity(std::string("Cherno")); //会报错，因为其构造函数用explicit关键字禁止了隐式转换
    PrintEntity(Entity("Cherno")); //ok 做了一次std::string隐式转换，Entity没有做隐式转换所以不违反Entity 的explicit的关键字
	std::cin.get();
}
```

##  37. `virtual xxx() =0`纯虚方法

**纯虚函数** 必须被子类实现，否则会编译报错。

[参考链接：c++ virtual =0 纯虚方法](https://blog.csdn.net/qq_15267341/article/details/79359193)

## 38.memset()方法

```c++
void *memset(void *str, int c, size_t n)
```

> 函数功能：把字符c复制n份**替换**到str所指向的**字符串的前n个字符**。
>
> 参数`str` -- 指向要填充的内存块
>
> 参数`c` -- 要被设置的值，该值以int形式传递，但是函数在添加内存块时是使用该值的无符号字符形式
>
> 参数`n` -- 要被设置为该之的字符数

例子:

```cpp
#include <stdio.h>
#include <string.h>
 
int main ()
{
   char str[50];
 
   strcpy(str,"This is string.h library function");
   puts(str);
 
   memset(str,'$',7);
   puts(str);
   
   return(0);
}
```

输出结果：

> ```
> This is string.h library function
> $$$$$$$ string.h library function
> ```

参考链接：[C 库函数 - memset()](https://www.runoob.com/cprogramming/c-function-memset.html)

## 39.零拷贝

[参考文献：原来 8 张图，就可以搞懂「零拷贝」了](https://zhuanlan.zhihu.com/p/258513662)

磁盘可以说是计算机系统最慢的硬件之一，读写速度相差内存 10 倍以上，所以针对优化磁盘的技术非常的多，比如零拷贝、直接 I/O、异步 I/O 等等，这些优化的目的就是为了提高系统的吞吐量，另外操作系统内核中的磁盘高速缓存区，可以有效的减少磁盘的访问次数。

在前面我们知道了，传统的文件传输方式会历经 4 次数据拷贝，而且这里面，「从内核的读缓冲区拷贝到用户的缓冲区里，再从用户的缓冲区里拷贝到 socket 的缓冲区里」，这个过程是没有必要的。

因为文件传输的应用场景中，在用户空间我们并不会对数据「再加工」，所以数据实际上可以不用搬运到用户空间，因此**用户的缓冲区是没有必要存在的**。

![img](Cpp_知识点.assets/v2-dc405f1eb057217aee8820b6d3e340fd_720w.jpg)

这就是所谓的**零拷贝（\*Zero-copy\*）技术，因为我们没有在内存层面去拷贝数据，也就是说全程没有通过 CPU 来搬运数据，所有的数据都是通过 DMA 来进行传输的。**

## 40.Linux用户态和内核态

[参考链接：用户态和内核态](https://www.cnblogs.com/maxigang/p/9041080.html)

**内核态**：cpu可以访问内存的所有数据，包括外围设备，例如硬盘，网卡，cpu也可以将自己从一个程序切换到另一个程序。

**用户态**：只能受限的访问内存，且不允许访问外围设备，占用cpu的能力被剥夺，cpu资源可以被其他程序获取。

## 41.内核缓冲区和用户缓冲区

[参考链接：底层原理，用户进程缓冲区和内核缓冲区](https://www.cnblogs.com/yc3110/p/10440613.html)

**用户进程缓存区**：用户进程通过系统调用访问系统资源的时候，需要切换到内核态，而这对应一些特殊的堆栈和内存环境，必须在系统调用前建立好。而在系统调用结束后，cpu会从核心模式切回到用户模式，而堆栈又必须恢复成用户进程的上下文。

**内核缓冲区**：当一个用户进程要从磁盘读取数据时，内核一般不直接读磁盘，而是将内核缓冲区中的数据复制到进程缓冲区中。

我感觉是用户态情况下访问不到内核态的内存。

## 42.上下文切换

[参考链接：一文让你明白CPU上下文切换](https://zhuanlan.zhihu.com/p/52845869)

**CPU 寄存器**和**程序计数器**就是 CPU 上下文，因为它们都是 CPU 在运行任何任务前，<u>必须的依赖环境</u>。

- **CPU 寄存器**是 CPU 内置的容量小、但速度极快的内存。
- **程序计数器**则是用来存储 CPU 正在执行的指令位置、或者即将执行的下一条指令位置。

> **什么是 CPU 上下文切换**：
>
> 就是先**把前一个任务的 CPU 上下文（也就是 CPU 寄存器和程序计数器）保存起来**，**然后加载新任务的上下文到这些寄存器和程序计数器**，最后再**跳转到程序计数器所指的新位置，运行新任务**。
>
> 而这些**保存下来的上下文，会存储在系统内核中**，并**在任务重新调度执行时再次加载进**来。这样就能**保证任务原来的状态不受影响**，让任务看起来还是连续运行。

**每次上下文切换**都需要**几十纳秒到数微秒的 CPU 时间**。这个时间还是相当可观的，特别是在进程上下文切换次数较多的情况下，很容易导致 CPU 将大量时间耗费在寄存器、内核栈以及虚拟内存等资源的保存和恢复上，进而大大缩短了真正运行进程的时间。这也正是导致平均负载升高的一个重要因素。

## 43.进程和线程

线程与进程最大的区别在于：**线程是调度的基本单位，而进程则是资源拥有的基本单位**。说白了，所谓内核中的任务调度，实际上的调度对象是线程；

而**进程**只是给线程**提供了虚拟内存、全局变量等资源**。

## 44.std::deque

st::deque是双端队列，可以高效的在头尾两端插入和删除元素，双端队列提供了类似向量（std::vector）的功能，且不仅可以在容器末尾，还可以在容器开头高效地插入或删除元素。但是，相比向量，**双端队列不保证内部的元素是按连续的存储空间存储的**，因此，**不允许对指针直接做偏移操作来直接访问元素**。但是**deque支持快速的随机访问。**

在内部，双端队列与向量的工作方式完全不同：向量使用单数组数据结构，在元素增加的过程中，需要偶尔的内存重分配，而双端队列中的元素被零散地保存在不同的存储块中，容器内部会保存一些必要的数据使得可以以恒定时间及一个统一的顺序接口直接访问任意元素。因此，双端队列的内部实现比向量的稍稍复杂一点，但这也使得它在一些特定环境下可以更高效地增长，特别是对于非常长的序列，内存重分配的代价是及其高昂的。
对于大量涉及在除了起始或末尾以外的其它任意位置插入或删除元素的操作，相比列表（std::list）及正向列表（std::forward_list），deque 所表现出的性能是极差的，且操作前后的迭代器、引用的一致性较低。

[参考链接：C++/C++11中std::deque的使用](https://blog.csdn.net/fengbingchun/article/details/72757856/)

使用的方法和vector类似：

```cpp
deque <int> c1;
c1.push_back(10);
int& j = c1.at(1);
int& i = c1.back();
int& ii = c1.front();
cout << "The size of the deque is initially " << c1.size() << endl;
c1.clear();

deque <int>::iterator v1_Iter;
v1_Iter = v1.begin();
deque <int>::const_reverse_iterator v1_rIter;
v1_rIter = v1.crbegin();
```

**std::deque::resize**：调整容器大小以包含`count`个元素[参考链接：std::deque::resize](https://cloud.tencent.com/developer/section/1010052)

```cpp
void resize( size_type count );    //用法1
void resize( size_type count, const value_type& value );  //用法2
//count：void resize( size_type count );  
//value：用来初始化新元素的值
```

如果当前size小于count，则1)附加默认插入的元素 2)附加拷贝值被添加(append)

举例：

```cpp
#include <iostream>
#include <deque>
int main()
{
    std::deque<int> c = {1, 2, 3};
    std::cout << "The deque holds: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(5);
    std::cout << "After resize up 5: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
}
/* 输出为：
The deque holds: 1 2 3
After resize up 5: 1 2 3 0 0
After resize down to 2: 1 2
*/
```

**std::deque::pop_front**：移除容器的第一个元素。[参考链接：std::deque::pop_front](https://cloud.tencent.com/developer/section/1010047)

**std::deque::pop_back**：移除容器的最后一个元素 [参考链接：std::deque::pop_back](https://cloud.tencent.com/developer/section/1010046)

**std::deque::push_front**：在容器头部插入元素 [参考链接：](https://blog.csdn.net/u014779536/article/details/111309384)

**std::deque::push_back**：在容器末尾插入元素

## 45.CHECK()和CHECK_GT()



## 46.lower_bound()和upper_bound()

**lower_bound( begin,end,num)**：从数组的begin位置到end-1位置二分**查找第一个大于或等于num的数字**，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。[参考链接：C++ lower_bound()函数用法详解](http://c.biancheng.net/view/7521.html)

**upper_bound( begin,end,num)**：从数组的begin位置到end-1位置二分**查找第一个大于num的数字**，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。[参考链接：C++ upper_bound()函数（精讲版）](http://c.biancheng.net/view/7527.html)

## 47.std::fixed和std::setprecision(2)

[参考链接：C++ fixed用法详解](http://c.biancheng.net/view/1341.html)
流操作符`fixed`，表示浮点输出应该以固定点或小数点表示法显示，而不是通过科学计数法

```cpp
cout << 10.65486 << fixed << setprecision(2);
//输出 10.65
```

## 48.common::math::Clamp

没找到资料，是apollo内实现的函数，`modules/common/math/math_utils.h`

```cpp
template <typename T>
T Clamp(const T value, T bound1, T bound2) {
  if (bound1 > bound2) {
    std::swap(bound1, bound2);
  }

  if (value < bound1) {
    return bound1;
  } else if (value > bound2) {
    return bound2;
  }
  return value;
}
```



## 49.hypot (cmath)

c=hypot(a,b)，代表c=sqrt(a^2+b^2)

## 50.`std::numeric_limits<double>::max();`

是函数，返回编译器允许的double类型的数的最大值。

[参考链接：numeric_limits<double>::max ()的用法](https://blog.csdn.net/qq_37554547/article/details/96852197)

## 51.单例设计模式

[参考链接：五分钟学设计模式.01.单例模式](https://www.bilibili.com/video/BV1af4y1y7sS?from=search&seid=15082392538170520370&spm_id_from=333.337.0.0)

确保一个类只有一个实例，而且自行实例化并向整个系统提供这个示例。

确保一个类只有一个实例，那就要求它的构造方法一定不能是public公开的，即不能被外界进行实例化，那它的构造方法只能是private。

接着，它只有一个实例，这个实例属于当前类，即这个实例是当前类的类成员变量及类静态变量，我们知道类变量就是静态变量，即用static修饰。

所以说上半句话，我们就可以想象出来，这种设计模式要求构造方法是private，并且拥有一个当前类的静态成员变量，后面它要求向整个系统提供这个实例，即我们要再提供一个静态的方法，向外界提供当前类的实例，当前实例只能在内部进行实例化，它不能放到外面去。

单例模式的主要作用是确保一个类只有一个实例存在，比如说序列号生成器、Web页面的计数器等等都可以使用单例模式，同时如果创建某个对象需要消耗较多资源的话，比如访问IO，或者数据库资源的时候，我们也可以使用单例模式来减少资源的消耗。

我们现在来看一下单例模式的实现：

```java
package interview.pattern;

public class SingletonPattern {
    public static void main(String[] args) {
    }
}

class Singleton{
    private static Singleton singleton;
    private Singleton(){}
    
    public static Singleton getInstance(){
        return null;
    }
}
```

对于一个实现了单例模式的类来说呢，它首先构造方法必须是私有的，即Private，接着，它拥有一个唯一的实例，即它的类变量，静态变量，用static修饰的，但是我们singleton在什么时候进行实例化呢，可以看到它刚开始是空的，根据实例化实际不同，单例模式可以分为两种，饿汉式和懒汉式。

饿汉式，即在类加载的时候就进行实例化，返回时返回这个实例化对象

```cpp
package interview.pattern;

public class SingletonPattern {
    public static void main(String[] args) {
    }
}

class Singleton{
    private static Singleton singleton = new Singleton();  //饿汉式，1.类加载的时候就进行实例化
    private Singleton(){}
    
    public static Singleton getInstance(){
        return singleton;    //2.返回时返回这个实例化对象
    }
}
```

懒汉式，在刚开始，即类加载的时候不进行实例化，在第一次使用的时候再进行实例化

```cpp
package interview.pattern;

public class SingletonPattern {
    public static void main(String[] args) {
    }
}

class Singleton{
    private static Singleton singleton;
    private Singleton(){}
    
    public static Singleton getInstance(){
        if(singleton == nullptr)
        {
            singleton = new Singleton();  //在第一次调用，即getInstance()方法的时候才进行实例化
        }
        return singleton;
    }
}
```

## 52.静态成员变量 static

1.静态数据成员的定义和调用

2.静态数据成员的本质

3.使用静态成员的好处

​    // 静态成员变量

​    // （1） 要单独的把实现写在类外(.cpp中)

​    // （2） 默认会用0对该成员进行初始化

​    // （3） 静态成员变量是同一个类的不同对象共用的，所以不占用类的内存大小

​    // （4） 本质：带类域的全局变量

[参考链接：shellmad-c++_42 静态成员变量 ](https://www.bilibili.com/video/BV1hV411d7JB?spm_id_from=333.999.0.0)  [代码](JianzhiOffer_ws/shellmad_static/shellmad_42_1.cpp)

## 53.声明和定义

声明，是告诉编译器一些信息，以协助编译器进行语法分析，避免编译器报错。

定义，是告诉编译器生成一些代码，并且这些代码由连接器使用，在运行时分配内存

**编译器编译程序时，只会一个一个源文件编译，并分别生成相应的中间文件（对VC就是.obj文件），然后再由连接器统一将所有的中间文件连接形成一个可执行文件。**

[参考链接：C++函数和变量的声明、定义的原因和作用](https://blog.csdn.net/luyumiao1990/article/details/23944373)

## 54.静态成员函数

[参考链接：shellmad-c++_43 静态成员函数](https://www.bilibili.com/video/BV1EZ4y1p7q5?spm_id_from=333.999.0.0)   [代码](JianzhiOffer_ws/shellmad_static/shellmad_43_1.cpp)

​    // 静态成员函数

​    // （1） 在头文件的函数名前面加上关键字static

​    // （2） 函数内部不能够访问非静态成员变量，只能访问静态成员变量

​    // （3） 本质：静态成员函数中是没有this指针

​    // （4） 静态成员函数实际上就是带类域的全局函数

## 55.strftime()函数

[参考链接：C++中strftime()的详细说明](https://blog.csdn.net/clarkness/article/details/90047406)

strftime()函数将时间格式化为我们想要的格式

```cpp
time_t rawtime;  //1.time_t这种类型是存储从1970年1月1日 到现在经过了多少秒
char name_buffer[80];
std::time(&rawtime);  //2.获得time_t类型的“当前时间”
std::tm time_tm;   //3.定义一个tm结构体的时间变量
localtime_r(&rawtime, &time_tm);  //4.把time_t类型的时间转换成tm结构的时间格式
strftime(name_buffer, 80, "/tmp/speed_log__%F_%H%M%S.csv", &time_tm);  //5.把time_tm的时间转换成格式化的字符
//%F 年-月-日   %H 24小时制的小时  %M 十时制表示的分钟数   %S 十进制的秒数
```

[参考链接：c++ 时间类型详解 time_t](https://blog.csdn.net/love_gaohz/article/details/6637625)

其中std::tm结构体：

```cpp
struct tm
{
    int tm_sec;  /*秒，正常范围0-59， 但允许至61*/
    int tm_min;  /*分钟，0-59*/
    int tm_hour; /*小时， 0-23*/
    int tm_mday; /*日，即一个月中的第几天，1-31*/
    int tm_mon;  /*月， 从一月算起，0-11*/  1+p->tm_mon;
    int tm_year;  /*年， 从1900至今已经多少年*/  1900＋ p->tm_year;
    int tm_wday; /*星期，一周中的第几天， 从星期日算起，0-6*/
    int tm_yday; /*从今年1月1日到目前的天数，范围0-365*/
    int tm_isdst; /*日光节约时间的旗标*/
};
/*————————————————
版权声明：本文为CSDN博主「helmsgao」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/love_gaohz/article/details/6637625*/
```

> `local_time_r()`:通过time_t格式的时间转换成tm格式的时间结构，运行在linux平台下,
>
> 函数原型为struct tm *localtime_r(const time_t *timep, struct tm *result);  
>
> `local_time_s()`:用来获取系统时间，运行在windows平台下
>
> [参考链接：localtime、localtime_s、localtime_r的使用](https://blog.csdn.net/u010087712/article/details/50731222)

## 56.size_t

[参考链接：【C/C++】size_t详解](https://blog.csdn.net/qq_34018840/article/details/100884317)

使用size_t可能会提高代码的可移植性、有效性或者可读性，或许同时提高这三者。

size_t是标准C库中定义的，它是一个基本的与机器相关的**无符号整数**的C/C + +类型， 它是sizeof操作符返回的结果类型，该类型的大小可选择。其大小足以保证存储内存中对象的大小（简单理解为 unsigned int就可以了，64位系统中为 long unsigned int）。通常用sizeof(XX)操作，这个操作所得到的结果就是size_t类型。
（可以理解size_t是和操作系统的位数是相关的，如果是32位系统，那么size_t的表示范围是0～2^32，如果是64位系统，那么size_t的表示范围是0～2^64）
