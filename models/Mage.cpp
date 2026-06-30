#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(string name) : Unit(name, 100, 50) {}

void Mage::attack(Unit& target) {
    cout << name << " attacks " << target.getName() << " with fireball!" << endl;
    target.takeDamage(damage);
}

void Mage::move() {
    cout << name << " teleports forward" << endl;
}

void Mage::showInfo() const {
    cout << "=== Mage ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << "/" << maxHp << endl;
    cout << "Damage: " << damage << endl;
}

string Mage::getType() const {
    return "Mage";
}
