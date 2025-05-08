#include<iostream>
using namespace std;

class Person{
	protected:
        string name;
	    int age;
	public:
	    void setPerson(string n, int a){
		name = n;
		age = a;
	}
	void showPerson(){
		cout<<"Name :"<<name<<endl;
		cout<<"Age :"<<age<<endl;
	}
};
class Student: public Person{
	int rollNo;
	public:
		void setStudent(string n, int a,int R){
			setPerson("Sughra", 18);
			rollNo = R;
		}
	public: 
	    void showStudent(){
	    	showPerson();
		    cout<<"Roll No: "<<rollNo<<endl;
		}
};