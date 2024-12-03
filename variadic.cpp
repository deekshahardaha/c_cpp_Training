#include <iostream>
using namespace std;


template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...); 
}

int main76() {
    cout << "Sum of 1, 2, 3: " << sum(1, 2, 3) << endl; 
    cout << "Sum of 1.5, 2.5, 3.5: " << sum(1.5, 2.5, 3.5) << endl; 
    cout << "Sum of 'a', 'b', 'c': " << sum('a', 'b', 'c') << endl; 
    // cout << "Sum of \"jkfsd\",\"shjkd\",\"kdjs\" : " << sum("jkfsd","shjkd","kdjs") << endl; 

    return 0;
}