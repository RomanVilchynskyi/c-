#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
	string getdate() {
		return (day < 10 ? "0" : "") + to_string(day) + "." + to_string(month) + "." + to_string(year);
	}
};
//string getdate(Date dt);

struct Student {
	string name;
	string lastname;
	double average;
	Date birthday;
};

void printStudent(Student stud) {
	cout << "First name :: " << stud.name << endl;
	cout << "Last name :: " << stud.lastname << endl;
	cout << "Average :: " << stud.average << endl;
	cout << "Birthdate :: " << stud.birthday.getdate() << endl;
}

void editstudent(Student &stud) {
	cout << "Enter name :: "; cin >> stud.name;
	cout << "Enter lastname :: "; cin >> stud.lastname;
	cout << "Enter average :: "; cin >> stud.average;
	cout << "Enter name :: "; cin >> stud.birthday.day>> stud.birthday.month>> stud.birthday.year;
}

struct Washingmachine {
	string firm;
	string color;
	double width;
	double length;
	double height;
	double power;
	double spinspeed;
	double temperature;
};

void printwashmach(Washingmachine mach) {
	cout << "Firm :: " << mach.firm << endl;
	cout << "Color :: " << mach.color << endl;
	cout << "Width sm:: " << mach.width << endl;
	cout << "Length sm :: " << mach.length << endl;
	cout << "height sm:: " << mach.height << endl; 
	cout << "power rv/h :: " << mach.power << endl;
	cout << "Spin speed r/m :: " << mach.spinspeed << endl;
	cout << "Temperature c:: " << mach.temperature << endl;
}
//string getdate(Date dt) {
//	return (dt.day < 10 ? "0" : "") + to_string(dt.day) + "." + to_string(dt.month) + "." + to_string(dt.year);
//}

struct Iron {
	string firm;
	string model;
	string color;
	double mintemperature;
	double maxtemperature;
	bool steam;
};

void printiron(Iron i) {
	cout << "Firm :: " << i.firm << endl;
	cout << "Model :: " << i.model << endl;
	cout << "Color :: " << i.color << endl;
	cout << "Mintemperature c:: " << i.mintemperature << endl;
	cout << "Mintemperature c:: " << i.mintemperature << endl;
	cout << "Steam yes/no:: " << boolalpha <<i.steam << endl;
}

struct Boiler {
	string firm;
	string color;
	double power;
	double volume;
	double temperature;
};

void printboiler(Boiler b) {
	cout << "Firm :: " << b.firm << endl;
	cout << "Color :: " << b.color << endl;
	cout << "Power kv/h:: " << b.power << endl;
	cout << "Volume l:: " << b.volume << endl;
	cout << "Temperature c:: " << b.temperature << endl;

}

struct Animal {
	string name;         
	string species_class;  
	string nickname;       

	// Функція для заповнення об'єкта
	void fillAnimal(const string& animal_name, const string& animal_class, const string& animal_nickname) {
		name = animal_name;
		species_class = animal_class;
		nickname = animal_nickname;
	}

	void outputAnimal() {
		cout << "Назва тварини: " << name << endl;
		cout << "Клас тварини: " << species_class << endl;
		cout << "Кличка тварини: " << nickname << endl;
	}

	void makeSound() {
		if (species_class == "Ссавець") {
			cout << nickname << " каже: Гав-гав" << endl;
		}
		else if (species_class == "Птах") {
			cout << nickname << " каже: Чірік-чірік" << endl;
		}
		else {
			cout << nickname << " видає звук" << endl;
		}
	}
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Washingmachine d;
	cout << "Washing machine: " << endl;
	d.firm = "bosch";
	d.color = "white";
	d.width = 59.5;
	d.length = 37.7;
	d.height = 85;
	d.power = 4;
	d.spinspeed = 1200;
	d.temperature = 90;

	printwashmach(d);
	cout << endl;

	Iron i;
	cout << "Iron: " << endl;
	i.firm = "Philips";
	i.model = "5000 Series DST5030/20";
	i.color = "blue";
	i.mintemperature = 110;
	i.maxtemperature = 205;
	i.steam = true;

	printiron(i);
	cout << endl; 

	cout << "Boiler: " << endl;
	Boiler b = { "Antlantic", "white", 1500, 80, 80 };
	printboiler(b);
	cout << endl;

	Animal animal;
	animal.fillAnimal("Собака", "Птах", "Барсик");
	animal.outputAnimal();
	animal.makeSound();
	cout << endl;

	Student ivan;
	ivan.name = "Ivan";
	ivan.lastname = "Demchuk";
	ivan.average = 11.5;
	ivan.birthday.day = 2;
	ivan.birthday.month = 12;
	ivan.birthday.year = 2009;

	Student olia = { "Olia","Bondar",10.3,{24,5,2005} };

	printStudent(ivan);
	cout << endl;
	printStudent(olia);

	cout << "Edit student:: " << endl;
	editstudent(ivan);
	cout << "Result :: " << endl;
	printStudent(ivan);

	int size = 3;
	Student* group = new Student[size]{
	ivan,
	olia,
		{"Pavlo","Petrushun",5,{1,1,2001}}
	};

	for (size_t i = 0; i < size; i++)
	{
		cout << "\n==========================================\n";
		printStudent(group[i]);
	}
		/*string firstname = "Ivan";
		string lastname = "Potapchuk";

		double average = 10.2;
		int day = 1;
		int month = 10;
		int year = 2009;*/
}

//Завдання для самостійної роботи
//
//	Завдання 4. Розробити структуру, яка описує тварину
//	(назва, клас, кличка).Створити функції для роботи з
//	цією структурою :
//■ Заповнення об'єкта;
//■ Вивід на екран даних про об'єкт;
//■ Функція «Подати голос».