#include<iostream>
using namespace std;

class Employee{
//access specifier
private:
int id;
string name;
float salary;

//access specifier
public:
//Default Constructor
Employee ( ){
	id=0;
	name="unknown";
	salary=0;
}
//
//display account details
void displayDetails(){
	cout<<"Id: "<<id<<endl<<"Name: "<<name<<endl<<"salary: "<<salary<<endl;
}

};
