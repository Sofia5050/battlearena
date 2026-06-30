#pragma once

class IMovable {
public:
    virtual void move() = 0;
    virtual ~IMovable() {}
};
