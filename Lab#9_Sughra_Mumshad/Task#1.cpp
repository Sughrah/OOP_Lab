#include <iostream>
using namespace std;

class Demo {
private:
    static int count;   // Static data member
public:
    Demo() {            // Constructor
        count++;        // Increment count whenever an object is created
        cout << "Object created. Current count = " << count << endl;
    }

    void showCount() {
        cout << "Count accessed through object = " << count << endl;
    }
};

// Define static member outside the class
int Demo::count = 0;

int main() {
    Demo d1;  // first object
    Demo d2;  // second object
    Demo d3;  // third object

    d1.showCount();
    d2.showCount();
    d3.showCount();

    return 0;
}