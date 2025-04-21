#include<iostream>
using namespace std;
//Defined Class
class Calculator{
//Defined data members
	public:
	    float num1;
	    float num2;
//Defined mmember functions
	public:
		void setNumber(){
			cout<<"Enter first Number: ";
			cin>>num1;
			cout<<"Enter Second Number: ";
			cin>>num2;
			
		}
	float add(){
		return num1+num2;
	}
	float subtract(){
		return num1-num2;
	}
	float multiply(){
		return num1*num2;
	}
	float divide(){
		if(num2!=0){
			return num1/num2;
		}else{
			cout<<"Error!division by zero.";
		}
	}
};
