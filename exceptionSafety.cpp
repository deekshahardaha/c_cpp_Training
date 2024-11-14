#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class SimpleString {
public:
    SimpleString(const string& str) : data(new string(str)) {}
    
    ~SimpleString() {
        delete data; 
    }

    // Basic Guarantee
    void setValue(const string& str) {
        if (str.empty()) {
            throw invalid_argument("String cannot be empty");
        }
        *data = str; 
    }

    // Strong Guarantee
    SimpleString& operator=(SimpleString other) {
        swap(other); // Swap the resources
        return *this; // No exception can affect the original object
    }

    void swap(SimpleString& other) noexcept { // Noexcept 
        std::swap(data, other.data);
    }

    void print() const {
        cout << *data << endl;
    }

private:
    string* data;
};

void BasicGuarantee() {
    SimpleString str("Hello");
    try {
        str.setValue(""); // This will throw an exception
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    str.print(); // The string remains in a valid state
}

void StrongGuarantee() {
    SimpleString str1("Hello");
    SimpleString str2("World");
    
    str1 = str2;
    str1.print(); // Should print "World"
}

void Noexcept() noexcept {
    cout << "This function is noexcept and will not throw." << endl;
}

int main() {
    cout << "Basic Guarantee:" << endl;
    BasicGuarantee();

    cout << "Strong Guarantee:" << endl;
    StrongGuarantee();

    cout << "Noexcept:" << endl;
    Noexcept(); // This function should not throw

    return 0;
}