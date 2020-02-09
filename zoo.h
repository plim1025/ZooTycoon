#include <iostream>
#include "animal.h"
#include "sealion.h"
#include "tiger.h"
#include "bear.h"

#ifndef ZOO_H
#define ZOO_H

class Zoo {
  private:
    int money;
    int feeding_cost;
    int feed_type;
    int revenue;
    int spent;
    int num_animals;
    int num_sealions;
    int num_tigers;
    int num_bears;
    Sealion *sealions;
    Tiger *tigers;
    Bear *bears;
  public:
    Zoo();
    Zoo(const Zoo&);
    Zoo& operator=(const Zoo&);
    ~Zoo();

    int get_money() const;
    int get_feeding_cost() const;
    int get_revenue() const;
    int get_spent() const;
    int get_num_animals() const;
    int get_num_sealions() const;
    int get_num_tigers() const;
    int get_num_bears() const;
    int get_num_adult_sealions() const;
    int get_num_adult_tigers() const;
    int get_num_adult_bears() const;
    Sealion* get_sealions() const;
    Tiger* get_tigers() const;
    Bear* get_bears() const;
    Sealion get_random_sealion() const;
    Tiger get_random_tiger() const;
    Bear get_random_bear() const;

    void add_sealion(int age = 0);
    void add_tiger(int age = 0);
    void add_bear(int age = 0);
    void remove_sealion(int);
    void remove_tiger(int);
    void remove_bear(int);

    void random_event();

    void sick_event();
    void get_random_index_or_type(int* type, int* index = NULL) const;

    void birth_event();
    bool birth_possible() const;
    int get_birth_type() const;

    void boom_event();

    void collect_revenue();
    void buy_animals();
    bool enough_money(string animal_type, string num_animals = "1");

    void get_feed_type();
    void set_feeding_cost();
    void pay_feeding_cost();

    void end_turn();
};

ostream& operator<<(ostream&, const Zoo& zoo);

#endif