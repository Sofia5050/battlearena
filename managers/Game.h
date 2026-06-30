#pragma once

#include "../models/Unit.h"
#include <vector>

class Game {
private:
    vector<Unit*> units;

public:
    void run();
    void showMenu();
    void createCharacter();
    void showAllCharacters();
    void showCharacterDetails();
    void startBattle();
    void healCharacter();
    void deleteCharacter();

    ~Game();
};
