#include <iostream>
#include <memory>

using namespace std;

int main60() {
    // Create a shared_ptr that manages an array of 5 integers
    // shared_ptr<int[]> arr(new int[5]);
    // auto arr = make_shared<int[5]>();
    shared_ptr<int> arr(new int[10], default_delete<int[]>());
    // int arr[5];

    // Initialize the array
    for (int i = 0; i < 5; ++i) {
        arr.get()[i] = i * 10; // Assign values to the array
    }

    // Print the array values
    cout << "Array values: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr.get()[i] << " "; // Access the array elements
    }
    cout << endl;

    // Create another shared_ptr that shares ownership of the same array
    shared_ptr<int> arr2 = arr;

    // Print the array values from arr2
    cout << "Array values from arr2: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr2.get()[i] << " "; // Access the array elements
    }
    cout << endl;

    // Modify the array using arr2
    arr2.get()[2] = 100; // Change the third element

    // Print the modified array using arr
    cout << "Modified array values from arr: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr.get()[i] << " "; // Access the modified array elements
    }
    cout << endl;

    // No need to manually delete the array; it will be automatically released when arr and arr2 go out of scope

    return 0;
}