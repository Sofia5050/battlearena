#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string name) : Unit(name, 150, 30) {}

void Warrior::attack(Unit& target) {
    cout << name << " attacks " << target.getName() << " with sword!" << endl;
    target.takeDamage(damage);
}

void Warrior::move() {
    cout << name << " moves slowly with heavy armor" << endl;
}

void Warrior::showInfo() const {
    cout << "=== Warrior ===" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << "/" << maxHp << endl;
    cout << "Damage: " << damage << endl;
}

string Warrior::getType() const {
    return "Warrior";
}
