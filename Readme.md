# EasyRand

More common randomization algorithms like `rand()` and `srand()`, have some problems, as it was pointed out [here](https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful) by Stephan T. Lavavej (Visual Studio C++ STL).

So, to solve those problems (at least, some of them),  utilities from `random` library are used. A simple way to generate random numbers that don't suffer from those problems can be been implemented using just `random_device`, but it is not [very efficient] when it need to be called multiple times (as pointed out in its documentation on cppreference).

As it is suggested on [cppreference](https://en.cppreference.com/w/cpp/numeric/random/random_device), a better random implementation uses `random_device` as a seed for a PRNG (pseudo-random number generator), such as `mt19937`. This library implements this kind of algorithm.

## Algorithm

1. Generate a TRUE random number using `random_device`
2. Generate all numbers with a PRNG, that has that true random number used as a seed (`mt19937`)
3. Use a uniform number distribution that produces random numbers only in a closed interval (ex. `uniform_int_distribution<int32_t>`).

There are actually 3 possible values returned - bool, int, double

## Reference

[Generating random numbers in C++](https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c)
