#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	srand(time(0));
	//1
	/*const int SIZE = 5;
	int arr[SIZE];*/
	/*arr[0] = rand() % 10 + 1;
	arr[1] = rand() % 10 + 1;
	arr[2] = rand() % 10 + 1;
	arr[3] = rand() % 10 + 1;
	arr[4] = rand() % 10 + 1;

	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10 + 1;
	}
	cout << "Print array:: ";
	double min = arr[0];
	double max = arr[0];
	for (size_t i = 0; i < SIZE; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
		cout << arr[i] << "\t ";
	}
	cout << endl;
	cout << "Max number: " << max << endl;
	cout << "Min number: " << min << endl;*/

	//2
    /*const int MONTHS = 12;
    int profit[MONTHS];

    cout << "������ �������� �� ����� � 12 ������:\n";
    for (int i = 0; i < MONTHS; i++) {
        cout << "̳���� " << i + 1 << ": ";
        cin >> profit[i];
    }

    int start, end;
    cout << "������ �������: ";
    cin >> start >> end;

    if (start < 1 || end > 12 || start > end) {
        cout << "����������� �������." << endl;
    }

    int maxProfit = profit[start - 1];
    int minProfit = profit[start - 1];
    int maxMonth = start;
    int minMonth = start;

    for (int i = start - 1; i < end; i++) {
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonth = i + 1;
        }
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonth = i + 1;
        }
    }


    cout << "������������ �������� ��� � ����� " << maxMonth << " � �������� " << maxProfit << endl;
    cout << "̳�������� �������� ��� � ����� " << minMonth << " � �������� " << minProfit << endl;*/

    //3
    const int SIZE = 10;
    int arr[SIZE];

    srand(time(0));

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 21 - 10;
    }

    cout << "������������ �����:\n";
    for (size_t i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    double sumn = 0;
    for (size_t i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            sumn += arr[i];
        }
    }

    int minI = 0, maxI = 0;
    for (size_t i = 1; i < SIZE; i++) {
        if (arr[i] < arr[minI]) {
            minI = i;
        }
        if (arr[i] > arr[maxI]) {
            maxI = i;
        }
    }

    double bmm = 1;
    if (minI > maxI) {
        int temp = minI;
        minI = maxI;
        maxI = temp;
    }
    for (size_t i = minI + 1; i < maxI; i++) {
        bmm *= arr[i];
    }

    double product = 1;
    for (size_t i = 0; i < SIZE; i += 2) {
        product *= arr[i];
    }

   
    cout << "���� ��'����� ��������: " << sumn << endl;
    cout << "������� �������� �� ��������� � ������������: " << bmm << endl;
    cout << "������� �������� � ������� ��������: " << product << endl;


}