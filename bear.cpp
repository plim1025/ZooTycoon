#include "bear.h"
#include <iostream>

using namespace std;

const int Bear::cost = 5000;
const int Bear::babies_at_once = 2;
const int Bear::food_multiplier = 3;

// Bear default constructor
Bear::Bear() : Animal() {
    // cout << "Bear default constructor called" << endl;
    revenue = 1000;
}

// Bear normal constructor
Bear::Bear(int new_age) : Animal(new_age) {
    // cout << "Bear normal constructor called " << endl;
    if(age < 6)
        revenue = 1000;
    else
        revenue = 500;
}

// Bear copy constructor
Bear::Bear(const Bear& old_bear) : Animal(old_bear) {
    // cout << "Bear copy constructor called " << endl;
}

// Bear assignment operator overload
Bear& Bear::operator=(const Bear& old_bear) {
    // cout << "Bear assignment operator overload called " << endl;
    age = old_bear.age;
    revenue = old_bear.revenue;
    return *this;
}

// Bear destructor
Bear::~Bear() {
    // cout << "Bear destructor called " << endl;
}

// Getter for sick cost of bear
int Bear::get_sick_cost() const {
    if(age < 6)
        return cost;
    else
        return cost/2;
}