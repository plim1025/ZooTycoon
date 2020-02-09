#include "zoo.h"
#include "animal.h"
#include "sealion.h"
#include "tiger.h"
#include "bear.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Zoo default constructor
Zoo::Zoo() {
    // cout << "Zoo default constructor called" << endl;
    money = 100000;
    feeding_cost = 80;
    feed_type = 0;
    revenue = 0;
    spent = 0;
    num_animals = 0;
    num_sealions = 0;
    num_tigers = 0;
    num_bears = 0;
    sealions = NULL;
    tigers = NULL;
    bears = NULL;
}

// Zoo copy constructor
Zoo::Zoo(const Zoo&) {
    // cout << "Zoo copy constructor called" << endl;
}

// Zoo assignment operator overload
Zoo& Zoo::operator=(const Zoo&) {
    // cout << "Zoo assignment operator overload called" << endl;
}

// Zoo destructor
Zoo::~Zoo() {
    // cout << "Zoo destructor called" << endl;
    if(num_sealions > 0)
        delete [] sealions;
    if(num_tigers > 0)
        delete [] tigers;
    if(num_bears > 0)
        delete [] bears;
}

// Getter for money
int Zoo::get_money() const {
    return money;
}

// Getter for feeding cost each turn
int Zoo::get_feeding_cost() const {
    return feeding_cost;
}

// Getter for revenue for current turn
int Zoo::get_revenue() const {
    return revenue;
}

// Getter for money spent for current turn
int Zoo::get_spent() const {
    return spent;
}

// Getter for number of animals
int Zoo::get_num_animals() const {
    return num_animals;
}

// Getter for number of sealions
int Zoo::get_num_sealions() const {
    return num_sealions;
}

// Getter for number of tigers
int Zoo::get_num_tigers() const {
    return num_tigers;
}

// Getter for number of bears
int Zoo::get_num_bears() const {
    return num_bears;
}

// Getter for number of adult sealions
int Zoo::get_num_adult_sealions() const {
    int num_adult_sealions = 0;
    for(int i = 0; i < num_sealions; i++) {
        if(sealions[i].get_age() > 48)
            num_adult_sealions++;
    }
    return num_adult_sealions;
}

// Getter for number of adult sealions
int Zoo::get_num_adult_tigers() const {
    int num_adult_tigers = 0;
    for(int i = 0; i < num_tigers; i++) {
        if(tigers[i].get_age() > 48)
            num_adult_tigers++;
    }
    return num_adult_tigers;
}

// Getter for number of adult bears
int Zoo::get_num_adult_bears() const {
    int num_adult_bears = 0;
    for(int i = 0; i < num_bears; i++) {
        if(bears[i].get_age() > 48)
            num_adult_bears++;
    }
    return num_adult_bears;
}

// Geter for sealion array
Sealion* Zoo::get_sealions() const {
    return sealions;
}

// Getter for tiger array
Tiger* Zoo::get_tigers() const {
    return tigers;
}

// Getter for bear array
Bear* Zoo::get_bears() const {
    return bears;
}

// Getter for random sealion
Sealion Zoo::get_random_sealion() const {
    int i = rand() % num_sealions;
    return sealions[i];
}

// Getter for random tiger
Tiger Zoo::get_random_tiger() const {
    int i = rand() % num_tigers;
    return tigers[i];
}

// Getter for random bear
Bear Zoo::get_random_bear() const {
    int i = rand() % num_bears;
    return bears[i];
}

// Adds a sealion into sealion array with a given age (default 0)
void Zoo::add_sealion(int age) {
    // Create new array 1 size bigger
    Sealion *new_sealions = new Sealion[num_sealions + 1];
    for(int i = 0; i < num_sealions; i++) {
        new_sealions[i].set_age(sealions[i].get_age());
        new_sealions[i].set_revenue(sealions[i].get_revenue());
    }
    if(num_sealions > 0)
        delete [] sealions;

    // Add new sealion to new array
    new_sealions[num_sealions].set_age(age);
    (age < 6) ? new_sealions[num_sealions].set_revenue(280) : new_sealions[num_sealions].set_revenue(140);

    // Redirect pointer to new sealions
    sealions = new_sealions;

    num_sealions++;
    num_animals++;
}

// Adds a tiger into tiger array with a given age (default 0)
void Zoo::add_tiger(int age) {
    // Create new array 1 size bigger
    Tiger *new_tigers = new Tiger[num_tigers + 1];
    for(int i = 0; i < num_tigers; i++) {
        new_tigers[i].set_age(tigers[i].get_age());
        new_tigers[i].set_revenue(tigers[i].get_revenue());
    }
    if(num_tigers > 0)
        delete [] tigers;

    // Add new sealion to new array
    new_tigers[num_tigers].set_age(age);
    (age < 6) ? new_tigers[num_tigers].set_revenue(2400) : new_tigers[num_tigers].set_revenue(1200);

    // Redirect pointer to new sealions
    tigers = new_tigers;

    num_tigers++;
    num_animals++;
}

// Adds a bear into bear array with given age (default 0)
void Zoo::add_bear(int age) {
    // Create new array 1 size bigger
    Bear *new_bears = new Bear[num_bears + 1];
    for(int i = 0; i < num_bears; i++) {
        new_bears[i].set_age(bears[i].get_age());
        new_bears[i].set_revenue(bears[i].get_revenue());
    }
    if(num_bears > 0)
        delete [] bears;

    // Add new sealion to new array
    new_bears[num_bears].set_age(age);
    (age < 6) ? new_bears[num_bears].set_revenue(1000) : new_bears[num_bears].set_revenue(500);

    // Redirect pointer to new sealions
    bears = new_bears;

    num_bears++;
    num_animals++;
}

// Removes a sealion at given index
void Zoo::remove_sealion(int index) {
    Sealion *new_sealions;
    // Create new array 1 size smaller
    if(num_sealions != 1)
        new_sealions = new Sealion[num_sealions - 1];
    else if (num_sealions == 0)
        new_sealions = NULL;
    // Copy over values to new array from old (check for index to not copy over)
    // i keeps track of old indexes
    // j keeps track of new indexes and only increments if data is copied over
    for(int i = 0, j = 0; i < num_sealions - 1; i++) {
        if(i != index) {
            int new_age = sealions[j].get_age();
            new_sealions[i].set_age(new_age);
            new_sealions[i].set_revenue(new_age < 6 ? 280 : 140);
            j++;
        }
    }

    delete [] sealions;

    // Redirect pointer to new sealions
    sealions = new_sealions;

    num_sealions--;
    num_animals--;
}

// Removes a tiger at given index
void Zoo::remove_tiger(int index) {
    Tiger *new_tigers;
    // Create new array 1 size smaller
    if(num_tigers != 1)
        new_tigers = new Tiger[num_tigers - 1];
    else
        new_tigers = NULL;
    // Copy over values to new array from old (check for index to not copy over)
    for(int i = 0; i < num_tigers; i++) {
        if(i != index) {
            int new_age = tigers[i].get_age();
            new_tigers[i].set_age(new_age);
            new_tigers[i].set_revenue(new_age < 6 ? 280 : 140);
        }
    }

    delete [] tigers;

    // Redirect pointer to new sealions
    tigers = new_tigers;

    num_tigers--;
    num_animals--;
}

// Removes a bear at given index
void Zoo::remove_bear(int index) {
    Bear *new_bears;
    // Create new array 1 size smaller
    if(num_bears != 1)
        new_bears = new Bear[num_bears - 1];
    else
        new_bears = NULL;
    // Copy over values to new array from old (check for index to not copy over)
    for(int i = 0; i < num_bears; i++) {
        if(i != index) {
            int new_age = bears[i].get_age();
            new_bears[i].set_age(new_age);
            new_bears[i].set_revenue(new_age < 6 ? 280 : 140);
        }
    }

    delete [] bears;

    // Redirect pointer to new sealions
    bears = new_bears;

    num_bears--;
    num_animals--;
}

// Selects a random event, either sick, birth, boom, or none
void Zoo::random_event() {
    if(num_animals == 0) {
        cout << "No animals in zoo, therefore no event possible" << endl;
        return;
    }
    int event_num = rand() % 8;
    switch(event_num) {
        case 0:
            if(feed_type == 0 || feed_type == 1)
                cout << "No event occurred this turn" << endl;
            else if(feed_type == 2)
                sick_event();
            break;
        case 1:
            if(feed_type == 0 || feed_type == 1)
                cout << "No event occurred this turn" << endl;
            else if(feed_type == 2)
                sick_event();
            break;
        case 2:
            sick_event();
            break;
        case 3:
            if(feed_type == 0 || feed_type == 2)
                sick_event();
            else if(feed_type == 1)
                cout << "No event occurred this turn" << endl;
            break;
        case 4:
            birth_event();
            break;
        case 5:
            birth_event();
            break;
        case 6:
            boom_event();
            break;
        case 7:
            boom_event();
    }
}

// If player has enough money to pay for sick animal, pay, else animal dies
void Zoo::sick_event() {
    cout << "Sick event:" << endl;
    int type_of_animal;
    int index_of_animal;
    get_random_index_or_type(&type_of_animal, &index_of_animal);
    // 0 - sealion, 1 - tiger, 2 - bear
    switch(type_of_animal) {
        case 0:
        {
            int sick_cost = sealions[index_of_animal].get_sick_cost();
            if(money > sick_cost) {
                money -= sick_cost;
                spent += sick_cost;
                cout << "\tA sealion got sick, paid " << sick_cost << " to help it recover" << endl;
            }
            else {
                remove_sealion(index_of_animal);
                cout << "\tA sealion got sick and you didn't have enough money to heal it. It dies." << endl;
            }

            break;
        }
        case 1:
        {
            int sick_cost = tigers[index_of_animal].get_sick_cost();
            if(money > sick_cost) {
                money -= sick_cost;
                spent += sick_cost;
                cout << "\tA tiger got sick, paid " << sick_cost << " to help it recover" << endl;
            }
            else {
                remove_tiger(index_of_animal);
                cout << "\tA tiger got sick and you didn't have enough money to heal it. It dies." << endl;
            }
            break;
        }
        case 2:
        {
            int sick_cost = bears[index_of_animal].get_sick_cost();
            if(money > sick_cost) {
                money -= sick_cost;
                spent += sick_cost;
                cout << "\tA bear got sick, paid " << sick_cost << " to help it recover" << endl;
            }
            else {
                remove_bear(index_of_animal);
                cout << "A bear got sick and you didn't have enough money to heal it. It dies." << endl;
            }

        }
    }
}

// Gets a random index and/or type of animal
// *Gives equal chance for all animals
void Zoo::get_random_index_or_type(int *type, int *index) const {
    srand(time(NULL));
    int overall_index = rand() % num_animals;
    if(overall_index < num_sealions) {
        // Since index is optional argument, must check if set before setting
        if(index)
            *index = overall_index;
        *type = 0;
    }
    else if(overall_index < num_sealions + num_tigers) {
        if(index)
            *index = overall_index - num_sealions;
        *type = 1;
    }
    else {
        if(index)
            *index = overall_index - num_sealions - num_tigers;
        *type = 2;
    }
}

// If player has at least one type of animal with two adults, birth occurs randomly
void Zoo::birth_event() {
    cout << "Birth event:" << endl;
    if(!birth_possible())
        return;

    int type = get_birth_type();
    switch(type) {
        case 0:
            for(int i = 0; i < Sealion::babies_at_once; i++)
                add_sealion();
            cout << Sealion::babies_at_once << " sealions added to zoo" << endl;
            break;
        case 1:
            for(int i = 0; i < Tiger::babies_at_once; i++)
                add_tiger();
            cout << Tiger::babies_at_once << " tigers added to zoo" << endl;
            break;
        case 2:
            for(int i = 0; i < Bear::babies_at_once; i++)
                add_bear();
            cout << Bear::babies_at_once << " bears added to zoo" << endl;
    }
}

bool Zoo::birth_possible() const {
    if(get_num_adult_sealions() >= 2)
        return true;
    else if(get_num_adult_tigers() >= 2)
        return true;
    else if(get_num_adult_bears() >= 2)
        return true;
    cout << "\tBirth event not possible, not enough adult animals of same species (minimum 2)" << endl;
    return false;
}

// Retrieves random type of animal
// *Gives each type probability based on number of that type of animal
int Zoo::get_birth_type() const {
    while(true) {
        int type;
        get_random_index_or_type(&type);
        switch(type) {
            case 0:
                if(get_num_adult_sealions() >= 2)
                    return 0;
                break;
            case 1:
                if(get_num_adult_tigers() >= 2)
                    return 1;
                break;
            case 2:
                if(get_num_adult_bears() >= 2)
                    return 2;
        }
    }
}

// Gives sealions bonus revenue for one turn
void Zoo::boom_event() {
    srand(time(NULL));
    cout << "Boom event:" << endl;
    if(num_sealions == 0)
        cout << "\tNo sealions owned, so no revenue bonus" << endl;
    for(int i = 0; i < num_sealions; i++) {
        int bonus = (rand() % 250) + 150;
        cout << "\tOne sealion gets a bonus " << bonus << " revenue this turn" << endl;
        money += bonus;
        revenue += bonus;
    }
}

// Collects revenue based on animal and age
void Zoo::collect_revenue() {
    for(int i = 0; i < num_sealions; i++) {
        money += sealions[i].get_revenue();
        revenue += sealions[i].get_revenue();
    }
    for(int i = 0; i < num_tigers; i++) {
        money += tigers[i].get_revenue();
        revenue += tigers[i].get_revenue();
    }
    for(int i = 0; i < num_bears; i++) {
        money += bears[i].get_revenue();
        revenue += bears[i].get_revenue();
    }
}

// Gives user option to buy animals, error handles if they do not have enough
void Zoo::buy_animals() {
    if(money < 700) {
        string dummy;
        cout << "You don't have enough money to buy animals, enter any key to continue: ";
        getline(cin, dummy);
        return;
    }

    string buy = "";
    while(buy != "0" && buy != "1") {
        cout << "Enter 1 to buy an animal or 0 to pass: ";
        getline(cin, buy);
    }

    if(buy == "0")
        return;

    string animal = "";
    while(animal != "1" && animal != "2" && animal != "3") {
        cout << "Enter 1 to buy sealion ($700), 2 to buy tiger ($12000), 3 to buy bear ($5000): ";
        getline(cin, animal);
        if(!enough_money(animal)) {
            cout << "Not enough money to buy this animal, please enter a different one" << endl;
            animal = "";
        }
    }
    string num_animals_str = "";
    while(num_animals_str != "0" && num_animals_str != "1" && num_animals_str != "2") {
        cout << "How many of these do you want to buy (max 2)? ";
        getline(cin, num_animals_str);
        if(!enough_money(animal, num_animals_str)) {
            cout << "Not enough money to buy this many animals, please enter a different number" << endl;
            num_animals_str = "";
        }
    }

    int num_animals_bought = atoi(num_animals_str.c_str());
    for(int i = 0; i < num_animals_bought; i++) {
        if(animal == "1") {
            add_sealion(48);
            money -= Sealion::cost;
            spent += Sealion::cost;
        }
        else if(animal == "2") {
            add_tiger(48);
            money -= Tiger::cost;
            spent += Tiger::cost;
        }
        else {
            add_bear(48);
            money -= Bear::cost;
            spent += Bear::cost;
        }
    }
}

// Checks if user has enough money to buy type of animal and number of that type (defualt 0)
bool Zoo::enough_money(string animal_type, string num_animals_str) {
    int num_animals_bought = atoi(num_animals_str.c_str());
    if(animal_type == "1") {
        if(money > Sealion::cost * num_animals_bought)
            return true;
        return false;
    }
    else if(animal_type == "2") {
        if(money > Tiger::cost * num_animals_bought)
            return true;
        return false;
    }
    else
        if(money > Bear::cost * num_animals_bought)
            return true;
        return false;
}

// Multiplies previous feeding cost by random percent between 80 and 120 sets it to member variable
void Zoo::set_feeding_cost() {
    srand(time(NULL));
    int percent_change = (rand() % 40) + 80;
    int change = feeding_cost * (float) percent_change / (float) 100;
    feeding_cost += change;
}

// Gets feed type from user (normal, premium, cheap)
void Zoo::get_feed_type() {
    string feed_type_str = "";
    while(feed_type_str != "0" && feed_type_str != "1" && feed_type_str != "2") {
        cout << "What type of feed would you like to purchase?" << endl;
        cout << "\tRegular (0) $" << feeding_cost << ", premium (1) $" << feeding_cost * 2;
        cout << ", or cheap (2) $" << feeding_cost/2 << ": ";
        getline(cin, feed_type_str);
    }
    feed_type = atoi(feed_type_str.c_str());
}

// Subtracts feed cost * num_animals from money
void Zoo::pay_feeding_cost() {
    if(num_animals > 0) {
        get_feed_type();
        if(feed_type == 1) {
            money -= 2 * (num_animals * feeding_cost);
            spent += 2 * (num_animals * feeding_cost);
        }
        else if(feed_type == 2) {
            money -= 0.5 * (num_animals * feeding_cost);
            spent += 0.5 * (num_animals * feeding_cost);
        }
        else {
            money -= num_animals * feeding_cost;
            spent += num_animals * feeding_cost;
        }

    }
}

// Increases age of animals and resets revenue and money spent
void Zoo::end_turn() {
    for(int i = 0; i < num_sealions; i++)
        sealions[i].increase_age();
    for(int i = 0; i < num_tigers; i++)
        tigers[i].increase_age();
    for(int i = 0; i < num_bears; i++)
        bears[i].increase_age();
    revenue = 0;
    spent = 0;
}

// Stream operator overload, used to print status of game
ostream& operator<<(ostream& stream, const Zoo& zoo) {
    stream << "Turn summary:" << endl;
    stream << "\tRevenue from animals this turn: " << zoo.get_revenue() << endl;
    stream << "\tMoney spent: " << zoo.get_spent() << endl;
    stream << "\tMoney: " << zoo.get_money() << endl;

    Sealion *sealions = zoo.get_sealions();
    Tiger *tigers = zoo.get_tigers();
    Bear *bears = zoo.get_bears();
    int num_sealions = zoo.get_num_sealions();
    int num_tigers = zoo.get_num_tigers();
    int num_bears = zoo.get_num_bears();
    stream << "\tAnimals: " << endl;
    for(int i = 0; i < num_sealions; i++)
        stream << "\t\tSealion: Age - " << sealions[i].get_age() << ", Revenue - " << sealions[i].get_revenue() << endl;

    for(int i = 0; i < num_tigers; i++)
        stream << "\t\tTigers: Age - " << tigers[i].get_age() << ", Revenue - " << tigers[i].get_revenue() << endl;

    for(int i = 0; i < num_bears; i++)
        stream << "\t\tBear: Age - " << bears[i].get_age() << ", Revenue - " << bears[i].get_revenue() << endl;

    return stream;
}
