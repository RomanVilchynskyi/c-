#include <iostream>

using namespace std;

//1
int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

//2
void printAscending(int start, int end) {
    if (start > end) return;
    cout << start << " ";    
    printAscending(start + 1, end); 
}

void printdecscending(int start, int end) {
    if (start > end) return; 
    printdecscending(start + 1, end); 
    cout << start << " ";   
}

//3
void printnum(int n) {
    if (n == 0)return;
    cout << n % 10;
    printnum(n / 10);
}

//4
int sumnum(int n) {
    if (n == 0)return 0;
    return(n%10)+ sumnum(n / 10);
}

//5
void printbrackets(int n) {
    if (n == 0) return;
    cout << "(";         
    printbrackets(n - 1); 
    cout << ")";
}

int main() {
	/*cout << factorial(5)<<endl;

    int start, end;
    cout << "Enter the range: ";
    cin >> start >> end;
    printAscending(start, end);
    cout << endl;
    printdecscending(start, end);
    cout << endl;

    int n;
    cout << "Enter num: ";
    cin >> n;
    printnum(n);*/


    //cout<<sumnum(1234);

    printbrackets(4);
}