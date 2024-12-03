#include <iostream>
#include <string>

using namespace std;


// 1. Typedef for inbuilt data types
typedef string str;               


// 2. function
typedef void (*FunctionPtr)(int); //function that takes an int and returns void

// 3. User-defined data types
struct Point {
    int x;
    int y;
};

typedef Point MyPoint; 

class MyClassS {
public:
    int p=33;
    int give(){
        cout<<"the value here is : "<<p<<endl;
        return 34;
    }
    
    void display() {
        cout << "MyClass display function called." << endl;
    }
};

typedef MyClassS MyClassType; // Typedef for class MyClass

// 4. Pointer to a member function of a user-defined data type
typedef void (MyClassS::*MemberFunctionPtr)(); //a pointer to a member function of MyClass


void sampleFunction(int value) {
    cout << "Sample Function called with value: " << value << endl;
}

int main73() {

    str s="priyanka";
    cout << "String : " << s << endl;

    // Using typedef for function pointer
    FunctionPtr funcPtr = &sampleFunction;
    funcPtr(42); 

    // Using typedef for user-defined data type (struct)
    MyPoint p1 = {3, 4};
    cout << "Point: (" << p1.x << ", " << p1.y << ")" << endl;

    // Using typedef for user-defined data type (class)
    MyClassType obj; 
    obj.display();

    typedef int (MyClassS:: *memfun )();

    memfun var = &MyClassS::give;

    cout<<(obj.*var)()<<endl;

    // Using pointer to member function
    MemberFunctionPtr memberFuncPtr = &MyClassS::display; // Pointer to member function
    (obj.*memberFuncPtr)(); // Call the member function using the pointer

    return 0;
}