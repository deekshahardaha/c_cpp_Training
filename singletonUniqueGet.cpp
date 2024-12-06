#include <iostream>
#include <memory>  // For std::unique_ptr
#include <mutex>   // For std::mutex

using namespace std;

class Singleton1 {
private:
    static unique_ptr<Singleton1> instance; // Unique pointer for singleton instance
    static mutex mtx;                      // Mutex for thread safety

    // Private constructor
    Singleton1() {
        cout << "Singleton created!" << endl;
    }

public:
    // Static method to get the singleton instance
    static Singleton1* getInstance() {
        lock_guard<mutex> lock(mtx); // Ensure thread safety
        if (!instance) {
            instance = unique_ptr<Singleton1>(new Singleton1());
            // instance = make_unique<Singleton>();
        }
        return instance.get();
    }

    void showMessage() {
        cout << "Hello from Singleton1!" << endl;
    }

    // Delete copy constructor and assignment operator to prevent copying
    Singleton1(const Singleton1&) = delete;
    Singleton1& operator=(const Singleton1&) = delete;
};

// Initialize static members
unique_ptr<Singleton1> Singleton1::instance = nullptr;
mutex Singleton1::mtx;

int mainsnglunq() {
    Singleton1* singleton1 = Singleton1::getInstance();
    singleton1->showMessage();

    Singleton1* singleton2 = Singleton1::getInstance();
    singleton2->showMessage();

    // Both pointers should point to the same instance
    cout << "Are both pointers equal? "
        << (singleton1 == singleton2 ? "Yes" : "No")
        << endl;

    return 0;
}

