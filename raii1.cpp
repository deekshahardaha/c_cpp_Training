#include <iostream>
#include <vector>

using namespace std;
 
void useRAII() {
    // vector automatically manages memory
    vector<int> numbers;  
 
    for (int i = 0; i < 10; i++) {
        numbers.push_back(i);
    } // When 'numbers' goes out of scope, its memory is automatically deallocated
}
 
int main51() {
    useRAII();
    return 0;
}