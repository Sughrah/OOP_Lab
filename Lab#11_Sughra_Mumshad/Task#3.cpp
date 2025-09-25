#include<iostream>
#include<fstream>
using namespace std;
int main(){
	fstream file("student.txt" ,ios::in | ios::out|ios::trunc);
	file<<"01, Ali, 3.5 ";
	file<<"02, Alisha, 3.4";
	file<<"03, Noor, 3.0 ";
    file<<"04, Zahid, 4.0 ";
	cout<<"Position of write pointer after writting : "<<file.tellp()<<endl;
	file.seekp(-13, ios::cur);
	file<<"05,Tahir,2.78";
	file.close();
	return 0;
}
