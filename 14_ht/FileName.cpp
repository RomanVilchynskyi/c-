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

//1. Написати функцію, яка приймає 2 рядки та порівнює їх довжину.Функція повертає 1, якщо першому рядку більше символів, ніж у другому; -1 - якщо у другій більше символів, ніж у першій; або 0 – якщо рядки однакової довжини.
//2. Написати функцію, яка переводить у верхній регістр перший символ переданого рядка.
//3. Написати функцію, яка рахує кількість голосних літер у переданому рядку.
//4. Написати функцію скорочення рядка.Функція приймає рядок та його максимальну довжину.Якщо довжина рядка більша, ніж максимальна, необхідно відкинути зайві символи, додавши замість них три крапки.Наприклад: truncate(“Hello, world!”, 8) має повернути “Hello...”.
//5. Написати функцію, яка перевіряє, чи є переданий рядок паліндромом.
//6. Написати функцію, яка рахує кількість слів у реченні.
//7. Написати функцію, яка повертає найдовше слово з речення.
//8. Написати функцію, яка рахує середню довжину слова у реченні.
//9. Написати функцію, яка приймає рядок та символ та виводить індекси, за якими знаходиться цей символ у рядку.Також вивести, скільки разів зустрічається цей символ у рядку.