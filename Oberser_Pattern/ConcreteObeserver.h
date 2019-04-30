#ifndef _CO_
#define _CO_
#include "Observer.h"
#include "Subject.h"
#include <string>
using namespace std;

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(string name);
    virtual ~ConcreteObserver() = default;
    virtual void update(Subject * sub);
private:
    string obs_name;
    int obs_state;
};

#endif