#include<iostream>
#include<string>
#include<string>
#include"Employee.h"
#include"BankAccount1.h"
#include"Rectangle1.h"
#include"Locker.h"
using namespace std;
// 
//                                Task#1: Default constructor

//int main(){
////	call default constructror
//    Employee Emp;
//    Emp.displayDetails();
//    
//    return 0;
//}

//                              Task#2: Parameterized  Constructor


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
