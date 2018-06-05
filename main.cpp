#include <iostream>
#include <vector>
#include <string>
#include "code/BaseX.h"
#include "models/Match.h"
#include "code/MatchFinder.h"
#include <ctime>
#include <algorithm>

using namespace std;

int main() {

    // Define the sorting structure
    struct sort_key {
        inline bool operator() (const Match & m1, const Match & m2) {
            return (m1.getTolerance() < m2.getTolerance());
        }
    };

    std::vector<string> names;
    names.emplace_back("Nate");
    names.emplace_back("Will");
    names.emplace_back("Ethan");
    names.emplace_back("Daniel");
    names.emplace_back("Charlie");
    names.emplace_back("Ian");
    names.emplace_back("IsaacM");
    names.emplace_back("IsaacF");
    names.emplace_back("Avery");
    names.emplace_back("Jake");
    names.emplace_back("Zach");
    names.emplace_back("Joe");
    names.emplace_back("August");
    names.emplace_back("Peter");
    names.emplace_back("Kyle");
    names.emplace_back("Kaan");
    names.emplace_back("Dawson");
    names.emplace_back("Josh");
    names.emplace_back("Jesse");
    names.emplace_back("George");
    //names.emplace_back("Adam");

    std::vector<int> playerSkills;
    playerSkills.push_back(4000);
    playerSkills.push_back(2000);
    playerSkills.push_back(4000);
    playerSkills.push_back(1500);
    playerSkills.push_back(3000);
    playerSkills.push_back(3250);
    playerSkills.push_back(2500);
    playerSkills.push_back(1750);
    playerSkills.push_back(1000);
    playerSkills.push_back(1200);
    playerSkills.push_back(500);
    playerSkills.push_back(1500);
    playerSkills.push_back(1000);
    playerSkills.push_back(1000);
    playerSkills.push_back(2000);
    playerSkills.push_back(2500);
    playerSkills.push_back(3500);
    playerSkills.push_back(2500);
    playerSkills.push_back(1500);
    playerSkills.push_back(3500);
    //playerSkills.push_back(2000);

    cout << names.size() << " " << playerSkills.size() << endl;


    MatchFinder finder(names, playerSkills, 20, 3, 5, 4);
	finder.compute();


/*
    BaseX baseX(4, 12, 0, 0); // must be factors of each other

    long long maxValue = baseX.getMaxValue();

    cout << "Max value: " << maxValue << endl;

    baseX.toString();

    // started at 1:08 pm
    for(long long i = 0; i < maxValue; i++) {
        baseX.increment();
        //baseX.toString();*
        if(i % (100000000) == 0) {
            cout << "Progress: " << (double(i) / double(maxValue) * 100.0) << "%" << endl;
        }
    }

    baseX.toString();

    time_t current = time(0);
    cout << ctime(&current) << endl;

    //std::vector yeet;
    //std::sort(yeet.begin(), yeet.end(), sort_key());
*/
    return 0;
}
