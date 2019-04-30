#ifndef _OBSERVER
#define _OBSERVER
class Subject;

class Observer {
public:
    Observer();
    ~Observer() = default;
    virtual void update(Subject * sub) = 0;
};

#endif