#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    ofstream outFile("notes.txt"); // open file in write mode
    outFile << "This is the first line.\n";
    outFile << "This is the second line.\n";
    outFile.close();
    cout << "File created and lines written.\n";


    ifstream inFile("notes.txt");
    string line;
    cout << "\n--- File Content Before Append ---\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    ofstream appendFile("notes.txt", ios::app);
    appendFile << "\nName: Ali Khan, Roll No: 123";
    appendFile.close();

    inFile.open("notes.txt");
    cout << "\n--- File Content After Append ---\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
