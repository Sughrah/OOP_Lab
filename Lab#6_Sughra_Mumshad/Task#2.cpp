#include<iostream>
#include<fstream>
using namespace std;
int main(){
	fstream file;
	file.open("notes.txt");
	string line;
	int count=0;
	while(getline(file,line)){
		count++;
	}
	cout<<"Total lines are: "<<line<<count<<endl;
	file.close();
	
	return 0;
}