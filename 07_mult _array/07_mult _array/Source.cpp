#include <iostream>

using namespace std;

int  main() {
	/*srand(time(0));
	const int length = 15;
	int arr[length]{};

	int min = -20, max = 20;
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = min + rand() % (max - min + 1);

	}

	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	double sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		sum += arr[i];
	}

	double average = sum / length;

	cout << average << endl;

	int middle = length / 3;
	if (average > 0) {
		middle *= 2;
	}
	for (size_t i = 0; i < length; i++)
	{
		if (0 == middle)
			cout << "| \t";
		cout << arr[i] << "\t";
	}

	for (size_t i = 0; i < length; i++)
	{
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 and key < arr[i]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	for (size_t i = middle, j = 0;j < (length - middle)/ 2; i++,j++)
	{
		int temp = arr[i];
		arr[i] = arr[length - 1 - j];
		arr[length - 1 - j] = temp;

	}

	for (size_t i = 0; i < length; i++)
	{
		if (i == middle)
			cout << "| \t";
		cout << arr[i] <<"\t";
	}
	cout << endl;*/

	//srand(time(0));
	//const int row = 4, col = 5;
	//int arr[row][col]{};

	///*arr[0][0] = rand() % 10 + 1;
	//arr[0][1] = rand() % 10 + 1;
	//arr[0][2] = rand() % 10 + 1;*/

	//for (size_t i = 0; i < row; i++)
	//{
	//	for(size_t j = 0;j < col;j++)
	//	{
	//		arr[i][j] = rand() % 10 + 1;
	//	}
	//}

	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}
	//	cout << endl;
	//}

	//cout << "\n\n ================================\n\n";
	//const int  block = 4, row_ = 4, col_ = 5;
	//int mas[block][row_][col_]{};

	//for (size_t i = 0; i < block; i++)
	//{
	//	for (size_t j = 0; j < row_; j++)
	//	{
	//		for (size_t q = 0; q < col_; q++)
	//		{
	//			mas[i][j][q] = rand() % 10 + 1;
	//			cout << mas[i][j][q]<<"\t";
	//		}
	//		cout << endl;
	//	}
	//	cout << "\n\n";
	//}

	//3
	/*const int row = 5, col = 10;
	int arr[row][col]{};
	int res[row][row]{};

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++) 
		{
			arr[i][j] = rand() % 10 + 1;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			res[i][j] = arr[i][j * 2] + arr[i][j * 2 + 1];
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}*/

	//1
	/*srand(time(0));
	const int row = 4, col = 5;
	int arr[row][col]{};
	double count = 0;
	int sum = 0;


	for (size_t i = 0; i < row; i++)
	{
		for(size_t j = 0;j < col;j++)
		{
			arr[i][j] = rand() % 10 + 1;
		}
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			sum += arr[i][j];
			count++;
		}
		cout << endl;
	}
	cout << "Sum: " << sum << "\t";

	double average = sum / count;
	cout << "Average: " << average << "\t";
	
	int max = arr[0][0];
	int min = arr[0][0];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
	}

	cout << "Max: " << max << "\t";
	cout << "Min: " << min << "\t";*/
	
	//2
	srand(time(0));
	const int row = 3; 
	const int col = 4;  
	int arr[row][col]{};

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 10 + 1;
		}
	}

	int totalSum = 0;      
	int colSum[col] = { 0 }; 

	for (int i = 0; i < row; i++) {
		int rowSum = 0; 
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << "\t";  
			rowSum += arr[i][j];        
			colSum[j] += arr[i][j];     
		}
		totalSum += rowSum;  
		cout << "| " << rowSum << endl;  
	}

	
	for (int j = 0; j < col; j++) {
		cout << "----";
	}
	cout << "-------------------" << endl;

	
	for (int j = 0; j < col; j++) {
		cout << colSum[j] << "\t";
	}
	cout << "| " << totalSum << endl;
}