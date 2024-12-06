#include <iostream>
#include <memory>  // For std::shared_ptr
#include <mutex>   // For std::mutex

using namespace std;

class Singletonshrd {
private:
    static shared_ptr<Singletonshrd> instance;
    static mutex mtx;

    Singletonshrd() {
        cout << "Singleton created!" << endl;
    }

public:
    static shared_ptr<Singletonshrd> getInstance() {
        lock_guard<mutex> lock(mtx); // Ensure thread safety
        if (!instance) {
             instance = shared_ptr<Singletonshrd>(new Singletonshrd());
            //instance = make_shared<Singletonshrd>();
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }

    // Delete copy constructor and assignment operator to prevent copying
    Singletonshrd(const Singletonshrd&) = delete;
    Singletonshrd& operator=(const Singletonshrd&) = delete;
};

// Initialize static members
shared_ptr<Singletonshrd> Singletonshrd::instance = nullptr;
mutex Singletonshrd::mtx;

int mainsnglshrd() {
    auto singleton1 = Singletonshrd::getInstance();
    singleton1->showMessage();

    auto singleton2 = Singletonshrd::getInstance();
    singleton2->showMessage();

    // Both pointers should point to the same instance
    cout << "Are both pointers equal? "
        << (singleton1 == singleton2 ? "Yes" : "No")
        << endl;

    return 0;
}

