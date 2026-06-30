#pragma once

class Unit;

class IHealable {
public:
    virtual void heal(Unit& target) = 0;
    virtual ~IHealable() {}
};
