#ifndef SEALION_H
#define SEALION_H

#include "animal.h"

using namespace std;

class Sealion : public Animal {
  private:
    int sick_cost;

  public:
    static const int cost;
    static const int babies_at_once;
    static const int food_multiplier;

    Sealion();
    Sealion(int age);
    Sealion(const Sealion&);
    Sealion& operator=(const Sealion&);
    ~Sealion();

    int get_sick_cost() const;
};

#endif