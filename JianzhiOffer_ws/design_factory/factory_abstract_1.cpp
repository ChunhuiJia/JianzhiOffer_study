#include <iostream>
#include <string>

using namespace std;

class Fruit
{
public:
    virtual void getName() = 0;
};

//苹果
class Apple : public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是苹果" << endl;
    }
};

//香蕉
class Banana : public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是香蕉" << endl;
    }
};

//梨子
class Pear : public Fruit
{
public:
    void getName()
    {
        cout << "我是梨子" << endl;
    }
};

//工厂
class Factory
{
public:
    //水果生产器
    virtual Fruit *createFruit() = 0;
};

class AppleFactory : public Factory
{
    Fruit *createFruit() override
    {
        return new Apple();
    }
};

class BananaFactory : public Factory
{
    Fruit *createFruit() override
    {
        return new Banana();
    }
};

class PearFactory : public Factory
{
    Fruit *createFruit() override
    {
        return new Pear();
    }
};

// class PearFactory:public Factory{

// };

//把工厂和水果都抽象出来，添加生产梨子的，只需要添加梨子（继承自水果）和梨子工厂（继承自工厂）
//抽象工厂模式
int main(void)
{
    Factory *factory = new AppleFactory();
    Fruit *apple = factory->createFruit();
    apple->getName();

    Factory *bananafactory = new BananaFactory();
    Fruit *banana = bananafactory->createFruit();
    banana->getName();

    Factory *pearfactory = new PearFactory();
    Fruit *pear = pearfactory->createFruit();
    pear->getName();

    delete factory;
    delete apple;
    return 0;
}