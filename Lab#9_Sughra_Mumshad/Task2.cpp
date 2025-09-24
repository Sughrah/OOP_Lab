#include <iostream>
using namespace std;

class Demo {
private:
    static int count;   // Static data member
public:
    Demo() {            // Constructor
        count++;
    }

    // Static function to print total number of objects
    static void print() {
        cout << "Total objects created so far = " << count << endl;
    }
};

// Define static member outside the class
int Demo::count = 0;

int main() {
    Demo::print(); // No objects yet

    Demo d1;  // 1st object
    Demo::print(); // Called using class name

    Demo d2, d3;  // 2nd and 3rd object
    Demo::print();

    // Can also call using object (not recommended but possible)
    d1.print();

    return 0;
}