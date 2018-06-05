//
// Created by Will Davies on 6/5/2018.
//

#ifndef ELOTEAMBALANCER_MATCHFINDER_H
#define ELOTEAMBALANCER_MATCHFINDER_H


#include <vector>
#include "BaseX.h"
#include "../models/Match.h"

class MatchFinder {
private:
    int _minPlayers;
    int _maxPlayers;
    int _numPlayers;
    int _numTeams;
    std::vector<std::string> _names;
    std::vector<int> _players; // reference to array of player skills, players will be temporarily identified by index
    BaseX baseX;
public:
    void compute();
    MatchFinder(std::vector<std::string> & names, std::vector<int> & players, int numPlayers, int minPlayersPerTeam, int maxPlayersPerTeam, int numTeams)
            : baseX(numTeams, numPlayers, minPlayersPerTeam, maxPlayersPerTeam), _numPlayers(numPlayers), _names(names) {
        _players = players;
        _minPlayers = minPlayersPerTeam;
        _maxPlayers = maxPlayersPerTeam;
        _numTeams = numTeams;
    }
};


#endif //ELOTEAMBALANCER_MATCHFINDER_H
