#include <iostream>
using namespace std;

class cl1 {
private:
    int value;
    static int stval;
public:
    cl1(int value) {
        this->value = value; // Using 'this' to resolve naming conflict
    }

    void display() {
        cout << "Value: " << this->value << endl;
    }

    // Method to compare the current object with another object
    bool isEqual(const cl1& other) {
        return this->value == other.value; // Compare using 'this'
    }

    static void staticFunction() {
        // cout << this->value; // Error: 'this' may only be used inside a nonstatic member function
        cout << "This is a static function." << endl;
        cout<<"static value inside static function : "<<stval<<endl;       
    }
};

int cl1::stval=33;

int main() {
    cl1 obj1(10);
    obj1.display();
    cl1 obj2(20);
    obj2.display();

    // Compare obj1 and obj2
    cout << "obj1 and obj2 are equal: " << obj1.isEqual(obj2) << endl;

    obj2.staticFunction();
    return 0;
}