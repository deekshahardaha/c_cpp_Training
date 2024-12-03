#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Rectangle {
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const {
        return width * height;
    }
};

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

int main26() {
    vector<Point> points = { {3, 4}, {1, 2}, {5, 0}, {2, 3} };

    // Sort points based on the x coordinate using a lambda function
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    cout << "Points sorted by x coordinate:\n";
    for (const auto& point : points) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }


    //==============================================//


    std::vector<Rectangle> rectangles = {
        {3.0, 4.0},
        {1.5, 2.0},
        {5.0, 2.0},
        {2.0, 3.0}
    };

    // Sort rectangles based on area using a lambda function
    std::sort(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return a.area() < b.area(); // Compare based on area
    });

    std::cout << "Rectangles sorted by area:\n";
    for (const auto& rect : rectangles) {
        std::cout << "Width: " << rect.width << ", Height: " << rect.height << ", Area: " << rect.area() << "\n";
    }

    return 0;
}