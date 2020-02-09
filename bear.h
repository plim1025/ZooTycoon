#ifndef BEAR_H
#define BEAR_H

#include "animal.h"

using namespace std;

class Bear : public Animal {
  private:
    int sick_cost;

  public:
    static const int cost;
    static const int babies_at_once;
    static const int food_multiplier;

    Bear();
    Bear(int age);
    Bear(const Bear&);
    Bear& operator=(const Bear&);
    ~Bear();

    int get_sick_cost() const;
};

#endif
