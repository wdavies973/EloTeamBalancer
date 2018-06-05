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
#include <math.h>
#include "BaseX.h"

BaseX::BaseX(int base, int length, int minPlayersPerTeam, int maxPlayersPerTeam) : _length(length) {
    _base = base;
    _minPlayersPerTeam = minPlayersPerTeam;
    _maxPlayersPerTeam = maxPlayersPerTeam;
    _number = new int[length];

    // initialize
    for(int i = 0; i < length; i++) {
       _number[i] = 0;
    }

    _number[0] = 2;
}

void BaseX::increment() {
    _number[_length - 1]++;

    // Fix any numbers higher than the base
    for(int i = _length - 1; i > 0; i--) {
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
    //std::cout << std::endl;
    return std::string();
}

bool BaseX::isValid() {
    return false;
}

BaseX::~BaseX() {
    delete[] _number;
}

/**
 * The maximum value of this number is not (base-1)E_length.
 * Because a base x number increment will cover every possible
 * number combination, it will run into duplicates or scenarios
 * were the teams are the same in essence, but called names.
 * To avoid these scenarios, we set the maximum value to an
 * even distribution of digits, starting at 0 to the base - 1
 * number. Theoretically, this should cover every possibility still
 * while reducing the number of tries down by several orders of
 * magnitude.
 *
 * @return the number of times increment() should be called to produce every possible combination
 */
long long BaseX::getMaxValue() {
    int distribution = _length / _base;

    auto * max = new int[_length];

    for(int i = 0, val = 0; i < _length; i++) {
        max[i] =  val;
        if(i != 0 && (i + 1) % distribution == 0) val++;
    }

    long long sum = 0;
    long long weight = 1;

    for(int i = _length - 1; i >= 0; i--) {
        sum += weight * long long(max[i]);
        weight *= _base;
    }

    delete[] max;

    return 549755813888 - 10;
}

int BaseX::getDigit(int index) {
    return _number[index];
}
