#include <iostream>
#include <memory>

using namespace std;

class UniqueExample {
public:
    UniqueExample() {
        cout << "Constructor" << endl;
    }
    ~UniqueExample() {
        cout << "Destructor" << endl;
    }
    void display() {
        cout << "In Function" << endl;
    }
};

int main74() {
    unique_ptr<UniqueExample> uniquePtr = make_unique<UniqueExample>();
    uniquePtr->display();

    unique_ptr<UniqueExample> uniquePtr2;
    // uniquePtr2=uniquePtr;    //cannot be referenced 
    
    uniquePtr2=std::move(uniquePtr);
    uniquePtr2->display();

    // No need to manually delete; it will be automatically deleted when it goes out of scope
    return 0;
}