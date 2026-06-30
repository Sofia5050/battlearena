#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer(string name) : Unit(name, 110, 40) {}

void Archer::attack(Unit& target) {
    cout << name << " attacks " << target.getName() << " with arrow!" << endl;
    target.takeDamage(damage);
}

void Archer::move() {
    cout << name << " runs fast as the wind" << endl;
}

void Archer::showInfo() const {
    cout << "=== Archer ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << "/" << maxHp << endl;
    cout << "Damage: " << damage << endl;
}

string Archer::getType() const {
    return "Archer";
}
