#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    bitset<8> b1; 
    cout << "Initial bitset b1: " << b1 << endl;

    // Set the bit at index 1 and 3 to 1
    b1.set(1); 
    b1.set(3);
    cout << "set bits 1 and 3: " << b1 << endl;

    // Reset a bit
    b1.reset(1); 
    b1.reset(4); //will do nothing
    cout << "resetting  1: " << b1 << endl;

    // Flip a bit
    b1.flip(3); 
    cout << " flipping 3: " << b1 << endl;

    // Check if a bit is set
    cout << " index 3 set? : " << (b1.test(3) ? "Yes" : "No") << endl;

    // Convert to string
    string bitString = b1.to_string();
    cout << "Bitset as string: " << bitString << endl;

    // Create a bitset from a string
    bitset<8> b2("11001010");
    cout << "Bitset b2 from string: " << b2 << endl;

    // Convert to unsigned long
    unsigned long num = b2.to_ulong();
    cout << "Bitset b2 as unsigned long: " << num << endl;

    cout<<"no of set bits in b2 : "<<b2.count() << endl;

    cout <<"checks if all 1's : "<< b2.all() << endl;

    cout << "checks if 4 is set : " << b2.test(4) << endl;
    cout << "checks if 3 is set : " << b2.test(3) << endl;

    cout << "checks if any bit is set : " << b2.any() << endl;


    return 0;
}