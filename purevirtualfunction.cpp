#include <iostream>

using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual double area() = 0; // No implementation in the base class
};


class Square : public Shape {
private:
    double length;

public:
    Square(double l) : length(l){}

    // Override the pure virtual function
    double area() override {
        return length*length; 
    }
};


class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override the pure virtual function
    double area() override {
        return width * height; 
    }
};

int main49() {
    Shape* shape1 = new Square(5.0); 
    Shape* shape2 = new Rectangle(4.0, 6.0); 

    cout << "Area of Circle: " << shape1->area() << endl;
    cout << "Area of Rectangle: " << shape2->area() << endl; 

    delete shape1;
    delete shape2;

    return 0;
}