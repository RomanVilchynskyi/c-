#include <iostream>
#include<Windows.h>

using namespace std;

//1
//int power(int d, int v) {
//	int res = 1;
//	for (size_t i = 0; i < v; i++)
//	{
//		res *= d;
//	}
//	return res;
//}

//2
//int range(int a, int b) {
//    int sum = 0;
//
//    if (a > b) {
//        for (int i = b; i <= a; i++) {
//            sum += i;
//        }
//    }
//    else {
//        for (int i = a; i <= b; i++) {
//            sum += i;
//        }
//    }
//
//    return sum;
//}

//3
//bool isperfect(int num) {
//    int sum = 0;
//
//    for (int i = 1; i < num; i++) {
//        if (num % i == 0) {
//            sum += i;
//        }
//    }
//    return sum == num;
//}
//
//void findnum(int start, int end) {
//    cout << "Досконалі числа у діапазоні від " << start << " до " << end << ": ";
//
//    bool found = false;
//    for (int i = start; i <= end; i++) {
//        if (isperfect(i)) {
//            cout << i << " ";
//            found = true;
//        }
//    }
//
//    if (!found) {
//        cout << "Немає досконалих чисел у цьому діапазоні.";
//    }
//
//    cout << endl;
//}

//5
int isperfect(int num) 
{
    int firstpart = num / 1000;
    int secondpart = num % 1000;

    int sum1 = 0;
    for (size_t i = 0; i < firstpart; i++)
    {
        sum1 += i;
    }
    int sum2 = 0;
    for (size_t j = 0; j < secondpart; j++)
    {
        sum2 += j;
    }

    if (sum1 == sum2) {
        cout << "Happy number";
        return 1;
    }
    else {
        cout << "not a happy number";
        return 0;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	//1
	/*int d, v;
	cout << "Enter base number and the power:: ";
	cin >> d>>v;

	cout << "Result: " << power(d, v) << endl;*/

    //2
    /*int a, b;
    cout << "Enter the numbers:: ";
    cin >> a >> b;

    cout << "Sum of range from: " << a << " to " << b <<" = " << range(a, b) << endl;*/

	//3
    /*int start, end;
    cout << "Введіь діапазон: ";
    cin >> start >> end;

    findnum(start, end);*/

    //5
    int num;
    cout << "Введіть шестизначне число: ";
    cin >> num;

    isperfect(num);

}