#include "Unit.h"
#include <iostream>
using namespace std;

Unit::Unit(string name, int hp, int damage) {
    this->name = name;
    this->hp = hp;
    this->maxHp = hp;
    this->damage = damage;
}

string Unit::getName() const {
    return name;
}

int Unit::getHp() const {
    return hp;
}

int Unit::getDamage() const {
    return damage;
}

void Unit::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    cout << name << " takes " << damage << " damage! HP: " << hp << endl;
}

void Unit::restoreHp(int amount) {
    hp += amount;
    if (hp > maxHp) {
        hp = maxHp;
    }
}

bool Unit::isAlive() const {
    return hp > 0;
}
