#include <iostream>
#include <vector>
#include <algorithm> // For sort, reverse, etc.
#include<typeinfo>

using namespace std;

int main78() {
    // 1. Declaration and Initialization
    vector<int> vec = {5, 2, 8, 1, 3};

    // 2. Size and Capacity
    cout << "Size: " << vec.size() << endl; // Number of elements
    cout << "Capacity: " << vec.capacity() << endl; // Allocated memory
    cout << "Max Size: " << vec.max_size() << endl; // Maximum size

    // 3. Accessing Elements
    cout << "First Element: " << vec.front() << endl; // Access first element
    cout << "Last Element: " << vec.back() << endl; // Access last element
    cout << "Element at index 2: " << vec.at(2) << endl; // Access with bounds checking
    cout << "Element at index 2 (using operator[]): " << vec[2] << endl; // Access without bounds checking

    // 4. Modifying Elements
    vec[0] = 10; // Modify the first element
    cout << "Modified First Element: " << vec.front() << endl;

    // 5. Adding Elements
    vec.push_back(6); // Add an element to the end
    cout << "After push_back(6): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    vec.insert(vec.begin() + 1, 4); // Insert 4 at index 1
    cout << "After insert(4 at index 1): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // 6. Removing Elements
    vec.pop_back(); // Remove the last element
    cout << "After pop_back(): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    vec.erase(vec.begin() + 1); // Remove element at index 1
    cout << "After erase(index 1): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // 7. Clearing the Vector
    vec.clear(); // Remove all elements
    cout << "After clear(): Size = " << vec.size() << endl;

    // 8. Re-initializing the Vector
    vec = {5, 2, 8, 1, 3};

    // 9. Sorting the Vector
    sort(vec.begin(), vec.end()); // Sort in ascending order
    cout << "After sort(): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // 10. Reversing the Vector
    reverse(vec.begin(), vec.end()); // Reverse the order
    cout << "After reverse(): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // 11. Finding an Element
    auto it = find(vec.begin(), vec.end(), 2); // Find element 2
    if (it != vec.end()) {
        cout << "Element 2 found at index: " << distance(vec.begin(), it) << endl;
    } else {
        cout << "Element 2 not found." << endl;
    }

    // 12. Resizing the Vector
    vec.resize(8, 0); // Resize to 10 elements, filling new elements with 0
    cout << "After resize(10, 0): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    cout << "Before shrink_to_fit(): Capacity = " << vec.capacity() << endl;

    // 13. Shrinking the Vector
    vec.shrink_to_fit(); // Reduce capacity to fit size
    cout << "After shrink_to_fit(): Capacity = " << vec.capacity() << endl;


    // 15. crbegin() and crend()
    cout << "Using crbegin() and crend() for reverse iteration:" << endl;
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        cout << *it << " "; // Outputs elements in reverse order
    }
    cout << endl;

    // 16. data()
    int* dataPtr = vec.data(); // Get pointer to the underlying array
    cout << "Data pointer points to: " << *dataPtr << endl; // Outputs 5

    // 17. emplace() and emplace_back()
    vec.emplace_back(10); // Adds 10 to the end of the vector
    cout << "After emplace_back(10): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    vec.emplace(vec.begin() + 1, 4); // Inserts 4 at index 1
    cout << "After emplace(4 at index 1): ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // 18. empty()
    cout << "Is the vector empty? " << (vec.empty() ? "Yes" : "No") << endl;

    // 19. get_allocator()
    allocator<int> alloc = vec.get_allocator(); // Get the allocator
    cout << "Allocator type: " << typeid(alloc).name() << endl;

    // 20. operator[]
    cout << "Element at index 2: " << vec[2] << endl; // Access element at index 2

    // 21. rbegin() and rend()
    cout << "Using rbegin() and rend() for reverse iteration:" << endl;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " "; // Outputs elements in reverse order
    }
    cout << endl;

    // 22. shrink_to_fit()
    vec.reserve(20); // Reserve more space than needed
    cout << "Capacity before shrink_to_fit(): " << vec.capacity() << endl;
    vec.shrink_to_fit(); // Reduce capacity to fit size
    cout << "Capacity after shrink_to_fit(): " << vec.capacity() << endl;

    // 23. swap()
    vector<int> vec2 = {100, 200, 300};
    cout << "Before swap, vec2: ";
    for (int n : vec2) cout << n << " ";
    cout << endl;

    vec.swap(vec2); // Swap contents of vec and vec2
    cout << "After swap, vec: ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    cout << "After swap, vec2: ";
    for (int n : vec2) cout << n << " ";
    cout << endl;

    // Note: The following methods are internal and not typically used directly.
    // They are part of the implementation of vector and are not meant for public use.
    // _m_allocate(), _m_get_tp_allocator(), _m_impl(), ~vector_base(), ~vector() are not directly accessible.

    return 0;
}