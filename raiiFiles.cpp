#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;

class FileGuard {

public:

    ifstream file;
 
    // Constructor opens the file

    FileGuard(const string& filename) {

        file.open(filename);

        if (!file) {

            throw runtime_error("Failed to open file");

        }

    }
 
    // Destructor automatically closes the file

    ~FileGuard() {

        if (file.is_open()) {

            file.close();

            cout << "File closed automatically.\n";

        }

    }

};
 
void readFile() {

    try {

        FileGuard fileGuard("example.txt");

        string line;

        while (getline(fileGuard.file, line)) {

            cout << line << endl;

        }
        // File is automatically closed when fileGuard goes out of scope

    } catch (const exception& e) {
        cout << e.what() << endl;
    }

}
 
int main52() {

    readFile();

    return 0;

}

 