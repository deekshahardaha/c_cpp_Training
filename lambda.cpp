#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main25() {

    auto add = [](int a, int b) {
        return a + b;
    };

    cout << "Sum: " << add(5, 3) << endl; 

    //==============================================//

    int x1 = 10;
    auto lambda1 = [x1]() {
        cout << "Captured by value: " << x1 << endl;
    };
    lambda1(); 
    x1 = 20;   
    lambda1();

    //==============================================//

    int x2 = 10;
    auto lambda2 = [&x2]() {
        x2 += 5; 
        cout << "Captured by reference: " << x2 << endl;
    };
    lambda2(); 
    cout << "Outside lambda: " << x2 << endl; 

    //==============================================//

    vector<int> numbers = {41, 32, 3, 64, 35, 6, 7, 98, 9, 10};

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b; // Sort in ascending order
    });

    cout << "Sorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl; 

    //==============================================//

    auto apply = [](auto func, int value) {
        return func(value);
    };

    auto square = [](int x) {
        return x * x;
    };

    cout << "Square of 5: " << apply(square, 5) << endl;

    //==============================================//

    //By default, lambdas capture variables as const. If you need to modify captured variables, you can use the "mutable" keyword.

    int x3 = 10;
    auto lambda = [x3]() mutable {
        x3 += 5;
        cout << "Inside lambda: " << x3 << endl;
    };
    lambda();
    cout << "Outside lambda: " << x3 << endl; 

    //==============================================//

    // Use a lambda to print all even numbers
    cout << "Even numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        if (n % 2 == 0) {
            cout << n << " ";
        }
    });
    cout << endl;

    //==============================================//

    // Use a lambda to calculate the sum of all numbers
    int sum = 0;
    for_each(numbers.begin(), numbers.end(), [&sum](int n) {
        sum += n;
    });
    cout << "Sum of all numbers: " << sum << endl;

    //==============================================//

    // Use a lambda to count how many numbers are greater than 35
    int count = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 5;
    });
    cout << "Count of numbers greater than 35: " << count << endl;

    

    return 0;
}