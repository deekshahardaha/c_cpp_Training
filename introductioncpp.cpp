#include<iostream>
#include <fstream>
#include<cwchar>

using namespace std;

int main23(){
    // without space 
    // string name;
    // cin>>name;
    // cout<<name<<endl;

    // if the space is needed in the string then use getline()
    // char nm[50];
    // cin.getline(nm,50);
    // cout<<nm<<endl;

    // string name2;
    // name2 = name;
    // if (name==name2){
    //     cout<<"same string"<<endl;
    // }
    // name2.append("deek");
    // cout<<name2.c_str()<<" "<<name2.size()<<endl;


    /*
    cerr is a standard output stream in C++ used for error messages and diagnostics.
    It is unbuffered, meaning that output is displayed immediately.
    */
    // int number;
    // cout << "Enter a number: ";
    // cin >> number;
    // if (cin.fail()) {
    //     cerr << "Error: Invalid input. Please enter a valid number." << endl;
    // }
    // ifstream file("nonexistent.txt");

    // if (!file) {
    //     cerr << "Error: Could not open the file." << endl;
    // }

    
    // to take input of any script (hindi, telugug or any)
    // wchar_t script=L'ब';
    // wstring wstr =L"वेब पर कहीं भी लिखना आसान";
    // wcout<<script<<endl;
    // cout<<sizeof(script)<<endl;
    // cout<<sizeof(wstr)<<endl;


    // 1. Constructors
    string s1; // Default constructor
    string s2("Hello,"); // From C-string
    string s3(s2); // Copy constructor
    string s4(5, 'A'); // From count of characters
    string s5(s2,3); // with the first 3 characters of

    // 2. Assignment
    s1 = "World!"; // Assigning a C-string
    cout << "s1: " << s1 << endl;
    string s6 =s2; //already existing string to the another string object.

    // 3. Element Access
    cout << "First character of s2: " << s2.front() << endl;
    cout << "Last character of s2: " << s2.back() << endl;
    cout << "Character at index 1 of s2: " << s2.at(1) << endl;
    cout << "Character at index 2 of s2: " << s2[2] << endl;

    // 4. Capacity
    // The size() function is part of the C++ Standard Library's container interface, which is used for various container types (like vector, list, etc.)
    cout << "Size of s2: " << s2.size() << endl;
    // The length() function is more commonly associated with string manipulation and is often used in other programming languages (like Java).
    cout << "length of s2: " << s2.length() << endl;
    //the maximum number of characters the string can hold.
    //a useful function for understanding the limits of string storage in C++.
    cout << "max size of s2: " << s2.max_size() << endl;
    cout << "max size of s1: " << s1.max_size() << endl;
    //returns the amount of storage currently allocated for the string, which may be greater than or equal to the size of the string
    //capacity will be 15 , 30 and then lenght of the string
    cout << "Capacity of s2: " << s2.capacity() << endl;
    cout << "Capacity of s1: " << s1.capacity() << endl;

    // Original string
    cout << "Original string: " << s1 << " (Size: " << s1.size() << ")" << endl;

    // Resize to a smaller size
    s1.resize(5);
    cout << "After resizing to 5: " << s1 << " (Size: " << s1.size() << ")" << endl;

    // Resize to a larger size
    s1.resize(10);
    cout << "After resizing to 10: " << s1 << " (Size: " << s1.size() << ")" << endl;

    // Resize to a larger size with a specified character
    s1.resize(15, '*');
    cout << "After resizing to 15 with '*': " << s1 << " (Size: " << s1.size() << ")" << endl;

    // 5. Modifiers
    //Erases the contents of the string.
    s1.clear();

    s2.append("How are you?"); // Append
    cout << "After append: " << s2 << endl;

    s2.insert(7, "beautiful "); // Insert
    cout << "After insert: " << s2 << endl;

    s2.erase(7, 10); // Erase
    cout << "After erase: " << s2 << endl;

    s2.replace(7, 4, "great"); // Replace
    cout << "After replace: " << s2 << endl;

    s2.append("buddy");
    cout << "After append: " << s2 << endl;

    s2+="fun";
    cout << "After append: " << s2 << endl;

    // 6. String Operations

    // s2.rfind("kjdh")  to find the last occurrence.
    //s.find_first_of("aeiou")  Returns the index of the first occurrence of any character from the specified set.
    //s.find_last_of("aeiou")  Returns the index of the last occurrence of any character from the specified set.
    //s.find_first_not_of("aeiou")  Returns the index of the first character not in the specified set.
    //s.find_last_not_of("aeiou")  Returns the index of the last character not in the specified set.
    size_t found = s2.find("great");
    if (found != string::npos) {
        cout << "'great' found at index: " << found << endl;
    }

    // 7. Substrings
    string sub = s2.substr(0, 4); // Get substring
    cout << "Substring: " << sub << endl;

    // 8. Comparison
    // Compares two strings lexicographically.
    // 0: if s1 is equal to s2.
    // < 0: if s1 is lexicographically less than s2.
    // > 0: if s1 is lexicographically greater than s2.

    if (s1.compare("World!") == 0) {
        cout << "s1 is equal to 'World!'" << endl;
    }

    // This is an operator overload for the equality operator (==) that checks if the two strings are equal.
    // It returns a boolean value:
    // true: if s1 is equal to s2.
    // false: if s1 is not equal to s2.
    // This operator also performs a case-sensitive comparison.
    cout<<(s1 == s2)<<endl;

    // 9. Conversion
    //Use c_str() when you need a null-terminated string for C-style functions.
    //Use data() when you need direct access to the character data without the need for null-termination.
    const char* cstr = s2.c_str(); // Convert to C-string
    cout << "C-string: " << cstr << endl;
    // Get a pointer to the underlying character array
    const char* dataPtr = s2.data();
    // Print the data
    cout << "Data: " << dataPtr << endl;

    size_t pos = 6; 
    size_t len = 8 ; 
    s2.replace(pos, len, "C++");
    cout << "Modified string: " << s2 << endl;

    // 10. Clear the string
    s2.clear();
    cout << "After clear, size of s2: " << s2.size() << endl;

    return 0;
}