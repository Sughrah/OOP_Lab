#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream studentFile("students.txt");

    // Writing details of 3 students
    studentFile << "Name: Ali, Roll No: 101\n";
    studentFile << "Name: Sara, Roll No: 102\n";
    studentFile << "Name: Ahmed, Roll No: 103\n";
    studentFile.close();

    // Reading and displaying student details
    ifstream readFile("students.txt");
    string line;
    cout << "\n--- Student Details ---\n";
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();

    return 0;
}
