#include <iostream>

using namespace std;

int main(){

    // non-constant initialization
    int a = 33;
    int b = 40;
    a = 20;

    //1. A non-const pointer pointing to a non-const value. 
    int *p1=&a;
    cout<<++(*p1)<<endl;

    //const intitilaization
    const int x = 10;
    int const y = 20;
    // y++; //Error can not change const value.
 
    //2. A non-const pointer pointing to a const value. 
    // int* p2=&x; //Error 


    //3. A const pointer pointing to a non-const value. 
    int* const p=&a;
    cout<<*p<<endl;
    //(*p)++; //giving error because we are trying to modify the value using a const-pointer.
    //p++; // cant be done because pointer is const.


    int arr[3] = { 1,2,3 };
    // p3 is a (const int) type of pointer (not a const pointer)
    const int* p3 = arr;
    cout << *p3 << endl;
    cout << *(++p3) << endl;
    cout << *(++p3) << endl;
    //(*p3)++;//giving error because we are trying to modify the value using a const-int pointer.
    cout<<*p3<<endl;
    p3++; // went to some unknown location.
    cout << *p3 << endl; //gives garbage value.

  
    //4. Const-pointer of const-value. 
    const int* const p4 = &x;
    cout << *p4<<endl;
    // (*p4)++; // error (pointer is also constant here)
    // p4++; //error (p4 pointing to a value of const-int type)
    cout << *p4 << endl;

    const int* const ptr3 = &a; // although a was not declared as const but using ptr3 we can only use it as const-int
    cout << *ptr3<<endl;
    // ptr3++; 

    return 0;
}
