#include<iostream>

using namespace std;

template <typename T, typename U>
T maxfun(T a, U b){
    // both will be converted to type T hence Explicitly converting a to type U
    return ((U)a>b)? a : b;
}

template <typename T>
T maxfun(T a,T b){
    return (a>b)? a : b;
}


int main71(){
    cout<<"max of 2 and 6 is : "<<maxfun(2,6)<<endl;
    cout<<"max of 2, 2.65 is : "<<maxfun(2.56,2)<<endl;

    return 0;
}

