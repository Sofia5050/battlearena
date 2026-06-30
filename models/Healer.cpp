#include "Healer.h"
#include <iostream>
using namespace std;

Healer::Healer(string name) : Unit(name, 90, 15) {}

void Healer::attack(Unit& target) {
    cout << name << " attacks " << target.getName() << " with staff!" << endl;
    target.takeDamage(damage);
}

void Healer::move() {
    cout << name << " walks carefully" << endl;
}

void Healer::heal(Unit& target) {
    int healAmount = 30;
    cout << name << " heals " << target.getName() << " for " << healAmount << " HP!" << endl;
    target.restoreHp(healAmount);
    cout << target.getName() << " now has " << target.getHp() << " HP" << endl;
}

void Healer::showInfo() const {
    cout << "=== Healer ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << "/" << maxHp << endl;
    cout << "Damage: " << damage << endl;
    cout << "Heal: 30" << endl;
}

string Healer::getType() const {
    return "Healer";
}
