#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "ConcreteObeserver.h"
#include "ConcreteSubject.h"

using namespace std;

int main()
{
    Subject * subject = new ConcreteSubject();
    Observer * obA = new ConcreteObserver("A");
    Observer * obB = new ConcreteObserver("B");
    subject->attach(obA);
    subject->attach(obB);
    subject->setState(1);
    subject->notify();
    cout << "=====================================" << endl;
    subject->detach(obA);
    subject->setState(2);
    subject->notify();
    return 0;
}
