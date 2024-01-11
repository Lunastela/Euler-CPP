#include <iostream>
#include <vector>
using namespace std;

bool ensure_divisibility(long int factorial, int max_limit) {
    bool divisible = false;
    for (int i = 1; i <= max_limit; i++) {
        divisible = (factorial % i == 0);
        if (!divisible)
            break;
    }
    return divisible;
}

int main() {
    // Get the factorial of the number
    int max_limit = 20;
    long int factorial = 1;
    for (int i = 1; i <= max_limit; i++)
        factorial *= i;
    // The interval to divide the factorial by
    int division_interval = 1;
    // Whether or not we have tried all possible divisions
    bool rotated_through = false;
    int amount_failed = 0; // The amount of divisions that have failed in a row
    while (!rotated_through) {
        division_interval = (division_interval + 1) % (max_limit + 1);
        if (division_interval == 0 || division_interval == 1)
            continue;
        if (ensure_divisibility(factorial / division_interval, max_limit)) {
            factorial = factorial / division_interval;
            amount_failed = 0;
        } else {
            amount_failed++;
            if (amount_failed >= max_limit - 2)
                rotated_through = true;
        }
    }
    cout << factorial << endl;
}