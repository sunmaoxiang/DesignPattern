#include "ConcreteSubject.h"
#include <iostream>
ConcreteSubject::ConcreteSubject() {

}


int ConcreteSubject::getState() {
    return this->now_state;
}

void ConcreteSubject::setState(int s) {
    this->now_state = s;
} 