#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the - operator
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload the * operator
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag, 
                       real * other.imag + imag * other.real);
    }

    // Overload the / operator
    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Overload the << operator for output
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    // Overload the == operator
    bool operator==(const Complex& other) {
        return (real == other.real) && (imag == other.imag);
    }

    // Overload the != operator
    bool operator!=(const Complex& other) {
        return !(*this == other);
    }
};

int main40() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3(1.0, 2.0);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;

    // Equality check
    if (c2 == c3) {
        cout << "c2 is equal to c3" << endl;
    } 
    if (c1!=c2) {
        cout << "c1 is not equal to c2" << endl;
    }

    return 0;
}