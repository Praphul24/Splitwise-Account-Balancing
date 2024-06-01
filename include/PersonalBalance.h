#ifndef PERSONBALANCE_H
#define PERSONBALANCE_H

#include <string>
using namespace std;

class PersonalBalance {
public:
    string name;   // Person's name
    int balance;   // Person's balance

    PersonalBalance(string _name, int _balance){
        name = _name;
        balance = _balance;
    }
};

#endif // PERSONBALANCE_H
