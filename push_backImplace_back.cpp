/*
push_back calls the copy constructor or the move constructor during the operation.
emplace_back does not call any hence better to use.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClassS {
public:
    string b;
    MyClassS( const string& b) :b(b) {
        cout << "MyClass constructed: "  << b << endl;
    }
    MyClassS(const MyClassS &curr) :b(curr.b){
        cout << "Copy constructed: " << b << endl;
    }
    MyClassS(MyClassS &&curr):b(move(curr.b))  {
        cout << "Move constructed: " << b << endl;
    }

};

int main50() {
    vector<MyClassS> vec;

    // Using push_back
    MyClassS obj1("Object1");
    vec.push_back(obj1);
    vec.push_back(MyClassS("obj5")); // Copies obj1 into the vector

    // Using emplace_back
    vec.emplace_back("Object2"); // Constructs directly in the vector

    return 0;
}