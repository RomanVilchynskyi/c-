#include <iostream>
using namespace std;



//int sum(int a, int b)
//{
//    return a + b;
//}
//
//double sum(double a, double b)
//{
//    return a + b;
//}
//string sum(string a, string b)
//{
//    return a + b;
//}
//double sum(int a, double b)
//{
//    return a + b;
//}
//int sum(int a, int b, int c)
//{
//    return a + b + c;
//}

template <typename T>
T sum(T a, T b)
{
	return a + b;
}

template <typename T, typename T2>
auto sum(T a, T2 b)
{
	return a + b;
}
template <typename T, typename T2, typename T3>
auto sum(T a, T2 b, T3 c)
{
	return a + b + c;
}


//void fillArray(int arr[], size_t length, int min = 1, int max = 10)
//{
//	for (size_t i = 0; i < length; i++)
//	{
//		arr[i] = min + rand() % (max - min + 1);
//	}
//}
//void fillArray(double arr[], size_t length, int min = 1, int max = 10)
//{
//	for (size_t i = 0; i < length; i++)
//	{
//		arr[i] = (min + rand() % (max - min + 1)) / 3.0;
//	}
//}
//void fillArray(char arr[], size_t length, int min = 1, int max = 10)
//{
//	for (size_t i = 0; i < length; i++)
//	{
//		arr[i] = (min + rand() % (max - min + 1));
//	}
//}
template <typename T>
void fillArray(T arr[], size_t length, int min = 1, int max = 10, bool div = false)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
		if (div)
		{
			arr[i] /= 3.0;
		}
	}
}
template <typename T, int COL = 5>
void fillArray(T arr[][COL], size_t row, size_t col, int min = 1, int max = 10, bool div = false)
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			arr[j][i] = min + rand() % (max - min + 1);
			if (div)
			{
				arr[j][i] /= 3.0;
			}
		}
	}
}
template <typename T, int COL = 5>
void printArray(T arr[][COL], size_t row, size_t col, string prompt = "")
{
	cout << prompt << endl;
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			cout << arr[j][i] << "\t";
		}cout << endl;
	}
}
template <typename T>
void printArray(T arr[], size_t length, string prompt = "")
{
	cout << prompt;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}cout << endl;
}
//void printArray(int arr[], size_t length, string prompt = "")
//{
//	cout << prompt;
//	for (size_t i = 0; i < length; i++)
//	{
//		cout << arr[i] << "\t";
//	}cout << endl;
//}
//void printArray(double arr[], size_t length, string prompt = "")
//{
//	cout << prompt;
//	for (size_t i = 0; i < length; i++)
//	{
//		cout << arr[i] << "\t";
//	}cout << endl;
//}
//void printArray(char arr[], size_t length, string prompt = "")
//{
//	cout << prompt;
//	for (size_t i = 0; i < length; i++)
//	{
//		cout << arr[i] << "\t";
//	}cout << endl;
//}
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


void min_max(int arr[], size_t length)
{
	int min = arr[0];
	int max = arr[0];
	int min_i = 0, max_i = 0;
	for (size_t i = 1; i < length; i++)
	{
		if (min > arr[i]) {
			min = arr[i];
			min_i = i;
		}
		if (max < arr[i])
		{
			max = arr[i];
			max_i = i;
		}
	}
	//cout << "Min" << min ...
}
int min_(int arr[], size_t length)
{
	int min = arr[0];

	int min_i = 0;
	for (size_t i = 1; i < length; i++)
	{
		if (min > arr[i]) {
			min = arr[i];
		}

	}
	return min;

}
void fin(int arr[], size_t length) {
	cout << min_(arr, length) << endl;
}
int main()
{
	cout << "Sum int    --> " << sum(5, 3) << endl;
	cout << "Sum double --> " << sum(5.5, 3.9) << endl;
	string first = "hello", second = "world";
	cout << "Sum string --> " << sum(first, second) << endl;
	cout << "Sum double --> " << sum(5, 3.9) << endl;
	cout << "Sum int --> " << sum(5, 2, 6.3) << endl;
	cout << "\n\n ============================ Array ===============================\n";
	const int size = 10;
	int arr[size]{};
	double arr_d[size]{};
	char arr_c[size]{};
	fillArray(arr, size);
	fillArray(arr_d, size, 20, 50, true);
	fillArray(arr_c, size, 'A', 'Z');
	printArray(arr, size, "Print array int    ::  ");
	printArray(arr_d, size, "Print array double ::  ");
	printArray(arr_c, size, "Print array char   ::  ");

	cout << "\n\n ============================ Find ===============================\n";
	cout << "find 22 --> position :: " << indexOf(arr, size, 22) << endl;
	int index = indexOf(arr, size, 5);
	while (index != -1)
	{
		cout << "find 5  --> position :: " << index << endl;
		index = indexOf(arr, size, 5, index + 1);
	}
	cout << "find X  --> position :: " << indexOf(arr_c, size, 'X') << endl;

	cout << "\n\n ============================ Multi Array ===============================\n";
	const int row = 4, col = 7;
	int mas[row][col]{};
	fillArray(mas, row, col, 1, 10, false);
	printArray(mas, row, col, "Print Multi Array :: ");
}