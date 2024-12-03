#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;

class MyClassS {
public:
    MyClassS(const string& name) : name(name) {
        cout << "MyClass constructor called for: " << name << endl;
    }

    ~MyClassS() {
        cout << "MyClass destructor called for: " << name << endl;
    }

    void greet() const {
        cout << "Hello from " << name << "!" << endl;
    }

private:
    string name;
};

// Custom deleter for MyClass
void customDeletercls(MyClassS* p) {
    cout << "Custom deleter called for MyClass instance." << endl;
    delete p; 
}

struct MyStruct {
    int value;
    MyStruct(int val) : value(val) {}
};

// Custom deleter function
void customDeleter2(int* p) {
    cout << "Custom deleter called for: " << *p << endl;
    delete p; 
}

int main7() {
    auto customDeleter1 = [](MyStruct* ptr) {
        cout << "Deleting MyStruct with value: " << ptr->value << endl;
        free(ptr);
    };

    unique_ptr<MyStruct, decltype(customDeleter1)> ptr(static_cast<MyStruct*>(malloc(sizeof(MyStruct))), customDeleter1);

    new (ptr.get()) MyStruct(33);

    cout << "MyStruct value: " << ptr->value << endl;

    // ======================================================================= //
    {
    shared_ptr<int> ptr1(new int(44), customDeleter2);

    cout << "Value: " << *ptr1 << endl;

    }
    // ======================================================================= //

    // Create a shared_ptr with a lambda as a custom deleter
    shared_ptr<int> ptr2(new int(22), [](int* p) {
        cout << "Custom deleter called for: " << *p << endl;
        delete p; 
    });

    cout << "Value: " << *ptr2 << endl;


    // ======================================================================= //

    shared_ptr<MyClassS> ptr3(new MyClassS("MyObject"), customDeletercls);

    // Use the object
    ptr3->greet();


    // The custom deleter will be called automatically when ptr goes out of scope
    return 0;
}