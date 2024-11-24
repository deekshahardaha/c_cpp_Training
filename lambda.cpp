#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use a lambda to print all even numbers
    cout << "Even numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        if (n % 2 == 0) {
            cout << n << " ";
        }
    });
    cout << endl;

    // Use a lambda to calculate the sum of all numbers
    int sum = 0;
    for_each(numbers.begin(), numbers.end(), [&sum](int n) {
        sum += n;
    });
    cout << "Sum of all numbers: " << sum << endl;

    // Use a lambda to count how many numbers are greater than 5
    int count = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 5;
    });
    cout << "Count of numbers greater than 5: " << count << endl;

    return 0;
}