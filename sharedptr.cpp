#include <iostream>
#include <memory>

using namespace std;

class SharedExample {
public:
    int a;
    SharedExample(int a):a(a) {
        cout << "Constructor" << endl;
    }
    ~SharedExample() {
        cout << "Destructor" << endl;
    }
    void display() {
        cout << "In Function : " << a<<endl;
    }
};

int main() {
    shared_ptr<SharedExample> sharedPtr1 = make_shared<SharedExample>(55);
    sharedPtr1->display();
    
    {
        // Create another shared pointer that shares ownership
        shared_ptr<SharedExample> sharedPtr2 = sharedPtr1;
        sharedPtr2->a=44;
        sharedPtr2->display();
        sharedPtr1->display();
        cout << "Reference Count: " << sharedPtr1.use_count() << endl; // Should be 2
    } // sharedPtr2 goes out of scope here

    cout << "Reference Count after sharedPtr2 goes out of scope: " << sharedPtr1.use_count() << endl; // Should be 1

    shared_ptr<SharedExample> sharedPtr3 = make_shared<SharedExample>(33);
    cout << "Reference Count : " << sharedPtr3.use_count() << endl;
    shared_ptr<SharedExample> sharedPtr4 = sharedPtr1;
    cout << "Reference Count " << sharedPtr4.use_count() << endl;
    shared_ptr<SharedExample> sharedPtr5 = sharedPtr4;
    cout << "Reference Count " << sharedPtr5.use_count() << endl;

    return 0;
}