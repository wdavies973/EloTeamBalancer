//
// Created by Will Davies on 6/4/2018.

/*
 *  Several optimizations can be used:
 *  1) Every number has a compliment, that is, the number that adds to the full base. So in Base3, the compliment
 *  of 1001 would be 1221 because when added together they equal 2222, the threshold line would be halfway between the
 *  values, so only half of the max value needs to be checked. So basically, the number can be stopped at half the base (1111).
 *
 *  0000
 *  1222 2111
 *  1000 2333
 *
 *  3333
 *
 */

//

#include <iostream>
#include "BaseX.h"

BaseX::BaseX(int base, int length, int minPlayersPerTeam, int maxPlayersPerTeam) {
    _base = base;
    _length = length;
    _minPlayersPerTeam = minPlayersPerTeam;
    _maxPlayersPerTeam = maxPlayersPerTeam;
    _number = new int[length];

    // initialize
    _number[0] = 0;
    _number[1] = 0;
    _number[2] = 0;
    _number[3] = 0;
    for(int i = 0; i < length; i++) {
        _number[i] = 0;
    }
}

void BaseX::increment() {
    _number[_length - 1]++;

    // Fix any numbers higher than the base
    for(int i = _length - 1; i >= 0; i--) {
        if(_number[i] == _base) {
            _number[i] = 0;
            _number[i - 1]++;
        } else break;
    }
}

std::string BaseX::toString() {
    for(int i = 0; i < _length; i++) {
        std::cout << _number[i];
    }
    std::cout << std::endl;
    return std::string();
}

bool BaseX::isValid() {
    return false;
}

BaseX::~BaseX() {
    delete[] _number;
}

float BaseX::getMaxValue() {
    int max[] = {0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3};

    float sum = 0;
    float weight = 1;

    for(int i = _length - 1; i >= 0; i--) {
        sum += weight * max[i];
        weight *= _base;
    }

    return sum;
}
