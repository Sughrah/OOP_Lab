#include <iostream>
using namespace std;

class Rectangle {
//access specifier
private:
    float length;
    float width;
//access specifier
public:
    // Default constructor
    Rectangle() {
        length = 1.0;
        width = 1.0;
    }

    // Parameterized constructor (two parameters)
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    //Parameterized constructor (square)
    Rectangle(float side) {
        length = side;
        width = side;
    }

    //calculate area
    float area() {
        return length * width;
    }

    //display dimensions
    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};