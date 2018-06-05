//
// Created by Will Davies on 6/5/2018.
//

#ifndef ELOTEAMBALANCER_TEAM_H
#define ELOTEAMBALANCER_TEAM_H


#include <string>
#include <vector>

class Team {
private:
    std::vector<int> players;
    int _skill;
public:
    explicit Team(int skill);
    void addPlayer(int playerIndex);
    int getSkill() {
        return _skill;
    }
    std::vector<int> getPlayers() {
        return players;
    }
    int getPlayer(int index) {
        return players[index];
    }
    int getPlayerSize() {
        return players.size();
    }
    void toString();
};


#endif //ELOTEAMBALANCER_TEAM_H
