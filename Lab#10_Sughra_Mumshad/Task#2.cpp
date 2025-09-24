#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("notes.txt");
    string line;
    int count = 0;

    while (getline(file, line)) {
        count++;
    }
    file.close();

    cout << "Number of lines in file: " << count << endl;
    return 0;
}
;

