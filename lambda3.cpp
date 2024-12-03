#include <iostream>
using namespace std;

auto fun1(int arg)
{
    return [arg](int n) -> int {
        return n * arg;
    };
}

int main27()
{   
    // here x is a callable object .
    auto x = fun1(5);
    cout<<x(4)<<endl;
    return 0;
}