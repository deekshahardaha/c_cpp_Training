#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

class DynamicArray {
public:
    DynamicArray(size_t size) : size(size), data(new int[size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = i; // Initialize with some values
        }
    }

    ~DynamicArray() {
        delete[] data; // Resource cleanup
    }

    // Basic Guarantee: If an exception occurs, the destructor will still be called
    void setValue(size_t index, int value) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        data[index] = value; // This may throw if index is out of range
    }

    // Strong Guarantee: Copy-and-swap idiom for assignment
    DynamicArray& operator=(DynamicArray other) { // Copy constructor is called
        swap(other); // Swap the resources
        return *this; // No exception can affect the original object
    }

    void swap(DynamicArray& other) noexcept { // Noexcept ensures no exceptions are thrown
        std::swap(size, other.size);
        std::swap(data, other.data);
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    size_t size;
    int* data;
};

void BasicGuaranteeS() {
    DynamicArray arr(5);
    try {
        arr.setValue(10, 100); // This will throw an exception
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    arr.print(); // The array remains in a valid state
}

void StrongGuaranteeS() {
    DynamicArray arr1(5);
    DynamicArray arr2(5);
    // arr1.setValue(0, 1);
    // arr1.setValue(1, 2);
    // arr1.setValue(2, 3);
    
    try {
        arr2 = arr1; // This should not throw, even if arr1 is modified
        arr1.setValue(7, 4); // Modify arr1 after assignment
    } catch (const exception& e) {
        cout << "Caught exception during assignment: " << e.what() << endl;
    }
    arr1.print(); // arr1 should still be valid
    arr2.print(); // arr2 should reflect the state of arr1 before modification
}

void NoexceptS() noexcept {
    // This function is marked noexcept, so it should not throw
    throw runtime_error("tried something");
    cout << "This function is noexcept and will not throw." << endl;
}

int main15() {
    cout << " Basic Guarantee:" << endl;
    BasicGuaranteeS();

    cout << "Strong Guarantee:" << endl;
    StrongGuaranteeS();

    cout << " Noexcept:" << endl;
    NoexceptS(); // This function should not throw
    cout<<"No exception thrown by no except"<<endl;

    return 0;
}