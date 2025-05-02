#include<iostream>
using namespace std;
//defined member data
class Student{
	private:
	string name;
	int rollNumber;
	float marks;
	public:
//defined member functions
	void getData(){
		cout<<"Enter student name: ";
		cin>>name;
		cout<<"Enter student Roll No: ";
		cin>>rollNumber;
		cout<<"Enter student marks: ";
		cin>>marks;
	}
	void displayData(){
		cout<<" Name:"<<name<<endl;
		cout<<"Roll No:"<<rollNumber<<endl;
		cout<<"Marks:"<<marks<<endl;
	}
	
};