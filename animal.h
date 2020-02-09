#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {

  protected:
    int age;
    int revenue;

  public:
    Animal();
    Animal(int);
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    ~Animal();

    int get_age() const;
    int get_revenue() const;
    void set_age(int);
    void set_revenue(int);
    void increase_age();
};

#endif