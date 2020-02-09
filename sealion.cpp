#include <iostream>
#include "sealion.h"

using namespace std;

const int Sealion::cost = 700;
const int Sealion::babies_at_once = 1;
const int Sealion::food_multiplier = 1;

// Sealion default constructor
Sealion::Sealion() : Animal() {
    // cout << "Sealion default constructor called" << endl;
    revenue = 280;
}

// Sealion normal constructor
Sealion::Sealion(int new_age) : Animal(new_age) {
    // cout << "Sealion normal constructor called " << endl;
    if(age < 6)
        revenue = 280;
    else
        revenue = 140;
}

// Sealion copy constructor
Sealion::Sealion(const Sealion& old_sealion) : Animal(old_sealion) {
    // cout << "Sealion copy constructor called " << endl;
}

// Sealion assignment operator overload
Sealion& Sealion::operator=(const Sealion& old_sealion) {
    // cout << "Sealion assignment operator overload called " << endl;
    age = old_sealion.age;
    revenue = old_sealion.revenue;
    return *this;
}

// Sealion destructor
Sealion::~Sealion() {
    // cout << "Sealion destructor called " << endl;
}

// Getter for sick cost of sealion
int Sealion::get_sick_cost() const {
    if(age < 6)
        return cost;
    else
        return cost/2;
}