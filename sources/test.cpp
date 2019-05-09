#include "../headers/EasyRand.h"
#include <iostream>

using namespace EasyRand;
using namespace std;

int main() {
    cout << Random::randInt() << "\n";
    cout << Random::randBool() << "\n";
    cout << Random::randReal() << "\n";
    return 0; 
}