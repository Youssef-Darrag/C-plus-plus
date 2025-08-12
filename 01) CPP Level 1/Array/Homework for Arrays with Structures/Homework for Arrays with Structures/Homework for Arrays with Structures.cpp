#include <iostream>
using namespace std;

struct stInfo
{
    string FristName;
    string LastName;
    int Age;
    string Phone;
};

void ReadInfo(stInfo &Info)
{
    cout << "Please,enter FirstName?\n";
    cin >> Info.FristName;
    cout << "Please,enter LastName?\n";
    cin >> Info.LastName;
    cout << "Please,enter Age?\n";
    cin >> Info.Age;
    cout << "Please,enter Phone?\n";
    cin >> Info.Phone;
}

void PrintInfo(stInfo Info)
{
    cout << "\n********************************\n";
    cout << "FirstName : " << Info.FristName << endl;
    cout << "LastName  : " << Info.LastName << endl;
    cout << "Age   : " << Info.Age << endl;
    cout << "Phone : " << Info.Phone << endl;
    cout << "********************************\n";
}

void ReadPersonsInfo(stInfo Persons[2])
{
    ReadInfo(Persons[0]);
    ReadInfo(Persons[1]);
}

void PrintPersonsInfo(stInfo Persons[2])
{
    PrintInfo(Persons[0]);
    PrintInfo(Persons[1]);
}
int main()
{
    stInfo Persons[2];
    ReadPersonsInfo(Persons);
    PrintPersonsInfo(Persons);
}

