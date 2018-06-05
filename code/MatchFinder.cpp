//
// Created by Will Davies on 6/5/2018.
//

#include <iostream>
#include <algorithm>
#include "MatchFinder.h"

void MatchFinder::compute() {
    std::cout << "Starting..." << std::endl;

    long long maxValue = baseX.getMaxValue();
    std::vector<Match> matches;

    int baseTolerance = 50; // matches not meeting this tolerance will be discarded

    for(long long i = 0; i < maxValue; i++) {
        baseX.increment();

        if(i % (1000000) == 0) {
            std::cout << "Progress: " << (double(i) / double(maxValue) * 100.0) << "% " << "(Matches: " << matches.size() << ")";
            //baseX.toString();
            std::cout << std::endl;
        }

       // baseX.toString();

        // Do some verification checks
        if(matches.size() >= 50) break;

        // Start processing the match
        auto * scores = new int[_numTeams];

		// default items to 0
		for (int k = 0; k < _numTeams; k++) {
			scores[k] = 0;
		}

        for(int k = 0; k < _numPlayers; k++) {
            scores[baseX.getDigit(k)] += _players[k];
        }

        // Calculate the highest skill difference between scores
        int highest = 0;
        for(int k = 0; k < _numTeams; k++) {
            for(int l = 0; l < _numTeams; l++) {
                if(k == l) continue;
                if(abs(scores[l] - scores[k]) > highest) highest = abs(scores[l] - scores[k]);
            }
        }

        if(highest > baseTolerance) {
            delete[] scores;
            continue; // Discard the team if it doesn't meet a certain tolerance level
       }

       // std::cout << "Processing possible candidate";

        // Otherwise, package a team and add it to the matches array
        // Create teams
        std::vector<Team> teams;
        for(int k = 0; k < _numTeams; k++) {
            Team team(scores[k]);
            // Add players
            for(int l = 0; l < _numPlayers; l++) {
                if(baseX.getDigit(l) == k) team.addPlayer(l);
            }

            teams.push_back(team);
        }

		delete[] scores;

        // Add the teams matchup to the match
        Match match(teams, highest);

        matches.push_back(match);

    }

	// Go through some of the matches
	std::cout << "Process finished with " << matches.size() << " possible match candidates" << std::endl;

    // Sort
    struct sort_key {
        inline bool operator() (const Match & m1, const Match & m2) {
            return (m1.getTolerance() < m2.getTolerance());
        }
    };

    std::sort(matches.begin(), matches.end(), sort_key());

    // Loop through
    for(int i = 0; i < 50; i++) {
        std::cout << "Match #" << (i + 1) << " (Tolerance: " << matches[i].getTolerance() << ")" << std::endl;
        for(int k = 0; k < matches[i].getTeams().size(); k++) {
            std::cout << "Team #" << (k + 1) << " (Skill: " << matches[i].getTeams()[k].getSkill() << "): ";
            for(int l = 0; l < matches[i].getTeams()[k].getPlayerSize(); l++) {
                std::cout << _names[matches[i].getTeams()[k].getPlayer(l)] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

    }
}
