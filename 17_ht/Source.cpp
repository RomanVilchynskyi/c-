#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*ofstream outFile1("file1.txt"), outFile2("file2.txt");

    outFile1 << "String 1\n";
    outFile1 << "String 2\n";
    outFile1 << "String 3\n";
    outFile1.close();

    outFile2 << "String 1\n";
    outFile2 << "String 2\n";
    outFile2 << "Ibakcb 3\n";  
    outFile2.close();

    ifstream file1("file1.txt"), file2("file2.txt");

    string line1, line2;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            cout << "file1.txt: " << line1 << "\n";
            cout << "file2.txt: " << line2 << "\n";
        }
    }

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Error" << endl;    
    }

    string l1, l2;

    while (getline(file1, l1) && getline(file2, l2)) {
        if (l1 != l2) {
            cout << "file1.txt: " << l1 << "\n";
            cout << "file2.txt: " << l2 << "\n";
        }
    }*/


    //2
    ifstream inputFile("file3.txt");
    ofstream outputFile("res.txt");

    if (!inputFile.is_open()) {
        cout << "Error" << endl;
    }

    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;
    string line;

    while (getline(inputFile, line)) {
        lineCount++; 
        for (size_t i = 0; i < line.length(); i++) {
            char ch = line[i];

            if (!isspace(ch)) charCount++; 

            char lowerCh = tolower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u' || lowerCh == 'y') {
                vowelCount++;
            }
            else if (isalpha(ch)) {
                consonantCount++;  
            }

            if (isdigit(ch)) {
                digitCount++; 
            }
        }
    }

    outputFile << "Symbols: " << charCount << endl;
    outputFile << "Lines: " << lineCount << endl;
    outputFile << "Vowels: " << vowelCount << endl;
    outputFile << "Consonants: " << consonantCount << endl;
    outputFile << "Numbers: " << digitCount << endl;

    inputFile.close();
    outputFile.close();



}