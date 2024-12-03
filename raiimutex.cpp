#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx1;

void print_hello(int id)
{
    lock_guard<mutex> lock(mtx1); // Lock acquired
    cout << "Hello from thread " << id << endl;
    // Mutex automatically unlocked when 'lock' goes out of scope
}

int main53()
{
    thread t1(print_hello, 1);
    thread t2(print_hello, 2);
    t1.join();
    t2.join();
    return 0;
}
