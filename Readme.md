# EasyRand

More common randomization algorithms like `rand()` and `srand()`, have some problems, as it was pointed out [here](https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful) by Stephan T. Lavavej (Visual Studio C++ STL).

So, to solve those problems (at least, some of them),  utilities from `random` library are used. A simple way to generate random numbers that don't suffer from those problems can be been implemented using just `random_device`, but it is not [very efficient](https://en.cppreference.com/w/cpp/numeric/random/random_device) when it need to be called multiple times. 

As it is suggested on the _cppreference_ website, a better random implementation uses `random_device` as a seed for a PRNG(pseudo-random number generator), such as `mt19937`. This library implements this kind of algorithm.

## Algorithms

The only difference between the algorithms is the range of the numbers generated.

The coin flip algorithm works this way:

1. Generate a TRUE random number using `random_device`
2. Generate all numbers with a PRNG, that has that true random number used as a seed (`mt19937`)
3. Use a uniform number distribution that produces random numbers only in a closed interval (`uniform_int_distribution<int32_t>`).

For this specific case, the algorithm produces integers with value of 0 or 1. The `flip` function will return this numbers, converted into booleans (0 to `false`, 1 to `true`).

## Reference

**Generating random numbers in C++** - [link](https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c)
