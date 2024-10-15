#include <iostream>
#include <windows.h>

using namespace std;

template <typename T>
void fill(T** arr, const size_t& row, const size_t& col, int min = 0, int max = 10)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = min + rand() % (max - min + 1);
		}
	}
}
template <typename T>
void print(T** arr, const size_t& row, const size_t& col, string prompt = "")
{
	if (!prompt.empty())
		cout << prompt << " :: " << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}cout << endl;
	}
}

template <typename T>
void insertRow(T**& arr, int& row, const size_t& col, const size_t& index)
{
	if (index > row) {
		cout << "Error! The index is out of range" << endl;
		return;
	}
	T** tmp = new T * [row + 1];
	for (size_t i = 0; i < row; i++)
	{
		if (i < index)
			tmp[i] = arr[i];
		else
			tmp[i + 1] = arr[i];
	}
	tmp[index] = new T[col]{};
	row++;
	delete[] arr;
	arr = tmp;
}

template <typename T>
void removeRow(T**& arr, int& row, const size_t& index)
{
	if (index >= row) {
		cout << "Error! The index is out of range" << endl;
		return;
	}
	T** tmp = new T * [--row];
	for (size_t i = 0; i < row; i++)
	{
		if (i < index)
			tmp[i] = arr[i];
		else
			tmp[i] = arr[i + 1];
	}
	delete[] arr[index];
	delete[] arr;
	arr = tmp;
}

template <typename t>
void insertCol(t** arr, const size_t& row, int& col, const size_t &index, t value = t()) {
	if (index > col) {
		cout << "Error! The index is out of range" << endl;
		return;
	}
	for (size_t i = 0; i < row; i++)
	{
		t* tmp = new t[col + 1];
		for (size_t j = 0; j < col; j++)
		{
			if (j < index)
				tmp[j] = arr[i][j];
			else
				tmp[j + 1] = arr[i][j];
		}
		tmp[index] = value;
		delete[]arr[i];
		arr[i] = tmp;
	}
	col++;
}

template <typename t>
void removeCol(t** arr, const size_t& row, int& col, const size_t& index) {
	if (index >= col) {
		cout << "Error! The index is out of range" << endl;
		return;
	}
	col--;
	for (size_t i = 0; i < row; i++)
	{
		t* tmp = new t[col];
		for (size_t j = 0; j < col; j++)
		{
			if (j < index)
				tmp[j] = arr[i][j];
			else
				tmp[j] = arr[i][j + 1];
		}
		delete[]arr[i];
		arr[i] = tmp;
	}
}

template <typename T>
void insertRowAtBeginning(T**& arr, int& row, const size_t& col) {
	T** tmp = new T * [row + 1];

	tmp[0] = new T[col]{};

	for (size_t i = 0; i < row; i++) {
		tmp[i + 1] = arr[i];
	}

	row++;
	delete[] arr;
	arr = tmp;
}

//template <typename T>
//void insertRowAtBeginning(T**& arr, int& row, const size_t& col) {
//	T** tmp = new T * [row + 1];
//
//	tmp[0] = new T[col]{};
//
//	for (size_t i = 0; i < row; i++) {
//		tmp[i + 1] = arr[i];
//	}
//
//	row++;
//	delete[] arr;
//	arr = tmp;
//}

template <typename T>
void insertRowAtEnd(T**& arr, int& row, const size_t& col)
{
	T** tmp = new T * [row + 1];

	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[row] = new T[col]{};
	row++;
	delete[] arr;
	arr = tmp;
}

template <typename t>
void delRowatbeg(t**& arr, t& row, const t& col) {
	t** tmp = new t * [row - 1];

	for (size_t i = 0; i < row-1; i++)
	{
		tmp[i] = arr[i + 1];
	}
	row--;
	delete[] arr[0];
	delete[] arr;
	arr = tmp;
}

template <typename t>
void delRowatend(t**& arr, t& row, const t& col) {
	delete[] arr[row-1];
	row--;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// create array
	int row = 4, col = 5;
	int** arr = new int* [row];

	/*arr[0] = new int[col];
	arr[1] = new int[col];
	arr[2] = new int[col];
	arr[3] = new int[col];*/
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	fill(arr, row, col, 1);
	print(arr, row, col, "Print array ");

	insertRow(arr, row, col, 2);
	print(arr, row, col, "Print array after insert ROW ");

	removeRow(arr, row, 1);
	print(arr, row, col, "Print array after remove ROW ");

	insertCol(arr, row, col, 2, -1);
	print(arr, row, col, "Print array after insert Col ");

	removeCol(arr, row, col, 3);
	print(arr, row, col, "Print array after insert Col ");

	//insertRowAtBeginning(arr, row, col);
	//print(arr, row, col, "Print array after insert Row at the begining ");

	insertRowAtEnd(arr, row, col);
	print(arr, row, col, "Print array after insert Row at the end ");

	delRowatbeg(arr, row, col);
	print(arr, row, col, "Print array after del Row at the begining ");

	delRowatend(arr, row, col);
	print(arr, row, col, "Print array after del Row at the end ");


	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
	/*int z = 2, y = 4, x = 5;
	int*** mas = new int** [z];
	for (size_t i = 0; i < z; i++)
	{
		cout << endl << endl;
		mas[i] = new int* [y];
		for (size_t j = 0; j < y; j++)
		{
			mas[i][j] = new int[x];
			for (size_t q = 0; q < x; q++)
			{
				mas[i][j][q] = rand() % 10;
				cout << mas[i][j][q] << "\t";
			}cout << endl;
		}
	}*/
}

// 1. Написати функцію яка додає рядок на початок двовимірного масиву
// 2. Написати функцію яка додає рядок в кінець двовимірного масиву
// 3. Написати функцію яка додає рядок за вказаною позицією двовимірного масиву+
// 4. Написати функцію яка видаляє рядок за вказаною позицією двовимірного масиву+
// 5. Написати функцію яка видаляє рядок на початку двовимірного масиву
// 6. Написати функцію яка видаляє рядок в кінеці двовимірного масиву

// 1. Написати функцію яка додає стовпець на початок двовимірного масиву
// 2. Написати функцію яка додає стовпець в кінець двовимірного масиву
// 3. Написати функцію яка додає стовпець за вказаною позицією двовимірного масиву+
// 4. Написати функцію яка видаляє стовпець за вказаною позицією двовимірного масиву+
// 5. Написати функцію яка видаляє стовпець на початку двовимірного масиву
// 6. Написати функцію яка видаляє стовпець в кінеці двовимірного масиву