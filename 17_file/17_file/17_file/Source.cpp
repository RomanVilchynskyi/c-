#include <iostream>
#include <fstream> // read, write
#include <string>

// ofstream -->  write (cout)
// ifstream --> read (cin)
// fstream --> read, write;


using namespace std;

int main() {
	string line = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";
	string fname = "my.txt";

	ofstream file;

	//file.open(fname, ios_base::app);// mode --> write (w), write and append (wa)
	//if (!file.is_open())
	//	cout << "File not found" << endl;
	//else {
	//	getline(cin, line);
	//	file << line << endl;
	//}

	//file.close();

	/*string numbers = "numbers.txt";
	file.open(numbers, ios_base::app);
	if (!file.is_open())
		cout << "Error" << endl;
	else {
		int number;
		while (cin >> number) {
			file << number << endl;
		}
	}*/

	ifstream ifile(fname);
	//if (!ifile.is_open())
	//	cout << "Error" << endl;
	//else {
	//	cout << "\n\n Read words " << endl;
	//	/*while (!ifile.eof())
	//	{
	//		ifile >> line;
	//		cout << "Result read file --> " << line << endl;

	//	}*/
	//	cout << "Start read:: " << ifile.tellg() << endl;
	//	while (ifile >> line)
	//	{
	//	cout << "Result read file --> " << line << endl;
	//	//cout << "End read:: " << ifile.tellg() << endl;

	//	}
	//	cout << "End read:: " << ifile.tellg() << endl;

	//	ifile.clear();
	//	ifile.seekg(0);

	//	cout << "Start read:: " << ifile.tellg() << endl;
	//	cout << "\n\n Read lines " << endl;
	//	while (getline(ifile,line))
	//	{
	//		cout << "Result read file --> " << line << endl;
	//	}

	//	char str[100];
	//	char s;

	//	ifile.clear();
	//	ifile.seekg(0);
	//	cout << "\n\n Read words " << endl;
	//	while (ifile >> str)
	//	{
	//		cout << "Result read file --> " << str << endl;
	//	}

	//	ifile.clear();
	//	ifile.seekg(0);
	//	cout << "\n\n Read lines " << endl;
	//	while (ifile.getline(str,100))
	//	{
	//		cout << "Result read file --> " << str << endl;
	//	}

	//	ifile.clear();
	//	ifile.seekg(0);
	//	cout << "\n\n Read symbols " << endl;
	//	while (ifile.get(s))
	//	{
	//		if (s == ' ' or s == '\n')
	//			continue;
	//		cout << "Result read file --> " << s << endl;
	//	}
	//}
	//ifile.close();

	//1
	//ofstream outputFile("result.txt");
	//if (!outputFile.is_open()) {
	//	cout << "File is not found!" << endl;
	//}

	//string word;
	//while (ifile >> word)
	//{
	//	if (word.length() >= 7) {
	//		outputFile << word << " ";
	//	}

	//}

	//file.close();
	
	//2
	/*
	string o_name = "output.txt";

	ifstream inputFile(fname);
	if (!inputFile.is_open()) {
		cout << "Error!" << endl;
	}

	ofstream outputFile(o_name);
	if (!outputFile.is_open()) {
		cout << "Error!" << endl;
	}

	string line2;

	while (getline(inputFile, line2)) {
		outputFile << line2 << endl;
	}

	inputFile.close();
	outputFile.close();*/

	//3
	ofstream result;
	ifstream output("taskk.txt");
	const int size = 100;
	string f_name = "task3";

	file.open(fname, ios_base::app);
	if (!file.is_open())
		cout << "File not found" << endl;
	else {
		int counter = 0;
		string task[size];
		string line3;
		result.open(f_name);
		while (getline(output,task[counter]))
		{
			counter++;
		}
		for (int i = counter - 1; i >= 0; i--)
		{
			result << task[i] << endl;
		}
		cout << counter;
		output.close();
		result.close();
	}

}