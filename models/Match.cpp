//
// Created by Will Davies on 6/5/2018.
//

#include <iostream>
#include "Match.h"

void Match::toString() {
    std::cout << "Team";
    for(int i = 0; i < _teams.size(); i++) {
        _teams[i].toString();
    }
}
