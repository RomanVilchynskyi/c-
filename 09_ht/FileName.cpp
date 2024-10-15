#include <iostream>

using namespace std;

template <typename T>
void fillArray(T arr[], size_t length, int min = 1, int max = 10)
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = (min + rand() % (max - min + 1))/1.0;
    }
}

double getRandomDouble(double min, double max) {
    double random = (double)rand() / RAND_MAX;  
    return min + random * (max - min);  
}

//a
//template <typename T>
//void inputArray(T arr[], int length) {
//	for (int i = 0; i < length; i++) {
//		cout << "Enter element " << i + 1 << ": ";
//		cin >> arr[i];
//	}
//}

//b
template <typename T>
void printarr(T arr[], int length) {
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << "\t";
    }cout << endl;
}

//c
template <typename T>
int indexOf(T arr[], size_t length, T key, int start = 0)
{
    for (size_t i = start; i < length; i++)
    {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

//d
template <typename T>
int indexOf2(T arr[], size_t length, T key, int start = -1)
{
    if (start == -1 || start >= (int)length) {
        start = length - 1;
    }

    for (int i = start; i >= 0; i--) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

//e
template <typename T>
void shufflearray(T arr[], int length) {
    for (size_t i = 0; i < 2; i++)
    {
        for (int i = 0; i < length; i++) {
            int randomIndex1 = rand() % length;
            int randomIndex2 = rand() % length;
            T temp = arr[randomIndex1];
            arr[randomIndex1] = arr[randomIndex2];
            arr[randomIndex2] = temp;
        }
    }
}

//f
template <typename T>
void printarr2(T arr[], int length, int index) {
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = index;
        cout << arr[i] << "\t";
    }cout << endl;
}

//g
template <typename T>
void sortup(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//h
template <typename T>
void sortdown(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));
    const int size = 5;
    int intArr[size]{};
    double doubleArr[size];
    char charArr[size];
    string strArr[size];

    //a
    /*cout << "Enter 5 integers: ";
    inputArray(intArr, 5);
    cout << "Enter 5 doubles: ";
    inputArray(doubleArr, 5);
    cout << "Enter 5 characters: ";
    inputArray(charArr, 5);
    cout << "Enter 5 strings: ";
    inputArray(strArr, 5);*/

    //b
    cout << "5 random numbers\n";
    fillArray(intArr, size);
    printarr(intArr, size);
    /*for (int i = 0; i < 5; i++) {
        double randomValue = getRandomDouble(1.0, 10.0);
        cout << randomValue << "\t";
    }cout << endl;
    fillArray(charArr, size);
    printarr(charArr, size);
    fillArray(strArr, size);
    printarr(strArr, size);*/

    //c
    cout << "First occurrence of 5 in int array: " << indexOf(intArr, 5, 5) << endl;
    //d
    cout << "Last occurrence of 8 in int array: " << indexOf2(intArr, 5, 8) << endl;

    //e
    shufflearray(intArr, 5);  
    cout << "Shuffled int array: " << endl;
    printarr(intArr, 5);

    //f
   /* cout << "Array with 10: " << endl;
    printarr2(intArr, 5, 10);*/

    //g
    sortup(intArr, 5); 
    cout << "Sorted int array in ascending order: "<<endl;
    printarr(intArr, 5);

    //h
    sortdown(intArr, 5);
    cout << "Sorted array in descending order: " << endl;
    printarr(intArr, 5);
}