
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/edbe51a388274689a22a1cc714b4aff1)](https://app.codacy.com/app/gramanicu/EasyRand?utm_source=github.com&utm_medium=referral&utm_content=gramanicu/EasyRand&utm_campaign=Badge_Grade_Dashboard)
# EasyRand &middot; [![Build Status](https://travis-ci.com/gramanicu/EasyRand.svg?branch=master)](https://travis-ci.com/gramanicu/EasyRand) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)


More common randomization algorithms like `rand()` and `srand()`, have some problems, as it was pointed out [here](https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful) by Stephan T. Lavavej (Visual Studio C++ STL).

So, to solve those problems (at least, some of them),  utilities from `random` library are used. A simple way to generate random numbers that don't suffer from those problems can be been implemented using just `random_device`, but it is not [very efficient] when it need to be called multiple times (as pointed out in its documentation on cppreference).

As it is suggested on [cppreference](https://en.cppreference.com/w/cpp/numeric/random/random_device), a better random implementation uses `random_device` as a seed for a PRNG (pseudo-random number generator), such as `mt19937`. This library implements this kind of algorithm.

## Algorithm

1. Generate a TRUE random number using `random_device`
2. Generate all numbers with a PRNG, that has that true random number used as a seed (`mt19937`)
3. Use a uniform number distribution that produces random numbers only in a closed interval (ex. `uniform_int_distribution<int32_t>`).

## Functions

There are 5 publicly exposed functions:

1. randBool() - returns a randomly generated boolean
2. randInt() - returns a randomly generated integer, with values between 0 and 
3. randInt(int32_t iStart, int32_t iEnd) - returns a randomly generated integer, with values between iStart and IEnd
4. randReal() - returns a randomly generated real number, with values between 0 and
5. randReal(double iStart, double iEnd) - returns a randomly generated real number, with values between iStart and iEnd

## Reference

[Generating random numbers in C++](https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c)
