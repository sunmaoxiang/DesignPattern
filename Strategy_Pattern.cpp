#include <bits/stdc++.h>

using namespace std;
/*
策略模式(Strategy Pattern)：定义一系列算法，将每一个算法封装起来，并让它们可以相互替换。策略模式让算法独立于使用它的客户而变化，也称为政策模式(Policy)。
*/


// 叫的行为接口
class QuackBehavior {
public:
    QuackBehavior() = default;
    ~QuackBehavior() = default;
    virtual void quack() {} 
};

// 飞的行为接口
class FlyBehavior {
public:
    FlyBehavior() = default;
    ~FlyBehavior() = default;
    virtual void fly() {}
};

// 实现一种飞的算法
class MyFly : public FlyBehavior {
public:
    virtual void fly() {
        cout << "I fly fly fly." << endl;
    }
};

// 实现一种叫的算法
class MyQuack : public QuackBehavior {
public:
    virtual void quack() {
        cout << "I quack quack quack." << endl;
    }
};

class Duck {
public:
    Duck() {}
    ~Duck() {
        delete _quackBehavior;
        delete _flyBehavior;
    }
    void performFly() {
        _flyBehavior->fly();
    }
    void performQuack() {
        _quackBehavior->quack();
    }
protected:
    Duck(QuackBehavior* _quackBehavior,  FlyBehavior* _flyBehavior) : _quackBehavior(_quackBehavior), _flyBehavior(_flyBehavior)  {}
    QuackBehavior* _quackBehavior;
    FlyBehavior* _flyBehavior;
};

class MyDuck : public Duck {
public:
    MyDuck() : Duck(new MyQuack(), new MyFly()) {}
};

int main()
{
    MyDuck* myDuck = new MyDuck();
    myDuck->performFly();
    myDuck->performQuack();
    delete myDuck;
    return 0;
}