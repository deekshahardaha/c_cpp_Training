// accessing base class member func from derived class through scope resolution operator 
#include <iostream>
using namespace std;

class Base {
private:
    int a=7;
    void basefunc(){
        cout<<"in base function."<<endl;
    }
public:
    Base() {
        cout << "Base Constructor Called" << endl;
    }
    void basepublicfun(){
        cout<<"base public func"<<endl;

    }
    ~Base() {
        cout << "Base Destructor Called" << endl;
    }
};

class Derived1 : public Base {
protected:
    int d1=11;
    void d1func(){
        cout<<"in D1 function."<<endl;
    }
public:
    Derived1() {
        cout << "Derived1 Constructor Called" << endl;
    }
    ~Derived1() {
        cout << "Derived1 Destructor Called" << endl;
    }
};

class Derived2 : protected Derived1 {
private:
    int d2=17;
    void d2func(){
        cout<<"in D2 function."<<endl;
    }
public:
    Derived2() {
        cout << "Derived2 Constructor Called" << endl;
    }
    void pubfund2(){
        d2func();
        Base::basepublicfun();
    }
    ~Derived2() {
        cout << "Derived2 Destructor Called" << endl;
    }
};

class Derived3 : private Derived2 {
private:
    int d3=45;
    void d3func(){
        cout<<"in D3 function."<<endl;
    }
protected:
    int dp=23;
    void dp3func(){
        cout<<"in D3 protected function."<<endl;
    }
public:
    Derived3() {
        cout << "Derived3 Constructor Called" << endl;
    }

    ~Derived3() {
        cout << "Derived3 Destructor Called" << endl;
    }
};

int main() {
    cout << "Creating Derived3 object." << endl;
    Derived3 obj;
    cout << "Derived3 object created." << endl;

    Derived2 obj2;

    obj2.pubfund2();

    return 0;
}