/*
** Program: Zoo Tycoon
** Author: Paul Lim
** Date: 2/8/2020
** Description: A game where you are a zookeeper managing sealions, tigers, and bears
*/

#include <iostream>
#include <cstdlib>
#include "zoo.h"
#include "animal.h"
#include "tiger.h"
#include "tiger.h"
#include "tiger.h"

using namespace std;

int main() {
    srand(time(NULL));

    Zoo zoo;
    while(zoo.get_money() >= 0) {
        zoo.random_event();
        zoo.collect_revenue();
        zoo.buy_animals();
        zoo.pay_feeding_cost();
        cout << endl << zoo << endl;
        zoo.end_turn();
	if(zoo.get_money() < 700 && zoo.get_num_animals() == 0) {
		cout << "You have no animals and not enough money to buy any. Game over." << endl;
		return 0;
	}		
    }
    cout << "You went bankrupt, game over." << endl;
    return 0;
}
