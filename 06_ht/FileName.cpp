#include <iostream>

using namespace std;

int main() {
	//3
	/*const int N = 10;
	int marks[N];
	int index, newMark;
	double sum = 0;
	int choice = 0;

	cout << "Enter marks: " << endl;
	for (int i = 0; i < N; i++)
	{
		do
		{
			cout << "Mark " << i + 1 << ": ";
			cin >> marks[i];
		} while (marks[i] < 1 || marks[i] > 12);
	}

	do
	{
		cout << "\nMenu:\n";
		cout << "1. Marks\n";
		cout << "2. Retake the exam\n";
		cout << "3. Scholarship\n";
		cout << "4. Exit\n";
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Marks: ";
			for (int i = 0; i < N; i++)
			{
				cout << marks[i] << " ";
			}
			cout << endl;
		}

		else if (choice == 2)
		{
			do
			{
				cout << "Enter mark you want to change: ";
				cin >> index;
			} while (index < 1 || index > 10);

			do
			{
				cout << "Enter new mark: ";
				cin >> newMark;
			} while (newMark < 1 || newMark > 12);

			marks[index - 1] = newMark;
			cout << "Mark changed" << endl;

		}
		else if (choice == 3)
		{
			sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += marks[i];
			}

			double average = sum / N;
			cout << "Average: " << average << endl;

			if (average >= 10.7) {
				cout << "You get a scholarship" << endl;
			}
			else {
				cout << "You don't get a scholarship" << endl;
			}

		}
	} while (choice != 4);*/


	//2
	/*cout << "\n\n\n";
	const int size = 5, size2 = 10;
	int one[size]{}, two[size]{}, res[size2]{};

	int min = -10, max = 10;
	for (size_t i = 0; i < size; i++)
	{
		one[i] = rand() % (max - min + 1) + min;
		two[i] = rand() % (max - min + 1) + min;
	}
	cout << "First array  :: ";
	for (size_t i = 0; i < size; i++)
	{
		cout << one[i] << "\t";
	}cout << endl;

	cout << "Second array :: ";
	for (size_t i = 0; i < size; i++)
	{
		cout << two[i] << "\t";
	}cout << endl;

	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (one[i] > 0)
			res[j++] = one[i];

		if (two[i] > 0)
			res[j++] = two[i];
	}

	for (size_t i = 0; i < size; i++)
	{
		if (one[i] == 0)
			res[j++] = one[i];
		if (two[i] == 0)
			res[j++] = two[i];
	}

	for (size_t i = 0; i < size; i++)
	{
		if (one[i] < 0)
			res[j++] = one[i];
		if (two[i] < 0)
			res[j++] = two[i];
	}
	cout << "Result array :: ";
	for (size_t i = 0; i < j; i++)
	{
		cout << res[i] << "\t";
	}cout << endl;*/

	/*const int N = 10; 
	int arr[N] = { 1, 0, 3, 0, 5, 0, 0, 7, 9, 0 };
	int index = 0; 

	for (int i = 0; i < N; i++) {
		if (arr[i] != 0) {
			arr[index++] = arr[i];
		}
	}

	while (index < N) {
		arr[index++] = -1;
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}*/
}