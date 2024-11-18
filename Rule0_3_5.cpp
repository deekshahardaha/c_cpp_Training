/*

The Rule of Zero states that you should design your classes in such a way that they do not require custom implementations of the special member functions (constructor, destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator). This is typically achieved by using standard library types (like vector, string, etc.) that manage their own resources.

The Rule of Three states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all three. This is because if you manage resources (like dynamic memory), you need to ensure proper copying and destruction of those resources.

The Rule of Five extends the Rule of Three to include move semantics, which were introduced in C++11. If a class requires a user-defined destructor, copy constructor, copy assignment operator, move constructor, or move assignment operator, it likely requires all five.

*/

#include <iostream>
#include <cstring> // For strcpy and strlen

using namespace std;

// Rule of Zero: No resources managed, so no special member functions needed
class RuleOfZero {
public:
    void display() const {
        cout << "Rule of Zero: No resources managed." << endl;
    }
};

// Rule of Three: Manages a dynamic array
class RuleOfThree {
private:
    int *data;

public:
    RuleOfThree(int s){
        cout<<"in 3 const"<<endl;
        data = new int; 
        *data= 23;
    }

    // Copy Constructor
    RuleOfThree(const RuleOfThree& other) {
        cout<<"in 3 cc"<<endl;
        data = new int; 
        data =other.data; 
    }

    // Copy Assignment Operator
    RuleOfThree& operator=(const RuleOfThree& other) {
        cout<<"in 3 copy ass"<<endl;
        if (this != &other) { // Self-assignment check
            delete data; // Free existing resource
            data = new int; // Allocate new memory
            data=other.data; // Copy data
        }
        return *this;
    }

    // Destructor
    ~RuleOfThree() {
        cout<<"in 3 des"<<endl;
        delete data; // Free allocated memory
    }

    void display() const {
        cout << "Rule of Three: ";
        cout << *data<<endl;
    }
};

// Rule of Five: Manages a dynamic array with move semantics
class RuleOfFive {
private:
    int* data;

public:
    RuleOfFive(int s)  {
        cout<<"in 5 cons"<<endl;
        data = new int; 
        *data =33;
    }

    // Copy Constructor
    RuleOfFive(const RuleOfFive& other) {
        cout<<"in 5 CC"<<endl;
        data = new int; 
        data=other.data ; 
    }

    // Copy Assignment Operator
    RuleOfFive& operator=(const RuleOfFive& other) {
        cout<<"in 5 copy ass.."<<endl;
        if (this != &other) { 
            delete data; 
            data = new int; 
            data= other.data ; 
        }
        return *this;
    }

    // Move Constructor
    RuleOfFive(RuleOfFive&& other) noexcept : data(other.data) {
        cout<<"in 5 move const.."<<endl;
        other.data = nullptr; // Leave the moved-from object in a valid state
    }

    // Move Assignment Operator
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        cout<<"in 5 move ass.."<<endl;
        if (this != &other) { 
            delete data; 
            data = other.data; 
            other.data = nullptr; 
        }
        return *this;
    }

    // Destructor
    ~RuleOfFive() {
        cout<<"in 5 des"<<endl;
        delete data; 
    }

    void display() const {
        cout << "Rule of Five: ";
        cout <<*data<< endl;
    }
};

int main() {
    // Demonstrating Rule of Zero
    RuleOfZero zero;
    zero.display();

    // Demonstrating Rule of Three
    RuleOfThree three(5);
    three.display();
    RuleOfThree threeCopy = three; // copy constructor
    threeCopy.display();

    RuleOfThree threeAssign(3);
    threeAssign = three; // copy assignment operator
    threeAssign.display();

    // Demonstrating Rule of Five
    RuleOfFive five(5);
    five.display();
    RuleOfFive fiveMove = move(five); //  move constructor
    fiveMove.display();

    RuleOfFive fiveAssign(3);
    fiveAssign = move(fiveMove); // move assignment operator
    fiveAssign.display();

    return 0;
}