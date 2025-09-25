#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open file for both reading and writing
    fstream file("student.txt", ios::in | ios::out);

    if (!file) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    cout << "Position of read pointer before reading: " << file.tellg() << endl;

    char ch;

    cout << "Move the read pointer position to 13" << endl;
    file.seekg(13); // Move read pointer to position 13

    // Read characters one by one
    while (file.get(ch)) {
        cout << "Character Read: " << ch
             << " Position of pointer after reading: " << file.tellg() << endl;
    }

    file.close();
    return 0;
}

