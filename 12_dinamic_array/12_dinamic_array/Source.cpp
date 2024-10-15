#include <iostream>

using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void fill(int* arr, size_t length, int min = 1, int max = 10) {
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
	}
}

void print(int* arr, size_t length, string prompt = "") {
	if (!prompt.empty()) {
		cout << prompt << " :: ";
	}

	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}cout << endl;
}

//template <typename t>
//t* pushback(t* arr, size_t& length, t value) {
//	t* temp = new t[length + 1];
//	for (size_t i = 0; i < length; i++)
//	{
//		temp[i] = arr[i];
//	}
//	temp[length] = value;
//	length++;
//	delete[] arr;
//	return temp;
//}

template <typename t>
void pushback(t* &arr, size_t& length, t value) {
	t* temp = new t[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		temp[i] = arr[i];
	}
	temp[length] = value;
	length++;
	delete[] arr;
	arr = temp;
}

template <typename t>
void insert(t*& arr, size_t& length, t value, const size_t& index) {
	if (index > length)
	{
		cout << "Error! out range";
		return;
	}
	t* tmp = new t[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		if (i < index) {
			tmp[i] = arr[i];
		}
		else {
			tmp[i + 1] = arr[i];
		}
	}
	tmp[index] = value;
	length++;
	delete[] arr;
	arr = tmp;

}

template <typename t>
void remove(t*& arr, size_t& length, const size_t& index) {
	if (index >= length) {
		cout << "error! out of range";
		return;
	}
	t* tmp = new t[--length];
	for (size_t i = 0; i < length; i++)
	{
		if (i < index)
			tmp[i] = arr[i];
		else
			tmp[i] = arr[i + 1];
	}
	delete[] arr;
	arr = tmp;
}

template <typename t>
void pushforward(t*& arr, size_t& length, t value) {
	t* temp = new t[length + 1];
	temp[0] = value;
	for (size_t i = 0; i < length; i++)
	{
		temp[i + 1] = arr[i];
	}
	length++;
	delete[] arr;
	arr = temp;
}


template <typename t>
void removeb(t*& arr, size_t& length) {
	t* temp = new t[length - 1];
	for (size_t i = 0; i < length - 1; i++)
	{
		temp[i] = arr[i];
	}
	length--;
	delete[] arr;
	arr = temp;
}

template <typename t>
void removef(t*& arr, size_t& length) {
	t* temp = new t[length - 1];
	for (size_t i = 1; i < length; i++)
	{
		temp[i - 1] = arr[i];
	}
	length--;
	delete[] arr;
	arr = temp;
}

int main() {
	int a = 5, b = 10;
	cout << "a :: " << a << "\t b :: " << b << endl;
	Swap(a, b);
	cout << "a :: " << a << "\t b :: " << b << endl;

	int* ptr = new int;
	cout << "address :: " << ptr << "\t value :: " << *ptr << endl;

	size_t size = 10;
	cout << "Enter size:: ";
	cin >> size;

	int* arr = new int[size];
	fill(arr, size);
	print(arr, size, "Print array:: ");

	//arr = pushback(arr, size, 22);	
	/*pushback(arr, size, 22);
	print(arr, size, "Print push back:: ");*/

	insert(arr, size, 33, 3);
	print(arr, size, "Print insert:: ");

	remove(arr, size, 5);
	print(arr, size, "Print remove:: ");

	pushforward(arr, size, 12);
	print(arr, size, "Print push forward:: ");

	removeb(arr, size);
	print(arr, size, "Print remove back:: ");

	removef(arr, size);
	print(arr, size, "Print remove forward:: ");
	delete [] arr;
	/*size = 20;
	arr = new int[size];
	print(arr, size, "Print array:: ");
	delete [] arr;*/


}