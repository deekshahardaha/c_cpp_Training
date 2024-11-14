#include <iostream>

#include <stdexcept>  // For standard exceptions
 
using namespace std;
 
// Define custom limits

const long long CUSTOM_MAX = 1000000;

const long long CUSTOM_MIN = -1000000;
 
// Level 4 function: Division operation that may throw divide-by-zero exception

void level4Function(int a, int b) {

    try {

        if (b == 0) {

            throw invalid_argument("Cannot divide by zero in level 4");

        }

        int result = a / b;

        cout << "Result of division in level 4: " << result << endl;

    } catch (const invalid_argument& e) {

        cout << "Caught in level4Function (level 4): " << e.what() << endl;

        throw;  

    }

}
 
// Level 3 function: Multiply two numbers, may throw overflow exception

void level3Function(int a, int b) {

    try {

        long long result = static_cast<long long>(a) * b; 

        if (result > CUSTOM_MAX || result < CUSTOM_MIN) {

            throw overflow_error("Multiplication overflow in level 3");

        }

        cout << "Result of multiplication in level 3: " << result << endl;

        level4Function(a, b);

    } catch (const overflow_error& e) {

        cout << "Caught in level3Function (level 3): " << e.what() << endl;

        throw; 

    }

}
 
// Level 2 function: Subtract two numbers, may throw underflow exception

void level2Function(int a, int b) {

    try {

        int result = a - b;

        if (result < 0) {

            throw underflow_error("Subtraction underflow in level 2");

        }

        cout << "Result of subtraction in level 2: " << result << endl;

        level3Function(a, b); 

    } catch (const underflow_error& e) {

        cout << "Caught in level2Function (level 2): " << e.what() << endl;

        // Rethrow the exception

        throw; 

    }

}
 
// Level 1 function: Add two numbers, may throw an exception for invalid input

void level1Function(int a, int b) {

    try {

        if (a < 0 || b < 0) {

            throw invalid_argument("Negative numbers are not allowed in level 1");

        }

        int result = a + b;

        cout << "Result of addition in level 1: " << result << endl;

        level2Function(a, b);  // Call level 2 function to perform subtraction

    } catch (const invalid_argument& e) {

        cout << "Caught in level1Function (level 1): " << e.what() << endl;

        throw;  // Rethrow to main (top level)

    }

}
 
int main() {

    try {

        // Call the innermost function with example values

        level1Function(1000, 0);  // This will trigger no exception

    } catch (const invalid_argument& e) {

        cout << "Caught in main (outer): " << e.what() << endl;

    } catch (const underflow_error& e) {

        cout << "Caught in main (outer): " << e.what() << endl;

    } catch (const overflow_error& e) {

        cout << "Caught in main (outer): " << e.what() << endl;

    } catch (...) {

        // Catch-all for any other exceptions

        cout << "Caught an unknown exception in main" << endl;

    }
 
    return 0;

}

 