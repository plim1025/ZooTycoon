#include <iostream>
#include "animal.h"

using namespace std;

// Animal default constructor
Animal::Animal() {
    // cout << "Animal default constructor called" << endl;
    age = 0;
}

// Animal normal constructor
Animal::Animal(int new_age) {
    // cout << "Animal normal constructor called" << endl;
    age = new_age;
}

// Animal copy constructor
Animal::Animal(const Animal& old_animal) {
    // cout << "Animal copy constructor called" << endl;
    age = old_animal.age;
    revenue = old_animal.revenue;
}

// Animal assignment operator overload
Animal& Animal::operator=(const Animal&) {
    // cout << "Animal assignment operator overload called" << endl;
}

// Animal destructor
Animal::~Animal() {
    // cout << "Animal destructor called" << endl;
}

// Getter for age of animal
int Animal::get_age() const {
    return age;
}

// Getter for revenue of animal
int Animal::get_revenue() const {
    return revenue;
}

// Setter for age of animal
void Animal::set_age(int new_age) {
    age = new_age;
}

// Setter for revenue of animal
void Animal::set_revenue(int new_revenue) {
    revenue = new_revenue;
}

// Increases age of animal, accounting for revenue
void Animal::increase_age() {
    age++;
    if(age == 6)
        revenue = revenue / 2;
}