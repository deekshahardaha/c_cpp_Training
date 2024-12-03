#include <iostream>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

void fileDeleter(ofstream* file) {
    if (file) {
        cout << "Closing file." << endl;
        file->close(); 
        delete file;   
    }
}

int main16() {
    // Create a unique_ptr with a custom deleter for ofstream
    unique_ptr<ofstream, decltype(&fileDeleter)> filePtr(new ofstream("example.txt"), fileDeleter);

    // Check if the file is open
    if (!filePtr->is_open()) {
        cerr << "Failed to open file." << endl;
        return 1; // Exit if file opening fails
    }

    // Write to the file
    *filePtr << "Hello, World!" << endl;

    // The custom deleter will be called when filePtr goes out of scope
    return 0;
}