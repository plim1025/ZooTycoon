#include "tiger.h"
#include <iostream>

using namespace std;

const int Tiger::cost = 12000;
const int Tiger::babies_at_once = 3;
const int Tiger::food_multiplier = 5;

// Tiger default constructor
Tiger::Tiger() : Animal() {
    // cout << "Tiger default constructor called" << endl;
    revenue = 2400;
}

// Tiger normal constructor
Tiger::Tiger(int new_age) : Animal(new_age) {
    // cout << "Tiger normal constructor called " << endl;
    if(age < 6)
        revenue = 2400;
    else
        revenue = 1200;
}

// Tiger copy constructor
Tiger::Tiger(const Tiger& old_tiger) : Animal(old_tiger) {
    // cout << "Tiger copy constructor called " << endl;
}

// Tiger assignment operator overload
Tiger& Tiger::operator=(const Tiger& old_tiger) {
    // cout << "Tiger assignment operator overload called " << endl;
    age = old_tiger.age;
    revenue = old_tiger.revenue;
    return *this;
}

// Tiger destructor
Tiger::~Tiger() {
    // cout << "Tiger destructor called " << endl;
}

// Getter for sick cost of tiger
int Tiger::get_sick_cost() const {
    if(age < 6)
        return cost;
    else
        return cost/2;
}