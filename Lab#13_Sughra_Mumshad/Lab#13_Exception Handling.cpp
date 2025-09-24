#include<iostream>
#include<stdexcept>
using namespace std;


int main(){
try{
	
		int numenator , denominator;
		cout<<"Enter Numenator: ";
		cin>>numenator;
		cout<<"Enter Denomenator: ";
		cin>>denominator;
		
	if(denominator==0){
		throw 0;	
} 
    double divide= numenator / denominator;
    cout<<divide<<endl;}
    catch(int value){
	cout<<"Divided by 0 is not possible"<<endl;
}
 return 0;

}