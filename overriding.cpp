#include<iostream>
using namespace std;

class A{
    int x;
public:
    A(){
        cout<<"A constructor !"<<endl;
        fun(); 
    }
    virtual void fun(){
        cout<<"A fun()"<<endl;
    }
};

class B:public A{
    char d;
public:
    B(){
        cout<<"B constructor !"<<endl;
    }
    void fun(){
        cout<<"B fun()"<<endl;
    }
    
};

class C:public B{
    int g;
public:
    C(){
        cout<<"C constructor !"<<endl;
    }
    void fun(){
        cout<<"C fun()"<<endl;
    }
};
int main(){


    A a;
    B b; // here virtual pionter will not be created it only be created with pointers.
    a.fun();
    b.fun();
    A *ptr1 = new A; // inline A::A()
    ptr1->fun();

    // we can create base class object with derived class instantiation. but vise-versa is not true.(it violates type safety in c++)
    A *ptr2 = new B;
    ptr2->fun();
    A *ptr3 = new C;
    ptr3->fun();
    // B *ptr = new A; // error for the above reason.
    // ptr->fun();


    cout<<sizeof(A)<<endl;
    cout<<sizeof(B)<<endl;
    cout<<sizeof(C)<<endl;


    /*
    sizeof(A) = 4 bytes
    sizeof(B) = 8 bytes (due to padding)
    sizeof(C) = 12 bytes
    With Virtual Functions:

    sizeof(A) = 8 bytes
    sizeof(B) = 12 bytes (due to padding)
    sizeof(C) = 16 bytes
    */
    delete ptr1;
    delete ptr2;
    delete ptr3;
    return 0;
}