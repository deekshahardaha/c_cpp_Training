#include <iostream>
#include <cctype> // For isalnum

using namespace std;

class MyString {
    char* p;
public:
    MyString() {
        p = nullptr;
        cout << "Inside default constructor" << endl;
    }

    MyString(const char* arg) {
        p = new char[lengthOfString(arg) + 1]; // +1 for null terminator
        cout << "Inside parameterized constructor" << endl;
        for (int i = 0; arg[i] != '\0'; i++) {
            p[i] = arg[i]; // Manually copy each character
        }
        p[lengthOfString(arg)] = '\0'; // Add null terminator
    }

    MyString(const MyString& obj) {
        this->p = new char[lengthOfString(obj.p) + 1];
        for (int i = 0; obj.p[i] != '\0'; i++) {
            p[i] = obj.p[i]; // Manually copy each character
        }
        p[lengthOfString(obj.p)] = '\0'; // Add null terminator
        cout << "Inside copy constructor" << endl;
    }

    MyString& operator=(const MyString& obj) {
        if (this != &obj) { // Self-assignment Check
            delete[] p; // Free existing resource
            p = new char[lengthOfString(obj.p) + 1]; // Allocate new memory
            for (int i = 0; obj.p[i] != '\0'; i++) {
                p[i] = obj.p[i]; // Manually copy each character
            }
            p[lengthOfString(obj.p)] = '\0'; // Add null terminator
        }
        cout << "Inside assignment operator" << endl;
        return *this;
    }

    ~MyString() {
        delete[] p;
    }

    // New lengthOfString function without using strlen
    int lengthOfString(const char* str) const {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    int lengthOfString() const {
        return lengthOfString(p); // Call the new lengthOfString function
    }

    int numberOfSpecialCharacters() const {
        if (p == nullptr) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < lengthOfString(); i++) {
            if (!isalnum(p[i])) {
                count++;
            }
        }
        return count;
    }

    char* reverseString() const {
        if (p == nullptr) {
            return nullptr;
        }
        int len = lengthOfString();
        char* reversedStr = new char[len + 1];
        for (int i = 0; i < len; i++) {
            reversedStr[i] = p[len - i - 1];
        }
        reversedStr[len] = '\0';
        return reversedStr;
    }

    void toUpperCase() {
        if (p == nullptr) {
            return;
        }
        for (int i = 0; i < lengthOfString(); i++) {
            if (p[i] >= 'a' && p[i] <= 'z') {
                p[i] = p[i] - 'a' + 'A';
            }
        }
    }

    void toLowerCase() {
        if (p == nullptr) {
            return;
        }
        for (int i = 0; i < lengthOfString(); i++) {
            if (p[i] >= 'A' && p[i] <= 'Z') {
                p[i] = p[i] - 'A' + 'a';
            }
        }
    }

    const char* getString() const {
        return p;
    }

    // Overload the << operator
    friend ostream& operator<<(ostream& os, const MyString& myStr) {
        if (myStr.p != nullptr) {
            os << myStr.p; // Output the string
        } else {
            os << "(null)"; // Handle null case
        }
        return os;
    }
};

int main38() {
    MyString str1;
    MyString str2("Hello");
    MyString str3(str2);
    MyString str4("oalngoal#@ngf123");
    
    str1 = str2;

    cout << "Length of string is : " << str1.lengthOfString() << endl;
    cout << "Number of special characters in string : " << str4.numberOfSpecialCharacters() << endl;
    
    char* reversed = str1.reverseString();
    cout << "Reversed string : " << reversed << endl;
    delete[] reversed;

    str2.toUpperCase();
    cout << "Uppercase string : "<< str2<<endl;

     str2.toLowerCase();
    cout << "Lowercase string : " << str2.getString() << endl;

    str1 = str2 = str3 = str4;
    
    return 0;
}