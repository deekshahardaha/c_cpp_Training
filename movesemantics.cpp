#include <iostream>

using namespace std;

class mycls {
    // Assuming mycls has some members and methods
public:
    mycls(){
        cout<<"Mycls cons.."<<endl;
    }
    mycls(const mycls &obj){
        cout<<"Mycls cons.."<<endl;
    }
    ~mycls(){
        cout<<"Myclas des.."<<endl;
    }
};

class A {
    int *m;      
    mycls oo;    

public:
    // Default constructor
    A() {
        cout<<"Const.."<<endl;
        m = new int; 
        *m = 4;      
    }

    // Copy constructor
    A(const A &rhs) : oo(rhs.oo) {
        cout<<"copy const.."<<endl;
        m = new int; 
        *m = *rhs.m; 
    }

    // Move constructor
    A(A &&rhs) : oo(move(rhs.oo)) {
        cout<<"Move const.."<<endl;
        m = rhs.m;  
        rhs.m = nullptr; 
    }

    // Destructor
    ~A() {
        cout<<"dest.."<<endl;
        delete m; 
    }

    // Copy assignment operator
    A& operator=(const A &rhs) {
        cout<<"copy assignment.."<<endl;
            m = new int; 
            *m = *rhs.m; 
            oo = rhs.oo; 
        return *this; 
    }

    // Move assignment operator
    A& operator=(A &&rhs) {
        cout<<"Move assignment.."<<endl;
            m = rhs.m; 
            oo = move(rhs.oo); 
            rhs.m = nullptr; 
        return *this; 
    }

    // Method to process data
    void dataprocess() {
        if (m) {
            cout << *m << endl; 
        }
    }
};

// Function that takes an A object by reference
A fun(A& x) {
    cout<<"In fun"<<endl;
    A y; 
    cout<<"out from fun "<<&x<<" "<<&y<<endl;
    return y; 
}

int main34() {
    A o1; 
    // A o2 = move(o1); // Move constructor
    // A o4(o2); // Copy constructor
    // o1.dataprocess(); // This may print garbage or nothing since o1 is moved from
    A o3; // Default constructor
    o3 = o1; // Copy assignment operator
    o3 = fun(o1); // Move assignment operator (fun returns an A object)
    return 0;
}