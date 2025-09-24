#include <iostream>
#include <cmath>
using namespace std;

class Circle;  // Forward declaration

class Rectangle {
private:
    float length;
    float width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }
    // Friend function declaration
    friend float totalArea(Rectangle r, Circle c);
};

class Circle {
private:
    float radius;
public:
    Circle(float r) {
        radius = r;
    }
    // Friend function declaration
    friend float totalArea(Rectangle r, Circle c);
};

// Friend function definition
float totalArea(Rectangle r, Circle c) {
    float rectArea = r.length * r.width;
    float circleArea = 3.14159f * c.radius * c.radius;
    return rectArea + circleArea;
}

int main() {
    Rectangle rect(10, 5);   // length=10, width=5
    Circle cir(7);           // radius=7

    cout << "Total Area of Rectangle + Circle = " << totalArea(rect, cir) << endl;
    return 0;
}
