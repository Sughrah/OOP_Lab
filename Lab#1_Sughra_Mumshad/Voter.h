#include<iostream>
using namespace std;
//Defined data members
class Voter{
	private:
	string name;
	int age;
	
	public:
//Defined member functions
	void setData();
	bool isEligible();
	
};
//Initliaze member functions
void Voter::setData(){
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter age: ";
	cin>>age;
	
}

bool Voter::isEligible(){ 
return age>18;
}