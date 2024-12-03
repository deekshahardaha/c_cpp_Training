#include <iostream>
#include <memory>
 
using namespace std;

class A;  // Forward declaration
 
class B {

public:
    int var=89;
    B(){
        var++;
        cout<<"In constB"<<endl;
    }
    ~B(){
        cout<<"Dest B"<<endl;
    }

    weak_ptr<A> a_ptr;  // B has a shared pointer to A

};
 
class A {
public:
    int varA=99;
    weak_ptr<B> b_ptr;  // A has a shared pointer to B
    A(){
        varA++;
        cout<<"In const A"<<endl;
    }

    ~A() { cout << "A Dest\n"; }

};
 
int main79() {

    shared_ptr<A> a = make_shared<A>();
    cout<< "A var : "<<a->varA<<endl;

    shared_ptr<B> b = make_shared<B>();
    cout<< "A var : "<<a->varA<<" B var : "<< b->var<<endl;
 
    a->b_ptr = b;
    cout<< "A var : "<<a->varA<<" B var : "<< b->var<<endl;

    b->a_ptr = a;  // Circular reference between A and B
    cout<< "A var : "<<a->varA<<" B var : "<< b->var<<endl;
 
    // To break the cycle, we would use weak_ptr in one of the classes

    // For example, change `shared_ptr<A> a_ptr` in B to `weak_ptr<A> a_ptr`

    cout << "Reference Count : " << b.use_count() << endl; 

    cout<< "A var : "<<a->varA<<" B var : "<< b->var<<endl;
 
    return 0;

}

 