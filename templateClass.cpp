/*
Generic Programming: Template classes allow you to write generic and reusable code that can work with any data type.
Type Safety: The compiler checks the types at compile time, which helps catch errors early.
Flexibility: You can create classes that can handle different types without duplicating code.
*/

#include <iostream>
using namespace std;

// Template class definition
template <typename T>
class Box {
private:
    T value; 

public:
    Box(T val) : value(val) {}

    T getValue() const {
        return value;
    }

    void setValue(T val) {
        value = val;
    }
};

int main70() {
    Box<int> intBox(123);
    cout << "Integer Box contains: " << intBox.getValue() << endl;


    Box<double> doubleBox(45.67);
    cout << "Double Box contains: " << doubleBox.getValue() << endl;


    Box<string> stringBox("Hello, Templates!");
    cout << "String Box contains: " << stringBox.getValue() << endl;
    stringBox.setValue("changing value of string .");
    cout << "String Box contains: " << stringBox.getValue() << endl;


    intBox.setValue(456);
    cout << "Updated Integer Box contains: " << intBox.getValue() << endl;

    return 0;
}