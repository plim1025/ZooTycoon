#ifndef TIGER_H
#define TIGER_H

#include "animal.h"

using namespace std;

class Tiger : public Animal {
  private:
    int sick_cost;

  public:
    static const int cost;
    static const int babies_at_once;
    static const int food_multiplier;

    Tiger();
    Tiger(int age);
    Tiger(const Tiger&);
    Tiger& operator=(const Tiger&);
    ~Tiger();

    int get_sick_cost() const;
};

#endif