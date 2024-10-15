#include <iostream>

using namespace std;

int main() {
	//1
	/*int a, sum = 0;
	cout << "Enter the number:: ";
	cin >> a;

	if (a >= 500) {
		cout << "Number must be under 500"<<endl;
	}
	else {
		for (int i = a; i <= 500; i++)
		{
			sum += i;
		}
		cout << sum << endl;
	}*/
	
	//2
	/*int x, y;
	cout << "Enter x y:: ";
	cin >> x >> y;

	int result = 1;

	for (int i = 0; i < y; i++) {
		result *= x;
	}

	cout << x << " in degree " << y << " = " << result << endl;*/

	//3
	/*int sum = 0;
	int count = 1000;  

	for (int i = 1; i <= count; i++) {
		sum += i;
	}

	int average = sum / count;

	cout << "Average: " << average<<endl;*/

	//4
	int num;
	long long j = 1;
	cout << "Enter the number:: ";
	cin >> num;

	if (num < 1 || num > 20) {
		cout << "Number must be in the range of 1 to 20!" << endl;
	}
	else {
		for (int i = num; i <= 20; i++)
		{
			j *= i;
		}
		cout << "From: " << num << " to 20: " << j << endl;
	}

	

	//5
	/*int k;
	cout << "Enter the nmuber:: ";
	cin >> k;

	for (size_t i = 1; i <= 10; i++)
	{
		int db = k * i;
		cout << k <<"*"<<i <<"="<<db << endl;
	}*/
}