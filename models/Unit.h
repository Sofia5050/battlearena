#pragma once

#include <string>
using namespace std;

class Unit {
protected:
    string name;
    int hp;
    int maxHp;
    int damage;

public:
    Unit(string name, int hp, int damage);

    string getName() const;
    int getHp() const;
    int getDamage() const;

    virtual void showInfo() const = 0;
    virtual string getType() const = 0;

    void takeDamage(int damage);
    void restoreHp(int amount);
    bool isAlive() const;

    virtual ~Unit() {}
};
