#include <iostream>

using namespace std;

void copyarr(int* src, int* dest, size_t length) {
    for (size_t i = 0; i < length; i++) {
        *(dest + i) = *(src + i);  
    }
}



int main() {
    const int size = 5;
    int arr1[size] = { 1, 2, 3, 4, 5 }; 
    int arr2[size] = {};

    copyarr(arr1, arr2, size); 

	cout << "Orig: ";
	for (int i = 0; i < size; i++) {
		cout << arr1[i] << " ";
	}
	cout<< endl;
	cout << "Copy: ";
	for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
	
	//2
	/*int* ptr = arr1;
	for (size_t i = 0; i < size; i++)
	{
		cout << *ptr << "\t";
		ptr++;
	}
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		ptr--;
		cout << *ptr << "\t";
	}*/
	
	//3
	cout << "Copy: ";
	for (int i = size - 1; i >= 0; i--) {
		cout << arr2[i] << " ";
	}
}