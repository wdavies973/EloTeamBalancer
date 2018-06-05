//
// Created by Will Davies on 6/5/2018.
//

#include <iostream>
#include "Team.h"

void Team::toString() {
    for(int i = 0; i < players.size(); i++) {
        std::cout << players[i] << " ";
    }
}

Team::Team(int skill) {
    _skill = skill;
}

void Team::addPlayer(int playerIndex) {
    players.push_back(playerIndex);
}
