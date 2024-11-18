#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Forward declaration of the implementation class
class MyClassImpl;

// Interface class
class MyClass {
public:
    MyClass(); 
    ~MyClass(); 

    void setName(const string& name);
    string getName() const;

private:
    unique_ptr<MyClassImpl> pImpl; // Pointer to implementation
};

// Implementation class definition
class MyClassImpl {
public:
    string name; // Actual data member
};

// Constructor
MyClass::MyClass() : pImpl(make_unique<MyClassImpl>()) {}

// Destructor
MyClass::~MyClass() = default; 


void MyClass::setName(const string& name) {
    pImpl->name = name;
}

string MyClass::getName() const {
    return pImpl->name;
}

int main() {
    MyClass myObject;
    myObject.setName("JKHKIUHJ");
    cout << "Name: " << myObject.getName() << endl;
    return 0;
}