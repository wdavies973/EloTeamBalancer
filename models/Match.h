//
// Created by Will Davies on 6/5/2018.
//

#ifndef ELOTEAMBALANCER_MATCH_H
#define ELOTEAMBALANCER_MATCH_H


#include "Team.h"

class Match {
private:
    std::vector<Team> _teams;
    int _tolerance; // the quality of this matchup
public:
    Match(std::vector<Team> & teams, int tolerance) : _tolerance(tolerance) {
        _teams = teams;
    }
    const int getTolerance()const {
        return _tolerance;
    }
    std::vector<Team> getTeams() {
        return _teams;
    }
    void toString();

};

#endif //ELOTEAMBALANCER_MATCH_H
