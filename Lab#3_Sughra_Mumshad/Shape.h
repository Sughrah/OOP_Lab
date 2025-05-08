#include<iostream>
using namespace std;

class Shape{
	public:
	Shape(){
		cout<<"Shape constructor called"<<endl;
	}
};
class Rectangle : public Shape{
	public:
	Rectangle(){
			cout<<"Rectangular constructor called"<<endl;
	}
};