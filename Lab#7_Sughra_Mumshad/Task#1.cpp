
#include <iostream>
using namespace std;

class Calculator {
public:
    // Add functions
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }

    // Multiply functions
    int multiply(int a, int b) {
        return a * b;
    }
    double multiply(double a, double b) {
        return a * b;
    }

    // Subtract functions
    int subtract(int a, int b) {
        return a - b;
    }
    double subtract(double a, double b) {
        return a - b;
    }

    // Divide functions
    double divide(int a, int b) {
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return (double)a / b;
    }
    double divide(double a, double b) {
        if (b == 0.0) {
            cout << "Error: Division by zero!" << endl;
            return 0.0;
        }
        return a / b;
    }
};

int main() {
    Calculator calc;

    cout << "Integer Add: " << calc.add(10, 5) << endl;
    cout << "Double Add: " << calc.add(10.5, 5.3) << endl;

    cout << "Integer Multiply: " << calc.multiply(4, 5) << endl;
    cout << "Double Multiply: " << calc.multiply(4.2, 5.1) << endl;

    cout << "Integer Subtract: " << calc.subtract(15, 5) << endl;
    cout << "Double Subtract: " << calc.subtract(15.5, 5.2) << endl;

    cout << "Integer Divide: " << calc.divide(10, 2) << endl;
    cout << "Double Divide: " << calc.divide(22.5, 7.5) << endl;

    return 0;
}
