#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> fib = {0, 1, 1};
    int exceed = 4000000;
    // Sum of even-valued terms
    int sum_even = 0;
    // The Fibonacci Sequence
    while (fib[fib.size() - 1] < exceed) {
        int cur_fib = fib[fib.size() - 1] + fib[fib.size() - 2];
        std::cout << cur_fib << std::endl;
        fib.push_back(cur_fib);
        // Add to the sum if the value is even
        if (cur_fib % 2 == 0)
            sum_even += cur_fib;
    }
    cout << "Sum of all: " << sum_even << endl;
    return 0;
}