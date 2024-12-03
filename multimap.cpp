#include <iostream>
#include <map>

using namespace std;

int main35() {
    // Create a multimap of string keys and integer values
    multimap<string, int> myMultimap;

    // Insert key-value pairs into the multimap
    myMultimap.insert({"apple", 1});
    myMultimap.insert({"banana", 2});
    auto var =myMultimap.insert({"apple", 3}); // Duplicate key
    cout<<var->first<<" "<<var->second<<endl;
    myMultimap.insert({"orange", 4});
    myMultimap.insert({"banana", 5}); // Duplicate key

    // Display the elements in the multimap
    cout << "Elements in the multimap:" << endl;
    for (const auto& pair : myMultimap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Count occurrences of a specific key
    int bananaCount = myMultimap.count("banana");
    cout << "Count of 'banana': " << bananaCount << endl;

    return 0;
}