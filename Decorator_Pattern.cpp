/*
装饰模式(Decorator Pattern) ：动态地给一个对象增加一些额外的职责(Responsibility)，就增加对象功能来说，装饰模式比生成子类实现更为灵活。其别名也可以称为包装器(Wrapper)，与适配器模式的别名相同，但它们适用于不同的场合。根据翻译的不同，装饰模式也有人称之为“油漆工模式”，它是一种对象结构型模式。
*/
#include <bits/stdc++.h>

using namespace std;

// 饮料抽象类
class Beverage {
public:
    Beverage() {}
    ~Beverage() = default;
    string getDescription() {
        return this->description;
    }
    virtual double cost() { return 0.0; }
protected:
    string description = "Unknown Beverage";
};

// 调料抽象类
class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() { return ""; }
};

// 一个具体的饮料——浓缩咖啡，但是需要调料进行装饰
class Espresso : public Beverage {
public:
    Espresso() {
        this->description = "Espresso";
    }
    virtual double cost() {
        return 1.99;
    }
};

// 摩卡调料，浓缩咖啡 + 摩卡调料 = 摩卡咖啡
class Mocha : public CondimentDecorator {
public: 
    Mocha(Beverage * beverage) : beverage(beverage) {}
    virtual string getDescription() {
        return beverage->getDescription() + ", Mocha";
    }
    virtual double cost() {
        return 0.2 + this->beverage->cost();
    }
private:
    Beverage* beverage; 
};

int main()
{
    Beverage* _espresso = new Espresso();
    cout << "一杯普通的浓缩咖啡：";
    cout << _espresso->getDescription() << " $" << _espresso->cost() << endl;
    Beverage* mochaCoffee = new Mocha(_espresso);
    cout << "一杯一份摩卡的咖啡：";
    cout << mochaCoffee->getDescription() << " $" << mochaCoffee->cost() << endl;
    Beverage* mocha2Coffee = new Mocha(mochaCoffee);
    cout << "一杯两份摩卡的咖啡：";
    cout << mocha2Coffee->getDescription() << " $" << mocha2Coffee->cost() << endl;
    delete _espresso;
    delete mochaCoffee;
    delete mocha2Coffee;
    return 0;
}