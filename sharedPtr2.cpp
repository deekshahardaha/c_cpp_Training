#include <iostream>

#include <memory>

using namespace std;
 
int main59() {

    // int arr[] = {12, 2, 4, 5, 6};
    // shared_ptr<int[]> ptr=make_shared<int []> arr; // error because make_shared cannot take an existing array

    // shared_ptr<int[]> ptr(arr);

    /*
    Using shared_ptr with a Stack-Allocated Array: The line shared_ptr<int[]> ptr(arr); is incorrect because arr is a stack-allocated array. When you create a shared_ptr from a stack-allocated array, the shared_ptr will attempt to call delete[] on that pointer when it goes out of scope, leading to undefined behavior.
    */
 
    // Create a shared_ptr that manages a dynamically allocated array of 5 integers
    shared_ptr<int[]> ptr(new int[5], default_delete<int[]>());

    // Initialize the array with values
    int arr[] = {12, 2, 4, 5, 6};

    // Copy values from the local array to the shared_ptr managed array
    for (int i = 0; i < 5; ++i) {
        ptr[i] = arr[i]; 
    }

    // Print the values from the shared_ptr managed array
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i] << " "; 
    }

    cout << endl;

    return 0;

}

 