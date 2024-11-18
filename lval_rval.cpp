#include <iostream>

using namespace std;

void Lvalue(int &x) { // 
    x += 10; 
}

void Rvalue(int &&y) { // Takes an rvalue reference
    y += 5; 
    cout << "Inside Rvalue: " << y << endl;
}

int main() {
    int a = 10; // a is an lvalue
    Lvalue(a); // Pass an lvalue to the function
    cout << "After Lvalue: " << a << endl; // Outputs: 20

    // Rvalue(a);// error(an rvalue reference cannot be bound to an lvalue)
    Rvalue(34); // Pass an rvalue (temporary) to the function
    // Note: We cannot do processRvalue(a); because a is an lvalue

    return 0;
}