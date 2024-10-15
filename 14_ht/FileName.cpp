#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

bool isPalindrome(const char* str) {
    unsigned int length = strlen(str);

    for (unsigned int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

unsigned int countWords(const char* sentence) {
    unsigned int wordCount = 0;
    bool inWord = false;

    for (size_t i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\n' && sentence[i] != '\t') {
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        }

        else {
            inWord = false;
        }
    }

    return wordCount;
}

unsigned int strLen(const char* str)
{
    unsigned int counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

string truncate(const string& str, size_t maxLength) {
    const char* suffix = "...";
    size_t suffixLength = strlen(suffix);
    size_t strLength = 0;
    while (str[strLength] != '\0') {
        ++strLength;
    }

    if (strLength <= maxLength) {
        return str;
    }

    char buffer[256];
    size_t copyLength = maxLength - suffixLength;

    strncpy_s(buffer, copyLength + 1, &str[0], copyLength);
    buffer[copyLength] = '\0';

    return string(buffer) + suffix;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char line1[] = "orange";
    char line2[] = "lemon";
    //1
    cout << line1 << " > " << line2 << "\t" << strcmp(line1, line2) << endl;
    cout << line2 << " < " << line1 << "\t" << strcmp(line2, line1) << endl;
    cout << line2 << " = " << line2 << "\t" << strcmp(line2, line2) << endl;

    //2
    string line3 = "orange";
    line3[0] = (char)toupper(line3[0]);
    cout << "orange = " << line3 << endl;

    //3
    char vowels[]{ 'a', 'e', 'i', 'o', 'u', 'y' };
    const int vowelCount = 7;
    unsigned int counter = 0;

    unsigned int length = strLen(line1);

    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < vowelCount; j++)
        {
            if (line1[i] == vowels[j]) {
                counter++;
            }
        }
    }

    cout << line1 << " have " << counter << " wovels" << endl;

    //4
    string result = truncate("Hello, world!", 8);
    cout << result << endl; 
    //5
    char line4[] = "level";
    char line5[] = "levels";
    cout << line4 << " is palindrom: " << boolalpha << isPalindrome(line4) << endl;
    cout << line5 << " is palindrom: " << boolalpha << isPalindrome(line5) << endl;

    //6
    const char* sentence = "apple juice \n";
    unsigned int wordCount = countWords(sentence);

    cout << sentence << "Words: " << wordCount << endl;
}

//1. �������� �������, ��� ������ 2 ����� �� ������� �� �������.������� ������� 1, ���� ������� ����� ����� �������, �� � �������; -1 - ���� � ����� ����� �������, �� � ������; ��� 0 � ���� ����� �������� �������.
//2. �������� �������, ��� ���������� � ������ ������ ������ ������ ���������� �����.
//3. �������� �������, ��� ���� ������� �������� ���� � ���������� �����.
//4. �������� ������� ���������� �����.������� ������ ����� �� ���� ����������� �������.���� ������� ����� �����, �� �����������, ��������� �������� ���� �������, ������� ������ ��� ��� ������.���������: truncate(�Hello, world!�, 8) �� ��������� �Hello...�.
//5. �������� �������, ��� ��������, �� � ��������� ����� ����������.
//6. �������� �������, ��� ���� ������� ��� � ������.
//7. �������� �������, ��� ������� �������� ����� � �������.
//8. �������� �������, ��� ���� ������� ������� ����� � ������.
//9. �������� �������, ��� ������ ����� �� ������ �� �������� �������, �� ����� ����������� ��� ������ � �����.����� �������, ������ ���� ����������� ��� ������ � �����.