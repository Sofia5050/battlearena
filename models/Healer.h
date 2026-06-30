#pragma once

#include "Unit.h"
#include "../interfaces/IAttackable.h"
#include "../interfaces/IMovable.h"
#include "../interfaces/IHealable.h"

class Healer : public Unit, public IAttackable, public IMovable, public IHealable {
public:
    Healer(string name);

    void attack(Unit& target) override;
    void move() override;
    void heal(Unit& target) override;
    void showInfo() const override;
    string getType() const override;
};
