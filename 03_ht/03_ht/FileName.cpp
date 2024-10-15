#include <iostream>

using namespace std;

int main() {
    //1
    /*int num;
    cout << "Enter number:: ";
    cin >> num;

    if (num < 100000 or num > 999999) {
        cout << "Error" << endl;
    }
    else {
        int a1 = num / 100000;
        int a2 = (num / 10000) % 10;
        int a3 = (num / 1000) % 10;
        int a4 = (num / 100) % 10;
        int a5 = (num / 10) % 10;
        int a6 = num % 10;

        if ((a1 + a2 + a3) == (a4 + a5 + a6)) {
            cout << "Happy number" << endl;
        }
        else {
            cout << "Number is not happy" << endl;
        }
    }*/

    //2
    /*int num;
    cout << "Enter number:: ";
    cin >> num;

    if (num < 1000 or num >9999) {
        cout << "Error" << endl;
    }
    else {
        int a1 = num / 1000;          
        int a2 = (num / 100) % 10;    
        int a3 = (num / 10) % 10;     
        int a4 = num % 10;            

        int new_num = a2 * 1000 + a1 * 100 + a4 * 10 + a3;

        cout << "Changed number: " << new_num << endl;
    }*/

    //3
    /*int a, b, c, d, e, f, g;
    cout << "Enter numbers: ";
    cin >> a >> b >> c >> d >> e >> f >> g;

    int max_number = a;

    if (b > max_number) {
        max_number = b;
    }
    if (c > max_number) {
        max_number = c;
    }
    if (d > max_number) {
        max_number = d;
    }
    if (e > max_number) {
        max_number = e;
    }
    if (f > max_number) {
        max_number = f;
    }
    if (g > max_number) {
        max_number = g;
    }

    cout << "Biggest number: " << max_number << endl;*/

    //4
    int dAB, dBC, weight;
    cout << "Enter distance À ³ Â: ";
    cin >> dAB;
    cout << "Enter distance Â ³ Ñ: ";
    cin >> dBC;
    cout << "Enter the weight (in kg): ";
    cin >> weight;

    if (weight > 2000) {
        cout << "Error" << endl;
    }

    int fuelc;
    if (weight <= 500) {
        fuelc = 1;
    }
    else if (weight <= 1000) {
        fuelc = 4;
    }
    else if (weight <= 1500) {
        fuelc = 7;
    }
    else {
        fuelc = 9;
    }

    int fuelAB = dAB * fuelc;
    int fuelBC = dBC * fuelc;

    if (fuelAB > 300) {
        cout << "Error" << endl;
        return 0;
    }

    if (fuelBC > 300) {
        cout << "Error" << endl;
        return 0;
    }

    int fuelRAB = 300 - fuelAB;
    int fuelN = fuelBC - fuelRAB;

    if (fuelN <= 0) {
        cout << "Fligth cannot continue" << endl;
    }
    else {
        cout << "Minimum fuel needed for Â: " << fuelN << " l" << endl;
    }
}