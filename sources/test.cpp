#include "../headers/EasyRand.h"
#include <iostream>

using namespace EasyRand;
using namespace std;

int main() {
    cout << Random::randInt() << "\n";
    cout << Random::randBool() << "\n";
    cout << Random::randReal() << "\n";
    cout << Random::randInt(31,33) << "\n";
    cout << Random::randReal(31.1, 31.9) << "\n";
    return 0; 
}