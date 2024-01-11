#include <iostream>
using namespace std;

int main() {
    // Establish the limit of numbers
    int num_lim = 100;
    // Get the square of the sum of the limit of numbers
    long int sum_square = 0;
    for (int i = 1; i <= num_lim; i++)
        sum_square += i;
    sum_square = sum_square * sum_square;
    // Get the sum of the squares of the limit of numbers
    long int square_sum = 0;
    for (int i = 1; i <= num_lim; i++)
        square_sum += (i * i);
    // Subtract the sum from the square
    sum_square -= square_sum;
    cout << "The sum of the squares from 1 to " << num_lim << " subtracted from the square of the sum of the same is: " << sum_square << endl;
}