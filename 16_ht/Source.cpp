#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Car {
    string color; 
    string model; 
    string number; 

    bool isNumber(const string& str) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] < '0' || str[i] > '9') {
                return false; 
            }
        }
        return true;
    }

    int getLength(const string& str) {
        int length = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            length++;
        }
        return length;
    }

    void fillCar(string carColor, string carModel, string carNumber) {
        color = carColor;
        model = carModel;

        int numberLength = getLength(carNumber); 
        if (numberLength <= 8 && ((numberLength == 5 && isNumber(carNumber)) || numberLength != 5)) {
            number = carNumber;
        }
    }

    /*void printCar() const {
        cout << "������: ����: " << color << ", ������: " << model << ", �����: " << number << endl;
    }*/
};
void printCarInfo(const Car& car)
{
    cout << "������: ����: " << car.color << ", ������: " << car.model << ", �����: " << car.number << endl;
}

void editCar(Car& car)
{
    cout << "\t\t ������ ����     :: ";
    getline(cin, car.color);  

    cout << "\t\t ������ ������    :: ";
    getline(cin, car.model);

    cout << "\t\t ������ �����     :: ";
    getline(cin, car.number);
};

void printAllCars(const Car* library, int size)
{
    cout << "\n������ ��� �����:\n";
    for (int i = 0; i < size; i++) {
        printCarInfo(library[i]); 
    }
}

void searchCarByNumber(const Car* library, int size, const string& number)
{
    bool found = false;  
    for (int i = 0; i < size; i++) {
        if (library[i].number == number) {  
            printCarInfo(library[i]);  
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "\n������ � ������� " << number << " �� ��������.\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Car car;

    /*car.fillCar("��������", "Toyota", "12345");

    car.printCar();

    car.fillCar("����", "Honda", "MtSAVA1");

    car.printCar();*/

    int size = 10;
    Car* library = new Car[size]{
        {"Red", "Ferrari", "wsAc12"},
        {"Blue", "Ford", "KBacc1"},
        {"Green", "Tesla", "BCaauc5"},
        {"Yellow", "Lamborghini", "adbB84"},
        {"Black", "Chevrolet", "avNVS3"},
        {"Silver", "Nissan", "avNVS3"},
        {"White", "Porsche", "asv225"},
        {"Orange", "McLaren", "LLNI29"},
        {"Purple", "Aston Martin", "BNIBsv2"},
        {"Brown", "Bugatti", "191AV"}
    };

    for (int i = 0; i < size; i++) {
        printCarInfo(library[i]);
    }

    int carIndex;
    cout << "\n������ ����� ������ ��� ����������� (1-" << size << "): ";
    cin >> carIndex;
    cin.ignore();  

    if (carIndex >= 1 && carIndex <= size) {
        editCar(library[carIndex - 1]);
        cout << "\n�������� ���������� ��� ������:\n";
        printCarInfo(library[carIndex - 1]);
    }

    printAllCars(library, size);

    string searchNumber;
    cout << "\n������ ����� ������ ��� ������: ";
    getline(cin, searchNumber);
    searchCarByNumber(library, size, searchNumber);

    delete[] library;
}