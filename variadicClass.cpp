#include <iostream>
#include <string>

using namespace std;

// Variadic class template
template<typename... Args>
class MyTuple;

// Specialization for the case with one element
template<typename T>
class MyTuple<T> {
public:
    MyTuple(T value) : value(value) {}

    void print() const {
        cout << value;
    }

private:
    T value;
};

template<typename T, typename... Rest>
class MyTuple<T, Rest...> {
public:
    MyTuple(T value, Rest... rest) : value(value), rest(rest...) {}

    void print() const {
        cout << value << ", ";
        rest.print();
    }

private:
    T value;
    MyTuple<Rest...> rest; // Recursive definition
};

int main77() {
    // Create a MyTuple with different types
    MyTuple<int, double, string> myTuple(42, 3.14, "Hello, World!");

    myTuple.print();

    return 0;
}