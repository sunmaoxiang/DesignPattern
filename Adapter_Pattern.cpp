#include <bits/stdc++.h>
using namespace std;

/*
适配器模式：将一个类的接口，转换成客户期望的另一个接口。
适配器让原本接口不兼容的类可以合作无间。
*/

// 目标接口类，面向User
class Target {
public:
    Target() = default;
    virtual ~Target() = default;
    virtual void Request() {
        cout << "Target::Request()" << endl;
    }
};

// 需要适配的类
class Adaptee {
public:
    Adaptee() {}
    ~Adaptee() {}
    void SpecificRequest() {
        cout << "Adaptee::SpecificRequest()" << endl;
    }
};

/* 类模式 */
class Adapter : public Target, private Adaptee {
public: 
    Adapter() {}
    ~Adapter() {}
    virtual void Request() {             // 重写Target中的Request
        cout << "------------类模式-----------" << endl;
        this->SpecificRequest();
        cout << "------------类模式-----------" << endl;
    }
};


/* 对象模式 */
class Adaper0 : public Target {
public:
    Adaper0(Adaptee* adaptee) : _adaptee(adaptee) {}
    Adaper0() {}
    ~Adaper0() {}
    virtual void Request() {
        cout << "------------对象模式-----------" << endl;
        this->_adaptee->SpecificRequest();
        cout << "------------对象模式-----------" << endl;
    }
private:
    Adaptee* _adaptee;
};

int main()
{
    Adapter* adapter = new Adapter();
    adapter->Request();
    Adaptee* adaptee = new Adaptee(); 
    Adaper0* _adapter0 = new Adaper0(adaptee);
    _adapter0->Request();
    delete adapter;
    delete adaptee;
    delete _adapter0;
    return 0;
}