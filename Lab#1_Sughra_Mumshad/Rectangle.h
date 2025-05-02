#include<iostream>
using namespace std;

//Defined data memebers
class Rectangle{
	private:
	   int length;
	   int width;
	
//defined member functions
    public:
	void setDimensions();
	int area();
	int perimeter();
};
//Initialize member functions
void Rectangle::setDimensions(){
	cout<<"Enter Rectangle's length: ";
	cin>>length;
	cout<<"\nEnter Rectangle's width: ";
	cin>>width;	
}

int Rectangle::area(){
	return length*width;
}

int Rectangle::perimeter(){
	return 2*(length+width);
}
