// Copyright Grama Nicolae 2019
#ifndef HEADERS_RANDOM_H_
#define HEADERS_RANDOM_H_

#include <stdint.h>
#include <random>

namespace EasyRand {
  class Seed {
    private:
      static bool initialized;
      static std::mt19937 generator;
      static std::uniform_int_distribution<int32_t> distribution;
      static std::uniform_real_distribution<double> realdistribution;

      static void seed() {

      };

      Seed() = delete;

    public:
      static int32_t randInt() {

      };

      static double randReal() {
        
      };

      static bool randBool() {

      };
  };

}
#endif  // HEADERSOM_H_