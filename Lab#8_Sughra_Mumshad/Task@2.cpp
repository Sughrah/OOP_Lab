#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;  
    // Virtual destructor for good practice
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}

    void draw() override {
        cout << "Drawing Rectangle of length " << length
             << " and width " << width << endl;
    }
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}

    void draw() override {
        cout << "Drawing Circle of radius " << radius << endl;
    }
};

int main() {
    Shape* s1 = new Rectangle(10, 5);
    Shape* s2 = new Circle(7);

    s1->draw();
    s2->draw();

    delete s1;
    delete s2;
    return 0;
}