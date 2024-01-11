#include <iostream>
#include <numbers>
#include <vector>
#include <math.h>
using namespace std;

bool number_is_palindrome(int palindrome) {
    // Get the number as a string
    string string_palindrome = to_string(palindrome);
    bool is_palindrome = true;
    for (int i = 0; i < (string_palindrome.length() / 2); i++)
        is_palindrome = (is_palindrome && (string_palindrome[i] == string_palindrome[string_palindrome.length() - (i + 1)]));
    return is_palindrome;
}

// Absolute mess, but it "works"
int main() {
    int digit_amount = 3;
    int starting_number = pow(10, digit_amount) - 1;
    int multiplicable = starting_number;
    int scale = pow(10, digit_amount - 1) - 1;
    int increment = 0;
    bool found_palindrome = false;
    while (!found_palindrome) {
        cout << starting_number * multiplicable << " of multiples " << starting_number << " and " << multiplicable << endl;
        // Figure out which number to subtract from if the number is not a palindrome yet
        for (int i = 0; i < scale; i++) {
            if (number_is_palindrome(starting_number * (multiplicable - i))) {
                multiplicable -= i;
                found_palindrome = true;
                break;
            }
        }
        if (!found_palindrome)
            starting_number--;
    }
    cout << starting_number * multiplicable << " of multiples " << starting_number << " and " << multiplicable << endl;
}