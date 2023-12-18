#include <iostream>
#include <vector>
using namespace std;

vector<int> get_multiples_of_number(int number, int limit = 10) {
    vector<int> multiples = {};
    int multiplier = 1;
    // Loop through all possible multiples of the number until the limit.
    while (multiplier * number < limit) {
        // Add the number to the list and increment the multiplier.
        multiples.push_back(multiplier * number);
        multiplier++;
    }
    // Return the multiples of the number.
    return multiples;
}

int main() {
    int num1 = 3;
    int num2 = 5;
    int lim = 1000;
    
    // Get the multiples of each number up to a specific number.
    vector<int> vec = get_multiples_of_number(3, lim);
    vector<int> vec2 = get_multiples_of_number(5, lim);

    // Combine the vectors into a singular one.
    std::vector<int> combined_vector = vec;
    combined_vector.insert(combined_vector.end(), vec2.begin(), vec2.end());

    // Create a final value for the combination of all numbers.
    int final_value = 0;
    for (const int& i : combined_vector) 
        final_value += i;
    cout << "The sum of all multiples of " << num1 << " and " << num2 << " below " << lim << " is " << final_value << "." << endl;
}