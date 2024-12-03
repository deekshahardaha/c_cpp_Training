#include <iostream>
#include <utility> // For std::pair
#include <string>
#include <vector>

using namespace std;

int main43() {
    // Creating a pair
    pair<int, string> myPair; // A pair of an integer and a string

    // Assigning values to the pair
    myPair.first = 1;          // Assigning value to the first element
    myPair.second = "Apple";   // Assigning value to the second element

    // Output the values of the pair
    cout << "First: " << myPair.first << endl;
    cout << "Second: " << myPair.second << endl;

    // Creating a pair using the make_pair function
    pair<double, char> anotherPair = make_pair(3.14, 'C');
    pair<double, string> anotherPair1(4567.567,"Deeksha");
    pair<double, char> anotherPair2 = {56.56,'s'};
    pair<double, char> anotherPair3({456.56,'H'});

    // Output the values of the second pair
    cout << "First: " << anotherPair.first << endl;
    cout << "Second: " << anotherPair.second << endl;

    // Using pairs in a vector
    vector<pair<int, string>> fruitBasket;
    fruitBasket.push_back(make_pair(2, "Banana"));
    fruitBasket.push_back(make_pair(5, "Orange"));
    fruitBasket.push_back(make_pair(3, "Grapes"));

    // Output the contents of the vector of pairs
    cout << "Fruit Basket:" << endl;
    for (const auto& fruit : fruitBasket) {
        cout << fruit.first << " " << fruit.second << endl;
    }

    anotherPair2.swap(anotherPair3);
    cout << "First: " << anotherPair2.first << endl;
    cout << "Second: " << anotherPair2.second << endl;
    cout << "First: " << anotherPair3.first << endl;
    cout << "Second: " << anotherPair3.second << endl;

    anotherPair3={23.45,'f'};
    cout << "First: " << anotherPair3.first << endl;
    cout << "Second: " << anotherPair3.second << endl;
    return 0;
}