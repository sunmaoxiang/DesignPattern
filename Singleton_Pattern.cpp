/*
单例模式：单例模式确保某一个类只有一个实例，而且自行实例化并向整个系统提供这个实例，这个类称为单例类，它提供全局访问的方法。
*/

#include <bits/stdc++.h>
using namespace std;

class Singleton {
public:
    static Singleton* getSingleton();
    Singleton();
    ~Singleton();
    void use();
private:
    static Singleton* instance;
};

Singleton* Singleton::instance = NULL;

Singleton::Singleton() {
    // pass
}

Singleton::~Singleton() {
    delete instance;
}

Singleton* Singleton::getSingleton() {
    if(instance == NULL) {
        instance = new Singleton();
    }
    return instance;
}

void Singleton::use() {
    cout << "Using Singleton." << endl;
}

int main()
{
    Singleton* singleton = Singleton::getSingleton();
    singleton->use();
    return 0;
}