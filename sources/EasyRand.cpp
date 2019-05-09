#include "../headers/EasyRand.h"
#include <float.h>

using namespace EasyRand;

bool Random::initialised = false;
std::mt19937 Random::generator;
std::uniform_int_distribution<int32_t> Random::booldistribution;
std::uniform_int_distribution<int32_t> Random::distribution;
std::uniform_real_distribution<double> Random::realdistribution;

void Random::seed() {
    booldistribution = std::uniform_int_distribution<int32_t>(0,1);
    distribution = std::uniform_int_distribution<int32_t>();
    realdistribution = std::uniform_real_distribution<double>(0, DBL_MAX);
    std::random_device rDevice;
    generator = std::mt19937(rDevice());
    initialised = true;
}

bool Random::randBool() {
    if (!initialised) {
        seed();
    }
    int32_t random = booldistribution(generator);
    if (random == 1) {
        return true;
    } else {
        return false;
    }
}

int32_t Random::randInt() {
    if (!initialised) {
        seed();
    }
    int32_t random = distribution(generator);
    return random;
}

double Random::randReal() {
    if (!initialised) {
        seed();
    }
    double random = realdistribution(generator);
    return random;
}