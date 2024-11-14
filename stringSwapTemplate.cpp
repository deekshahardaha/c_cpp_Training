#include <iostream>
#include <string>
#include<cstring> ///for strcpy

using namespace std;


void swapfun(string& a, int& b) {
    string temp = a; 
    a = to_string(b); 
    b = stoi(temp); 
}

// Function to swap string and char[]
void swapfun(string& a, char b[]) {
    string temp = a; 
    a = b;
    strcpy(b, temp.c_str()); 
}

int main() {

    int a=5;
    string s=to_string(a); 
    string str1= "Value";
    int num = 42;
    cout << "Before swap: str = " << str1 << ", num = " << num << endl;
    swapfun(str1, num);
    cout << "After swap: str = " << str1 << ", num = " << num << endl;

    string str = "Hello";
    char cstr[100] = "World";
    cout << "Before swap: str = " << str << ", cstr = " << cstr << endl;
    swapfun(str, cstr);
    cout << "After swap: str = " << str << ", cstr = " << cstr << endl;

    return 0;
}