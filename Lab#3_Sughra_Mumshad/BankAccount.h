#include<iostream>
using namespace std;

class BankAccount{
	public:
	   double *balance;
	public:
//	   Constructor
	 BankAccount(double b){
	 	balance = new double(b);
	 	*balance = b;
	 }
	 
//     Default Function
void display(){

	cout<<"Balance is:"<<*balance<<endl;
}

//     Modified function
void setBalance(double b){
	*balance = b;
}

//       Destructor
		~BankAccount(){
		delete balance;
    	cout<<"Destructor called for balance."<<endl;
    
	}
	 
	 
};
