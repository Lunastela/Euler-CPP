#include <iostream>
#include <vector>
using namespace std;

int main() {
    long int my_number = 600851475143;
    // Attempt to find the biggest prime number
    bool biggest_prime_found = false;
    int i = 2;
    while (!biggest_prime_found) {
        // Obtain factors of the main number
        if (my_number % i == 0) {
            long int current_factor = (long int)(my_number / i);
            // Check the current factor to see if it's prime
            bool is_prime = true;
            long int j = 2;
            while (is_prime && j < current_factor) {
                // Break if the current number is not prime
                if (current_factor % j == 0) {
                    is_prime = false;
                    break;
                }
                j++;
            }
            // Return the prime number
            if (is_prime) {
                cout << current_factor << endl;
                break;
            }
        }
        i++;
    }
    return 0;
}