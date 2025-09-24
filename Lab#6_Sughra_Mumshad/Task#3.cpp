#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	fstream fileout("student.txt");
	fileout<<"Sughra , 13\n";
	fileout<<"Amna , 10\n";
	fileout<<"Momina, 15\n";
	fileout.close();
	
	fstream filein("student.txt");
	 string s;
    cout << "Student Details:" << endl;
    while (getline(filein, s)) {
        cout << s << endl;
    }
	
	filein.close();
	
	return 0;
}