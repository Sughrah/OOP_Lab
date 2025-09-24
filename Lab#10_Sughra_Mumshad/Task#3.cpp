#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream source("notes.txt");       // Source file
    ofstream dest("copy_notes.txt");    // Destination file

    string line;
    while (getline(source, line)) {
        dest << line << endl;
    }

    source.close();
    dest.close();

    cout << "File copied successfully.\n";
    return 0;
}
