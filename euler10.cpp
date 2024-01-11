#include <iostream>
#include <vector>
using namespace std;

int main() {
    long int prime_sum = 5;
    int end = 2000000;
    // Establish a sample size of dividends
    vector<int> dividends = {2, 3}; 
    int dividend_limit = 7;
    int true_dividend_limit = 500;
    int i = 1;
    int biggest_prime = 0;
    while (biggest_prime < end) { 
        // Establish prime candidacy
        vector<int> candidates = {
            (6 * i) - 1, 
            (6 * i) + 1 
        };
        for (const int& j : candidates) {
            if (dividend_limit > 0) {
                dividends.push_back(j);
                dividend_limit--;
            } else {
                bool truly_prime = true;
                for (const int& dividend : dividends) {
                    truly_prime = (truly_prime && (j % dividend != 0));
                    if (!truly_prime)
                        break;
                }
                if (!truly_prime)
                    continue;
            }
            biggest_prime = j;
            if (biggest_prime >= end)
                break;
            if (true_dividend_limit - dividend_limit > 0) {
                dividends.push_back(j); 
                true_dividend_limit--;
            }
            prime_sum += j;
            cout << j << " is prime." << endl;
        }
        i++;
    }
    cout << prime_sum << endl;
}