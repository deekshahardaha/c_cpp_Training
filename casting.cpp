#include <iostream>
#include <typeinfo>

using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class" << endl; } // Virtual function
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class" << endl; }
};

int main() {

    double a = 10.5;
    int b = (int)a; // C-style cast
    cout << "C-style cast: " << b << endl; // Output: 10

    // Static casting
    Base* basePtr = new Derived(); // Upcasting (from Derived to Base) 
    Derived* derivedPtr = static_cast<Derived*>(basePtr); // Downcasting  (from Base to Derived)
    derivedPtr->show(); // Output: Derived class

    // Const casting
    const int x = 42;
    const int* constPtr = &x;
    int* modifiablePtr = const_cast<int*>(constPtr); // Remove constness
    *modifiablePtr ++; // Undefined behavior, but for demonstration
    cout << "Const cast (undefined behavior): " << x << endl; // Output may vary

    // Dynamic casting
    Base* basePtr2 = new Base(); // Base class object
    Derived* derivedPtr2 = dynamic_cast<Derived*>(basePtr2); // Attempt to downcast
    if (derivedPtr2) {
        derivedPtr2->show(); // This won't execute
    } else {
        cout << "Dynamic cast failed: basePtr2 is not a Derived object." << endl; // Output this line
    }

    // Reinterpret casting
    int num = 65;
    char* charPtr = reinterpret_cast<char*>(&num); // Cast int* to char*
    cout << "Reinterpret cast: " << *charPtr << endl; // Output may vary based on system (ASCII value)

    // Clean up
    delete basePtr; // Clean up derived object
    delete basePtr2; // Clean up base object

    return 0;
}