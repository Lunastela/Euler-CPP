#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Approximating Prime Numbers
    int i = 1;
    int true_increment = 0;
    int prime_limit = 10001;
    // Establish a vector of numbers to divide by
    vector<int> dividends = {2, 3}; 
    // The idea here is that all composite numbers are made up of primes, therefore every divisible number is divisible by some prime
    int dividend_limit = 7; // Blindly trust the first 7 "prime numbers" are actually prime
    int true_dividend_limit = 100; // The "true" sample size of numbers that the program will divide by
    while (true_increment < prime_limit - 2) { // 2 numbers are already in the prime list
        // Establish prime candidacy
        vector<int> candidates = {(6 * i) - 1, (6 * i) + 1 };
        // cout << candidates[0] << " or " << candidates[1] << endl;
        for (const int& i : candidates) {
            if (dividend_limit > 0) {
                dividends.push_back(i);
                dividend_limit--;
            } else {   
                bool truly_prime = true;
                for (const int& dividend : dividends)
                    truly_prime = (truly_prime && (i % dividend != 0));
                if (!truly_prime)
                    continue;
                else {
                    if (true_dividend_limit - dividend_limit > 0) {
                        dividends.push_back(i); 
                        true_dividend_limit--;
                    }
                    cout << i << " is prime." << endl;
                }
            }
            // Increment if it is truly a prime value
            true_increment++;
        }
        i++;
    }
}