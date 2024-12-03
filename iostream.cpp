#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main24() {
    vector<int> numbers;
    int input;

    // Using istream (std::cin) to read input
    cout << "Enter integers (type -1 to end):" << endl;

    // Read integers from standard input until -1 is entered
    while (true) {
        cin >> input;
        if (input == -1) {
            break; // Exit on -1
        }
        numbers.push_back(input);
    }

    // Using ostream (std::cout) to output the numbers
    cout << "You entered the following numbers:" << endl;

    // Using output iterator to print the numbers
    // for (ostream_iterator<int> out_it(cout, " "), it = numbers.begin(); it != numbers.end(); ++it) {
    //     *out_it = *it; // Write each number to the output stream
    // }

    // Using output iterator to print the numbers
    ostream_iterator<int> out_it(cout, " "); 
    copy(numbers.begin(), numbers.end(), out_it);
    
    cout << endl;


    

    return 0;
}