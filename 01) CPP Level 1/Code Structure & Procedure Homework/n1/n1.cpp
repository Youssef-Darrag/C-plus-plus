#include <iostream>
#include <string>
using namespace std;

struct stinfo
{
	string Name;
	int Age;
	string City;
	string Country;
	int MonthlySalary;
	char Gender;
	bool Married;
};

void readinfo(stinfo &info)
{
	cout << "please,enter your Name?\n";
	cin.ignore(1, '\n');
	getline(cin, info.Name);
	cout << "please,enter your Age?\n";
	cin >> info.Age;
	cout << "please,enter your City?\n";
	cin >> info.City;
	cout << "please,enter your Country?\n";
	cin >> info.Country;
	cout << "please,enter your MonthlySalary?\n";
	cin >> info.MonthlySalary;
	cout << "please,enter your Gender?\n";
	cin >> info.Gender;
	cout << "Please,enter your Married?\n";
	cin >> info.Married;
}

void printinfo(stinfo info)
{
	cout << "\n******************************************\n";
	cout << "Name : " << info.Name << endl;
	cout << "Age  : " << info.Age << endl;
	cout << "City : " << info.City << endl;
	cout << "Country : " << info.Country << endl;
	cout << "MonthlySalary : " << info.MonthlySalary << endl;
	cout << "YearlySalary  : " << info.MonthlySalary * 12 << endl;
	cout << "Gender  : " << info.Gender << endl;
	cout << "Married : " << info.Married << endl;
	cout << "\n******************************************\n";
}

int main()
{
	stinfo person1info;
	readinfo(person1info);
	printinfo(person1info);

	stinfo person2info;
	readinfo(person2info);
	printinfo(person2info);
}

