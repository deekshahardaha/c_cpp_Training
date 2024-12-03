#include <iostream>
#include <set>

using namespace std;

int main36() {

    multiset<int> myMultiset;

    myMultiset.insert(5);
    myMultiset.insert(1);
    myMultiset.insert(3);
    myMultiset.insert(5); // Duplicate element

    myMultiset.insert(2);

    cout << "Elements in the multiset: ";
    for (const int& num : myMultiset) {
        cout << num << " ";
    }
    cout << endl;

    // Count occurrences of a specific element
    int count = myMultiset.count(5);
    cout << "Count of 5: " << count << endl;

    return 0;
}