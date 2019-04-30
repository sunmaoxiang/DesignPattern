#include "ConcreteObeserver.h"
#include <iostream>
#include <vector>
#include "Subject.h"

using namespace std;



ConcreteObserver::ConcreteObserver(string name) {
    this->obs_name = name;
}

void ConcreteObserver::update(Subject * sub) {
    this->obs_state = sub->getState();
    cout << "update oberserver " << obs_name << " state: " << obs_state << endl;  
}