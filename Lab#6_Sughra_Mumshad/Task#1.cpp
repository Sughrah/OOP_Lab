#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Create and write to the file
    fstream fileout("notes.txt", ios::out);
    fileout << "My name is Sughra." << endl;
    fileout << "I live in Dhirkot." << endl;
    fileout << "I am a student of software engineering." << endl;
    fileout.close();

    // Read 
    cout << "Initial file contents:" << endl;
    fstream filein("notes.txt", ios::in);
    string s;
    while (getline(filein, s)) {  
        cout << s << endl;
    }
    filein.close();

    // Append new content 
    fstream fileapp("notes.txt", ios::app);
    fileapp << "My roll number is 13." << endl; 
    fileapp.close();

    
    cout << "\nFinal file contents:" << endl;
    fstream file("notes.txt", ios::in);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();

    return 0;
}