#include<iostream>
using namespace std;
class Product{
	private:
		string name;
		double price;
		int quantity;
	public:
//		setters
        void empty();
		void setName(string n){
			if(n.empty()){
				cout<<"Error! Name cannot be empty."<<endl;
			}else{
				name = n;
			}
		}
		void setPrice(double p){
			if(p>0){
				price = p;
			}else{
				cout<<"\nError! Price must be greater than zero."<<endl;
			}
		}
		void setQuantity(int q){
			if(q>=0){
				quantity=q;
			}else{
				cout<<"Error ! Quanity must be greater than zero."<<endl;
			}
		}
		
//		Getters

        string getname(){
        	return name;
		}
		double getprice(){
			return price;
		}
		int getquantity(){
			return quantity;
		}
};