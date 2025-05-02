#include<iostream>
using namespace std;

class Temprature{
//defined data members
	public:
	float celsius;
//defined data functions
	float toFahrenhiet(){
		return (celsius * 9/5)+32;
	}
	void displayFahrenhiet(){
		float fahrenhiet = toFahrenhiet() ;
		cout<<"\nTemprature in farenhiet will be: "<<fahrenhiet;
	}
};
