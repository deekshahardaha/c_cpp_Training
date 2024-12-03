#include<iostream>
using namespace std;

class A{
public:
    A(){
        cout<<"A constructor !"<<endl;
    }
    virtual void fun1(){
        cout<<"A fun1()"<<endl;
    }

    virtual void fun2(){
        cout<<"A fun2()"<<endl;
    }
};

class B{
public:
    B(){
        cout<<"B constructor !"<<endl;
    }
    void fun1(){
        cout<<"B fun1()"<<endl;
    }
    virtual void fun3(){
        cout<<"B fun3()"<<endl;
    }
    
};

class C:public A,public B{
public:
    C(){
        cout<<"C constructor !"<<endl;
    }
    void fun1(){
        cout<<"C fun1()"<<endl;
    }
    void fun3(){
        cout<<"B fun3()"<<endl;
    }
    virtual void fun4(){
        cout<<"B fun4()"<<endl;
    }
};
int main42(){


    A a;
    B b; 
    C c;


    cout<<sizeof(A)<<endl;  //4
    cout<<sizeof(B)<<endl;  //4
    cout<<sizeof(C)<<endl;  //8

    return 0;
}