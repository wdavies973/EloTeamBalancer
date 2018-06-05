#include <iostream>
#include <vector>
#include <string>
#include "code/BaseX.h"
#include <ctime>

using namespace std;

int main() {

    BaseX baseX(4, 20, 0, 0);

    float maxValue = baseX.getMaxValue();

    cout << "Max value: " << maxValue;

    // started at 8:51 pm

    for(float i = 0; i < maxValue; i++) {
        baseX.increment();
       // baseX.toString();
    }

    baseX.toString();

    time_t current = time(0);
    cout << ctime(&current) << endl;

    return 0;
}
