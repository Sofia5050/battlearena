#pragma once

class Unit;

class IAttackable {
public:
    virtual void attack(Unit& target) = 0;
    virtual ~IAttackable() {}
};
