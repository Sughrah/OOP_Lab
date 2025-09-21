#include<iostream>
using namespace std;

//                                  TASK#1: Shallow Copy

//class BankAccount{
//	public:
//	   double *balance;
//	public:
////	   Constructor
//	 BankAccount(double b){
//	 	balance = new double(b);
//	 	*balance = b;
//	 }
//	 
////     Default Function
//void display(){
//
//	cout<<"Balance is:"<<*balance<<endl;
//}
//
////     Modified function
//void setBalance(double b){
//	*balance = b;
//}
//
////       Destructor
//		~BankAccount(){
//		delete balance;
//    	cout<<"Destructor called for balance."<<endl;
//    
//	}
//	 
//	 
//};
//int main(){
//	BankAccount b1(5000.00);
////		shallow copy
//	BankAccount b2 = b1;  
//    b2.setBalance(6000.00);
//    cout<<"Account 1 :";
//    b1.display();
//    cout<<"Account 2 :";
//    b2.display();
//
//	return 0;
//	
//}
//

//                        TASK#2: Deep Copy

//#include<iostream>
//using namespace std;
//
//class BankAccount{
//	private:
//	   double *balance;
//	public:
//    constructor
//	 BankAccount(double b){
//	 	balance = new double(b);
//        *balance = b;
//	 }
//	 
//	BankAccount(const BankAccount &b){
//		balance = new double;
//		*balance= *(b.balance);
//	}
//Default function
//void display(){
//
//	cout<<"Balance is:"<<*balance<<endl;
//}
//Modified function
//void setBalance(double b){
//	*balance = b;
//}
//     destructor
//    ~BankAccount(){
//        delete balance;
//    	cout<<"Destructor called for balance."<<endl;
//    	
//	}
//	 
//	 
//};
//int main(){
//	BankAccount b1(5000.00);
//     deep copy
//    BankAccount b2 = b1;
//    b2.setBalance(6000.00);
//    
//    cout<<"Account 1: ";
//    b1.display();
//    
//    cout<<"Account 2: ";
//    b2.display();
//
//
//	
//	return 0;
//	
//}
//
//                            TASK#3: Single Inheritance

//#include<iostream>
//using namespace std;
//
//class Person{
//	protected:
//        string name;
//	    int age;
//	public:
//	    void setPerson(string n, int a){
//		name = n;
//		age = a;
//	}
//	void showPerson(){
//		cout<<"Name :"<<name<<endl;
//		cout<<"Age :"<<age<<endl;
//	}
//};
//class Student: public Person{
//	int rollNo;
//	public:
//		void setStudent(string n, int a,int R){
//			setPerson("Sughra", 18);
//			rollNo = R;
//		}
//	public: 
//	    void showStudent(){
//	    	showPerson();
//		    cout<<"Roll No: "<<rollNo<<endl;
//		}
//};
//
//int main(){
//	Student std;
//	std.setStudent("Sughra", 18,13);
//	std.showStudent();
//	
//	return 0;
//}

//                        TASK#4 : Constructor in Inheritance
//#include<iostream>
//using namespace std;
//
//class Shape{
//	public:
//	Shape(){
//		cout<<"Shape constructor called"<<endl;
//	}
//};
//class Rectangle : public Shape{
//	public:
//	Rectangle(){
//			cout<<"Rectangular constructor called"<<endl;
//	}
//};
//
//int main(){
//	Rectangle rec;
//	
//	return 0;
//}