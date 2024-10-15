#include <iostream>
//#include <cstring>
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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*char word[5];
    word[0] = 'P';
    word[1] = 'l';
    word[2] = 'u';
    word[3] = 'm';
    word[4] = '\0';
    cout << word << endl;*/

    //char word_1[]{ 'P','l','u','m','\0' };
    //cout << word_1 << endl;

    //char word_1[] = "Plum";
    //cout << word_1 << endl;

    ////word_1 = "Apple"; error
    ///*word_1[0] = 'A';
    //word_1[1] = 'p';
    //word_1[2] = 'p';
    //word_1[3] = 'l';
    //word_1[4] = 'e';*/
    ////word_1[5] = '\0';
    //for (size_t i = 0; i < strLen(word_1); i++)
    //{
    //    cout << word_1[i] << "\t";
    //}
    //cout << endl;
    //cout << "length {Hello World} :: " << strLen("Hello World") << endl;

    //cout << "\n===================== strlen() ========================\n";

    //char word_2[50] = "Apple";
    //cout << "\t Length " << word_1 << " :: " << strlen(word_1) << endl;
    //cout << "\t Length " << word_2 << " :: " << strlen(word_2) << endl;

    //cout << "word_1 :: " << word_1 << endl;
    //cout << "word_2 :: " << word_2 << endl;

    //cout << "\n===================== strcpy_s() ========================\n";

    ////strcpy_s(word_1, word_2); // error
    //strcpy_s(word_2, word_1);
    //cout << "word_1 :: " << word_1 << endl;
    //cout << "word_2 :: " << word_2 << endl;
    //cout << endl;
    //strcpy_s(word_2, "Hello");
    //cout << "word_1 :: " << word_1 << endl;
    //cout << "word_2 :: " << word_2 << endl;


    //strncpy_s(word_2, "purple", 4);
    //cout << "word_1 :: " << word_1 << endl;
    //cout << "word_2 :: " << word_2 << endl;

    //const int size = 50;
    //char* one = new char[size];
    //strcpy_s(one, strlen("Yellow") + 1, "Yellow");
    //cout << one << endl;

    //cout << "\n===================== strcat_s() ========================\n";
    //strcat_s(one, size, ", red");
    //cout << one << endl;
    //strcat_s(word_2, " World !!!");
    //cout << "word_1 :: " << word_1 << endl;
    //cout << "word_2 :: " << word_2 << endl;

    //strncat_s(word_2, "Test", 2);
    //cout << "word_1 :: " << word_1 << endl;
    //cout << "word_2 :: " << word_2 << endl;

    //cout << "\n===================== strcmp() ========================\n";
    //char a[] = "AbD";
    //char b[] = "Abd";
    //cout << a << "\t" << b << "\t" << strcmp(a, b) << endl; // -1 (a < b), 1 (a > b), 0 (a==b);
    //cout << a << "\t" << b << "\t" << strncmp(a, b, 2) << endl; // -1 (a < b), 1 (a > b), 0 (a==b);
    /////////////////////////////////////////

    //char line[] = "df HTG@#!123";
    //cout << "\n===================== isalpha(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << isalpha(line[i]) << " :: " << boolalpha << (bool)isalpha(line[i]) << endl;
    //}

    //cout << "\n===================== isdigit(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << isdigit(line[i]) << " :: " << boolalpha << (bool)isdigit(line[i]) << endl;
    //}

    //cout << "\n===================== isalnum(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << isalnum(line[i]) << " :: " << boolalpha << (bool)isalnum(line[i]) << endl;
    //}

    //cout << "\n===================== isspace(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << isspace(line[i]) << " :: " << boolalpha << (bool)isspace(line[i]) << endl;
    //}

    //cout << "\n===================== ispunct(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << ispunct(line[i]) << " :: " << boolalpha << (bool)ispunct(line[i]) << endl;
    //}

    //cout << "\n===================== islower(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << islower(line[i]) << " :: " << boolalpha << (bool)islower(line[i]) << endl;
    //}

    //cout << "\n===================== isupper(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << isupper(line[i]) << " :: " << boolalpha << (bool)isupper(line[i]) << endl;
    //}

    //////////////////
    //cout << "\n===================== tolower(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << (char)tolower(line[i]) << endl;
    //}

    //cout << "\n===================== toupper(char) ========================\n";
    //for (size_t i = 0; i < strlen(line); i++)
    //{
    //    cout << "\t" << line[i] << " :: " << (char)toupper(line[i]) << endl;
    //}
    ////cin >> a >> b >> c;

    //char str[100];
    //cout << "Enter str --> ";
    //cin >> str;
    //cout << "Result read :: " << str << endl;
    //cout << "Enter str --> ";
    //cin >> str;
    //cout << "Result read :: " << str << endl;
    //cout << "Enter str --> ";
    //cin >> str;
    //cout << "Result read :: " << str << endl;
    //cout << "Enter str --> ";
    //cin.clear();
    //cin.ignore();
    //cin.getline(str, 100);
    //cout << "Result read :: " << str << endl;


    //string text;
    //cout << "Enter --> ";
    //cin >> text;
    //cout << "Result text --> " << text << endl;
    //cout << "Enter --> ";
    //cin.clear();
    //cin.ignore();
    //getline(cin, text);
    //cout << "Result text --> " << text << endl;

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
    char vowels[]{'a', 'e', 'i', 'o', 'u', 'y'};
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
    //5
    char line4[] = "level";
    char line5[] = "levels";
    cout << line4 << " is palindrom: " << boolalpha << isPalindrome(line4) << endl;
    cout << line5 << " is palindrom: " << boolalpha<<isPalindrome(line5)<< endl;

    //6
    const char* sentence = "apple juice";
    unsigned int wordCount = countWords(sentence);

    cout << "Words: " << wordCount << endl;
}

//1. Написати функцію, яка приймає 2 рядки та порівнює їх довжину.Функція повертає 1, якщо першому рядку більше символів, ніж у другому; -1 - якщо у другій більше символів, ніж у першій; або 0 – якщо рядки однакової довжини.
//2. Написати функцію, яка переводить у верхній регістр перший символ переданого рядка.
//3. Написати функцію, яка рахує кількість голосних літер у переданому рядку.
//4. Написати функцію скорочення рядка.Функція приймає рядок та його максимальну довжину.Якщо довжина рядка більша, ніж максимальна, необхідно відкинути зайві символи, додавши замість них три крапки.Наприклад: truncate(“Hello, world!”, 8) має повернути “Hello...”.
//5. Написати функцію, яка перевіряє, чи є переданий рядок паліндромом.
//6. Написати функцію, яка рахує кількість слів у реченні.
//7. Написати функцію, яка повертає найдовше слово з речення.
//8. Написати функцію, яка рахує середню довжину слова у реченні.
//9. Написати функцію, яка приймає рядок та символ та виводить індекси, за якими знаходиться цей символ у рядку.Також вивести, скільки разів зустрічається цей символ у рядку.