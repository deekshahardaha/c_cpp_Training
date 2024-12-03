#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Functor for addition
class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

// Functor for subtraction
class Subtract {
public:
    int operator()(int a, int b) {
        return a - b;
    }
};

// Functor for multiplication
class Multiply {
public:
    int operator()(int a, int b) {
        return a * b;
    }
};

// Functor for division
class Divide {
public:
    int operator()(int a, int b) {
        if (b == 0) {
            throw invalid_argument("Division by zero");
        }
        return a / b;
    }
};


// Functor for less than comparison
class LessThan {
public:
    bool operator()(int a, int b) {
        return a < b;
    }
};

// Functor for greater than comparison
class GreaterThan {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

// Functor for equality comparison
class Equal {
public:
    bool operator()(int a, int b) {
        return a == b;
    }
};

int main20() {
    int x = 10;
    int y = 5;

    Add add;
    Subtract subtract;
    Multiply multiply;
    Divide divide;
    LessThan lessThan;
    GreaterThan greaterThan;
    Equal equal;

    cout << "Addition: " << add(x, y) << endl;         // Output: 15
    cout << "Subtraction: " << subtract(x, y) << endl; // Output: 5
    cout << "Multiplication: " << multiply(x, y) << endl; // Output: 50
    cout << "Division: " << divide(x, y) << endl;     // Output: 2
    cout << "Is x less than y? " << (lessThan(x, y) ? "Yes" : "No") << endl; // Output: No
    cout << "Is x greater than y? " << (greaterThan(x, y) ? "Yes" : "No") << endl; // Output: Yes
    cout << "Is x equal to y? " << (equal(x, y) ? "Yes" : "No") << endl; // Output: No

    return 0;
}