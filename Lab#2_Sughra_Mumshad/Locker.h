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