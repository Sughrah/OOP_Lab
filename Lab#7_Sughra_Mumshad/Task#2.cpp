#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        // Normalize inches (if inches >= 12)
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    // Overload == operator
    bool operator==(const Distance &d) const {
        return (feet == d.feet && inches == d.inches);
    }

    // Display function
    void display() const {
        cout << feet << " feet " << inches << " inches";
    }
};

int main() {
    Distance d1(5, 8);
    Distance d2(5, 8);
    Distance d3(6, 2);

    cout << "Distance 1: "; d1.display(); cout << endl;
    cout << "Distance 2: "; d2.display(); cout << endl;
    cout << "Distance 3: "; d3.display(); cout << endl;

    if (d1 == d2)
        cout << "Distance 1 and Distance 2 are equal." << endl;
    else
        cout << "Distance 1 and Distance 2 are not equal." << endl;

    if (d1 == d3)
        cout << "Distance 1 and Distance 3 are equal." << endl;
    else
        cout << "Distance 1 and Distance 3 are not equal." << endl;

    return 0;
}

