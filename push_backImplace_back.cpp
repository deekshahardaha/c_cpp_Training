/*
push_back calls the copy constructor or the move constructor during the operation.
emplace_back does not call any hence better to use.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClass {
public:
    string b;
    MyClass( const string& b) :b(b) {
        cout << "MyClass constructed: "  << b << endl;
    }
    MyClass(const MyClass &curr) :b(curr.b){
        cout << "Copy constructed: " << b << endl;
    }
    MyClass(MyClass &&curr):b(move(curr.b))  {
        cout << "Move constructed: " << b << endl;
    }

};

int main() {
    vector<MyClass> vec;

    // Using push_back
    MyClass obj1("Object1");
    vec.push_back(obj1);
    vec.push_back(MyClass("obj5")); // Copies obj1 into the vector

    // Using emplace_back
    vec.emplace_back("Object2"); // Constructs directly in the vector

    return 0;
}