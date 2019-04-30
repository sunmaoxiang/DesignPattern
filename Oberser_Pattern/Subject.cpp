#include "Subject.h"

Subject::Subject() {

}

void Subject::attach(Observer * observer) {
    this->observers.push_back(observer);
}

void Subject::notify() {
    for (auto & it : observers) {
        it->update(this);
    }
}

void Subject::detach(Observer * observer) {
    for(vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++) {
        if(*it == observer) {
            observers.erase(it);
            break;
        }
    }
}


