#include<iostream>
using namespace std;

// class Shape {
// public:
//     virtual void area() = 0; // Pure virtual function
// };

// class Circle : public Shape {
// public:
//     void area() {
//         std::cout << "area Circle" << std::endl;
//     }
// };

// class Square : public Shape {
// public:
//     void area() {
//         std::cout << "area Square" << std::endl;
//     }
// };

// class Rectangle : public Shape {
// public:
//     void area() {
//         std::cout << "area rectangle" << std::endl;
//     }
// };

// class Ellipse : public Shape {
// public:
//     void area() {
//         std::cout << "area Ellipse" << std::endl;
//     }
// };


// void renderShapes(Shape* shape) {
//     shape->area(); // Can work with any derived class of Shape
// }

// int main(){
//     Square s;
//     Rectangle r;
//     Circle c;
//     Ellipse e;

//     renderShapes(&c);
//     return 0;
// } 


class Shape{
public:
    virtual float Area() { return 0.0f; }
};
 
class Circle:public Shape{
public:
    float Area() { return 1.0f; }
};
 
class Rect:public Shape{
public:
    float Area() { return 2.0f; } 
};
 
class Square:public Shape{
public:
    float Area() { return 3.0f; }
};
 
void GetFun(Shape *ptr)
{
    cout<<ptr->Area()<<endl;
}
 
int main2(){
    Circle *pCircle=new Circle;
    Square *pSquare=new Square;
    Rect *pRect = new Rect;

    GetFun(pSquare);
    GetFun(pCircle);
    GetFun(pRect);

    delete pCircle;
    delete pSquare;
    delete pRect;

    return 0; 
}
 