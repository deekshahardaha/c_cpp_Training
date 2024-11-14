#include <iostream>

using namespace std;

template <typename T, typename U>
void swapfun(T& a, U& b) {
    U temp = static_cast<U>(a); 
    a = static_cast<T>(b);               
    b = temp;   
    cout<<a<<" "<<b<<endl;
}

template <typename T>
void swapfun(T& a, T& b) {
    T temp = a; 
    a = b;      
    b = temp;   
}

int main() {
    // with integers
    int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapfun(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    // with doubles
    double a = 1.5, b = 2.5;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapfun(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    //  with characters
    char c1 = 'A', c2 = 'B';
    cout << "Before swap: c1 = " << c1 << ", c2 = " << c2 << endl;
    swapfun(c1, c2);
    cout << "After swap: c1 = " << c1 << ", c2 = " << c2 << endl;

    //  with int and doubles
    int i1 = 1 ;
    double d1 = 2.5;
    cout << "Before swap: i1 = " << i1 << ", d1 = " << d1 << endl;
    swapfun(i1, d1);
    cout << "After swap: i1 = " << i1 << ", d1 = " << d1 << endl;

    //  with characters and int
    // 65-90 (A-Z) ([,\,],^,_,`) 97-122(a-z) ({,|,},~,,Ç)
    char c3 = 'A'; 
    int i3 = 99;
    cout << "Before swap: c3 = " << c3 << ", i3 = " << i3 << endl;
    swapfun(c3, i3);
    cout << "After swap: c3 = " << c3 << ", i3 = " << i3 << endl;
    char c4 = 'A'; 
    int i4 = 110;
    cout << "Before swap: c4 = " << c4 << ", i4 = " << i4 << endl;
    swapfun(c4, i4);
    cout << "After swap: c4 = " << c4 << ", i4 = " << i4 << endl;
    char c5 = 'A'; 
    int i5 = 26;
    cout << "Before swap: c5 = " << c5 << ", i5 = " << i5 << endl;
    swapfun(c5, i5);
    cout << "After swap: c5 = " << c5 << ", i5 = " << i5 << endl;


    return 0;
}