#include <chrono>
#include <iomanip>
#include <iostream>
#include "../headers/EasyRand.h"

using namespace EasyRand;
using namespace std;
using namespace std::chrono;

// How many numbers should be tested
#define NUM_OF_VALUES 1000000000

// The upper limit of the interval from which should the numbers be generated
#define MAX_SIZE 250000

// In how many partitions should the dataset be split
// This is used to make the output more readable
#define NUM_OF_PARTITIONS 25

#define SHOW_LOGS true

// At how many numbers should it say the current number of values generated
#define SHOW_LOG_EVERY 500000000

int main() {
    // Test Integer Distribution
    int32_t array[MAX_SIZE] = {0};

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (long long i = 0; i < NUM_OF_VALUES; i++) {
        if (SHOW_LOGS) {
            if (i % SHOW_LOG_EVERY == 0) cerr << "Reached " << i << " values\n";
        }
        int x = Random::randInt(0, MAX_SIZE - 1);
        array[x] += 1;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    int32_t max = INT32_MIN, min = INT32_MAX;
    int32_t imax = -1, imin = -1;
    int32_t partition[NUM_OF_PARTITIONS] = {0};
    long long partitionSize = MAX_SIZE / NUM_OF_PARTITIONS;

    for (int i = 0; i < MAX_SIZE; i++) {
        partition[i / partitionSize] += array[i];
        if (array[i] > max) {
            max = array[i];
            imax = i;
        } else if (array[i] < min) {
            min = array[i];
            imin = i;
        }
    }

    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "- Time taken to generate " << NUM_OF_VALUES
         << " integers : " << duration << "ms ( "
         << duration_cast<seconds>(t2 - t1).count() << " seconds) \n";
    cout << "- Distribution in partitions -\n";
    for (int i = 0; i < NUM_OF_PARTITIONS; i++) {
        cout << "Partition " << i + 1 << " : " << partition[i] << "\n";
    }
    cout << "\nNumber " << imax + 1 << " has appeared most times : " << max
         << "\n";
    cout << "Number " << imin + 1 << " has appeared least times : " << min
         << "\n";

    // Check Error Handling

    cout << "\n - Bad paramaters error test -\n";
    cout << "Equal interval ends (int 1-1) : " << Random::randInt(1, 1) << "\n";
    cout << "Equal interval ends (real 1.01-1.01) : " << fixed
         << Random::randReal(1.01, 1.01) << "\n";
    cout << "Reversed interval ends (int 2000-1000) : "
         << Random::randInt(2000, 1000) << "\n";
    cout << "Reversed interval ends (real 1234.1234-1234.1233) : " << fixed
         << Random::randReal(1234.1234, 1234.1233) << "\n";

    return 0;
}
