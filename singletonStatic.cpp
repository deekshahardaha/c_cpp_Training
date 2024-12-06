#include <iostream>
#include <mutex>

using namespace std;

class Singletonshrd {
private:
    // Private constructor to prevent instantiation
    Singletonshrd() {
        cout << "Singleton instance created." << endl;
    }

    // Delete copy constructor and assignment operator
    Singletonshrd(const Singletonshrd&) = delete;
    Singletonshrd& operator=(const Singletonshrd&) = delete;

    // Static instance pointer
    static Singletonshrd* instance;
    static mutex mutex_; // Mutex for thread safety

public:
    // Static method to get the instance of the Singleton
    static Singletonshrd* getInstance() {
        // Double-checked locking for thread safety
        if (instance == nullptr) {
            lock_guard<mutex> lock(mutex_);
            if (instance == nullptr) {
                instance = new Singletonshrd();
            }
        }
        return instance; 
    }

    // Example method
    void someFunctionLogic() {
       cout << "In Function logic." << endl;
    }
};

// Initialize static member
Singletonshrd* Singletonshrd::instance = nullptr;
mutex Singletonshrd::mutex_;

int mainsss() {
    // Access the Singleton instance and call a method
    Singletonshrd* singletonInstance = Singletonshrd::getInstance();
    singletonInstance->someFunctionLogic();

    // Access the Singleton instance again
    Singletonshrd* anotherInstance = Singletonshrd::getInstance();
    anotherInstance->someFunctionLogic();

    return 0;
}