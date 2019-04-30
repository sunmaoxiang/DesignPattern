#ifndef _SUBJECT
#define _SUBJECT
#include "Observer.h"
#include <vector>

using namespace std;

class Subject {
public:
    Subject();
    virtual ~Subject() = default;
    void attach(Observer * observer);    // add observer
    void detach(Observer * observer);    // 删除某个通知者    
    void notify();                       // 通知所有的观察者
    virtual int getState() = 0;
    virtual void setState(int s) = 0;
private:
    vector< Observer* > observers;
};

#endif