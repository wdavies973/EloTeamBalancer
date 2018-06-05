//
// Created by Will Davies on 6/4/2018.
//

#ifndef ELOTEAMBALANCER_BASEX_H
#define ELOTEAMBALANCER_BASEX_H
#include <string>

class BaseX {
public:
    BaseX(int base, int length, int minPlayersPerTeam, int maxPlayersPerTeam);
    BaseX() = delete;
    ~BaseX();
    void increment();
    float getMaxValue();
    std::string toString();
private:
    int _base;
    int _length;
    int _minPlayersPerTeam;
    int _maxPlayersPerTeam;
    int* _number;
    bool isValid();
};


#endif //ELOTEAMBALANCER_BASEX_H
