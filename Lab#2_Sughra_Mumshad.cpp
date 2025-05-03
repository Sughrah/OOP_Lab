//#include<iostream>
//#include<string>
//using namespace std;
//// 
////                                Task#1: Default constructor
//class Employee{
////access specifier
//private:
//int id;
//string name;
//float salary;
//
////access specifier
//public:
////Default Constructor
//Employee ( ){
//	id=0;
//	name="unknown";
//	salary=0;
//}
//
////display account details
//void displayDetails(){
//	cout<<"Id: "<<id<<endl<<"Name: "<<name<<endl<<"salary: "<<salary<<endl;
//}
//
//};
//
//int main(){
////	call default constructror
//    Employee Emp;
//    Emp.displayDetails();
//    
//    return 0;
//}

//                              Task#2: Parameterized  Constructor

//#include <iostream>
//#include <string>
//using namespace std;
//
//class BankAccount {
////access specifier
//private:
//    string accountNum;
//    string accountHolder;
//    double balance;
//
////access specifier
//public:
////parameterized constructor
//    BankAccount(string accNum, string accHolder, double bal) {
//        accountNum = accNum;
//        accountHolder = accHolder;
//        balance = bal;
//    }
//
////display account details
//    void showAccountDetails() {
//        cout << "Account Number is: " << accountNum<< endl;
//        cout << "Account Holder is: " << accountHolder<< endl;
//        cout << "Balance: " << balance << endl;
//    }
//};
//
//int main() {
//    // Creating object with user-defined values
//    BankAccount account("PK0309800780100", "Muhammad Awais", 10000);
//
//    // Displaying account details
//    account.showAccountDetails();
//
//    return 0;
//}

//                          Task#3: Constructor Overloading

//#include <iostream>
//using namespace std;
//
//class Rectangle {
////access specifier
//private:
//    float length;
//    float width;
////access specifier
//public:
//    // Default constructor
//    Rectangle() {
//        length = 1.0;
//        width = 1.0;
//    }
//
//    // Parameterized constructor (two parameters)
//    Rectangle(float l, float w) {
//        length = l;
//        width = w;
//    }
//
//    //Parameterized constructor (square)
//    Rectangle(float side) {
//        length = side;
//        width = side;
//    }
//
//    //calculate area
//    float area() {
//        return length * width;
//    }
//
//    //display dimensions
//    void display() {
//        cout << "Length: " << length << ", Width: " << width << endl;
//    }
//};
//
//int main() {
//    // Object using default constructor
//    Rectangle rect1;
//    rect1.display();
//    cout << "Area: " << rect1.area() << endl << endl;
//
//    // Object(two parameters)
//    Rectangle rect2(5.5, 3.0);
//    rect2.display();
//    cout << "Area: " << rect2.area() << endl << endl;
//
//    // Object(square)
//    Rectangle rect3(7.5);
//    rect3.display();
//    cout << "Area: " << rect3.area() << endl;
//
//    return 0;
//}

//                                    Task#4:Destructorr

#include<iostream>
using namespace std;

class Locker{
//access specifier
public:
	
//	constructor
	Locker(){
	cout<<"Locker allocated to customer.."<<endl;
}

//    destructor
    ~Locker(){
    	cout<<"Locker returned by user.."<<endl;
	}

};

int main(){
//create locker on stack
    {
	Locker locker1;
//	automatic destructor call
	}
// create locker on heap
    Locker* locker2= new Locker();
	delete locker2;
	 
	 return 0;
}
