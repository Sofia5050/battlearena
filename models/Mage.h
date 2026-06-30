#pragma once

#include "Unit.h"
#include "../interfaces/IAttackable.h"
#include "../interfaces/IMovable.h"

class Mage : public Unit, public IAttackable, public IMovable {
public:
    Mage(string name);

    void attack(Unit& target) override;
    void move() override;
    void showInfo() const override;
    string getType() const override;
};
