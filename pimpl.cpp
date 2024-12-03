#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Forward declaration of the implementation class
class MyClassImpl;

// Interface class
class MyClassD {
public:
    MyClassD(); 
    ~MyClassD(); 

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
MyClassD::MyClassD() : pImpl(make_unique<MyClassImpl>()) {}

// Destructor
MyClassD::~MyClassD() = default; 


void MyClassD::setName(const string& name) {
    pImpl->name = name;
}

string MyClassD::getName() const {
    return pImpl->name;
}

int main45() {
    MyClassD myObject;
    myObject.setName("JKHKIUHJ");
    cout << "Name: " << myObject.getName() << endl;
    return 0;
}