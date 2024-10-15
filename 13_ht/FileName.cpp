#include <iostream>
#include <Windows.h>

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
void insertCol(t** arr, const size_t& row, int& col, const size_t& index, t value = t()) {
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

	for (size_t i = 0; i < row - 1; i++)
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
	delete[] arr[row - 1];
	row--;
}

template <typename t>
void insertColatbeg(t**& arr, const size_t& row, int& col) {
	for (size_t i = 0; i < row; i++) {
		t* newRow = new t[col + 1]{};

		for (int j = 0; j < col; j++) {
			newRow[j + 1] = arr[i][j];
		}
		delete[] arr[i];

		arr[i] = newRow;
	}

	col++;
}

template <typename t>
void insertColatend(t**& arr, const size_t& row, int& col) {
	for (size_t i = 0; i < row; i++) {
		t* newRow = new t[col + 1]{};

		for (int j = 0; j < col; j++) {
			newRow[j] = arr[i][j];
		}
		delete[] arr[i];

		arr[i] = newRow;
	}

	col++;
}

template <typename t>
void delColatbeg(t**& arr, const size_t& row, int& col) {
	for (size_t i = 0; i < row; i++) {
		t* newRow = new t[col - 1]{};

		for (int j = 0; j < col; j++) {
			newRow[j-1] = arr[i][j];
		}
		delete[] arr[i];

		arr[i] = newRow;
	}

	col--;
}

template <typename t>
void delColatend(t**& arr, const size_t& row, int& col) {
	for (size_t i = 0; i < row; i++) {
		t* newRow = new t[col - 1]{};

		for (int j = 0; j < col-1; j++) {
			newRow[j] = arr[i][j];
		}
		delete[] arr[i];
			
		arr[i] = newRow;
	}

	col--;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int row = 4, col = 5;
	int** arr = new int* [row];

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

	insertColatbeg(arr, row, col);
	print(arr, row, col, "Print array after insert Col at the begining ");

	insertColatend(arr, row, col);
	print(arr, row, col, "Print array after insert Col at the end ");

	/*delColatbeg(arr, row, col);
	print(arr, row, col, "Print array after delete Col at the begining ");*/

	delColatend(arr, row, col);
	print(arr, row, col, "Print array after delete Col at the end ");


	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;

// 1. �������� ������� ��� ���� �������� �� ������� ����������� ������
// 2. �������� ������� ��� ���� �������� � ����� ����������� ������
// 5. �������� ������� ��� ������� �������� �� ������� ����������� ������
// 6. �������� ������� ��� ������� �������� � ����� ����������� ������

}