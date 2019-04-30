#ifndef _CS_
#define _CS_
#include "Subject.h"

class ConcreteSubject : public Subject {
public:    
    ConcreteSubject();
    virtual ~ConcreteSubject() = default;
    virtual int getState();
    virtual void setState(int s);
private:
    int now_state;
};

#endif