#include "Game.h"
#include "../models/Warrior.h"
#include "../models/Mage.h"
#include "../models/Archer.h"
#include "../models/Healer.h"
#include "../interfaces/IAttackable.h"
#include "../interfaces/IMovable.h"
#include "../interfaces/IHealable.h"
#include <iostream>
using namespace std;

void Game::run() {
    int choice = 0;

    while (choice != 7) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            createCharacter();
        } else if (choice == 2) {
            showAllCharacters();
        } else if (choice == 3) {
            showCharacterDetails();
        } else if (choice == 4) {
            startBattle();
        } else if (choice == 5) {
            healCharacter();
        } else if (choice == 6) {
            deleteCharacter();
        } else if (choice == 7) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Wrong choice!" << endl;
        }

        cout << endl;
    }
}

void Game::showMenu() {
    cout << "=== Battle Arena ===" << endl;
    cout << "1. Create character" << endl;
    cout << "2. Show all characters" << endl;
    cout << "3. Show character details" << endl;
    cout << "4. Start battle" << endl;
    cout << "5. Heal character" << endl;
    cout << "6. Delete character" << endl;
    cout << "7. Exit" << endl;
    cout << "Choice: ";
}

void Game::createCharacter() {
    string name;
    int type;

    cout << "Enter name: ";
    cin >> name;

    cout << "Choose class:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Archer" << endl;
    cout << "4. Healer" << endl;
    cout << "Choice: ";
    cin >> type;

    if (type == 1) {
        units.push_back(new Warrior(name));
    } else if (type == 2) {
        units.push_back(new Mage(name));
    } else if (type == 3) {
        units.push_back(new Archer(name));
    } else if (type == 4) {
        units.push_back(new Healer(name));
    } else {
        cout << "Wrong class!" << endl;
        return;
    }

    cout << name << " created!" << endl;
}

void Game::showAllCharacters() {
    if (units.empty()) {
        cout << "No characters!" << endl;
        return;
    }

    for (int i = 0; i < units.size(); i++) {
        cout << i + 1 << ". " << units[i]->getName()
             << " [" << units[i]->getType() << "]"
             << " HP: " << units[i]->getHp()
             << " DMG: " << units[i]->getDamage();

        if (!units[i]->isAlive()) {
            cout << " [DEAD]";
        }

        cout << endl;
    }
}

void Game::showCharacterDetails() {
    if (units.empty()) {
        cout << "No characters!" << endl;
        return;
    }

    showAllCharacters();
    cout << "Choose character: ";

    int index;
    cin >> index;
    index--;

    if (index < 0 || index >= units.size()) {
        cout << "Wrong number!" << endl;
        return;
    }

    units[index]->showInfo();

    IMovable* movable = dynamic_cast<IMovable*>(units[index]);
    if (movable) {
        movable->move();
    }
}

void Game::startBattle() {
    if (units.size() < 2) {
        cout << "Need at least 2 characters!" << endl;
        return;
    }

    showAllCharacters();

    cout << "Choose attacker: ";
    int a;
    cin >> a;
    a--;

    cout << "Choose target: ";
    int t;
    cin >> t;
    t--;

    if (a < 0 || a >= units.size() || t < 0 || t >= units.size()) {
        cout << "Wrong number!" << endl;
        return;
    }

    if (a == t) {
        cout << "Cannot attack yourself!" << endl;
        return;
    }

    if (!units[a]->isAlive()) {
        cout << units[a]->getName() << " is dead!" << endl;
        return;
    }

    if (!units[t]->isAlive()) {
        cout << units[t]->getName() << " is already dead!" << endl;
        return;
    }

    IAttackable* attacker = dynamic_cast<IAttackable*>(units[a]);
    if (attacker) {
        attacker->attack(*units[t]);
    }

    if (!units[t]->isAlive()) {
        cout << units[t]->getName() << " has been defeated!" << endl;
    }
}

void Game::healCharacter() {
    if (units.empty()) {
        cout << "No characters!" << endl;
        return;
    }

    int healerIndex = -1;
    for (int i = 0; i < units.size(); i++) {
        if (units[i]->getType() == "Healer" && units[i]->isAlive()) {
            healerIndex = i;
            break;
        }
    }

    if (healerIndex == -1) {
        cout << "No healer in team!" << endl;
        return;
    }

    showAllCharacters();
    cout << "Choose who to heal: ";

    int target;
    cin >> target;
    target--;

    if (target < 0 || target >= units.size()) {
        cout << "Wrong number!" << endl;
        return;
    }

    IHealable* healer = dynamic_cast<IHealable*>(units[healerIndex]);
    if (healer) {
        healer->heal(*units[target]);
    }
}

void Game::deleteCharacter() {
    if (units.empty()) {
        cout << "No characters!" << endl;
        return;
    }

    showAllCharacters();
    cout << "Choose character to delete: ";

    int index;
    cin >> index;
    index--;

    if (index < 0 || index >= units.size()) {
        cout << "Wrong number!" << endl;
        return;
    }

    cout << units[index]->getName() << " deleted!" << endl;
    delete units[index];
    units.erase(units.begin() + index);
}

Game::~Game() {
    for (int i = 0; i < units.size(); i++) {
        delete units[i];
    }
}
