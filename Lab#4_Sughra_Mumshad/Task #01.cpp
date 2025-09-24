#include <iostream>
using namespace std;

// Base class
class Employee {
public:
    virtual double calculateSalary() {
        cout << "Base Employee salary calculation called." << endl;
        return 0;
    }
    virtual ~Employee() {} // Virtual destructor for proper cleanup
};

// Derived class for permanent employees
class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double bonus;

public:
    PermanentEmployee(double bs, double b) : basicSalary(bs), bonus(b) {}

    double calculateSalary() override {
        return basicSalary + bonus;
    }
};

// Derived class for contract employees
class ContractEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    ContractEmployee(double hr, double hw) : hourlyRate(hr), hoursWorked(hw) {}

    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    // Create employee objects
    PermanentEmployee pe(40000, 5000);
    ContractEmployee ce(800, 30);

    // Use base class pointers for polymorphic behavior
    Employee* emp1 = &pe;
    Employee* emp2 = &ce;

    // Calculate and display salaries
    cout << "Permanent Employee Salary: " << emp1->calculateSalary() << endl;
    cout << "Contract Employee Salary: " << emp2->calculateSalary() << endl;

    return 0;
}