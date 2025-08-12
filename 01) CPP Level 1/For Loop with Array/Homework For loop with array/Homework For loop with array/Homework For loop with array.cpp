#include <iostream>
using namespace std;

struct strInfo
{
    string FristName;
    string LastName;
    int Age;
    string Phone;
};

void ReadInfo(strInfo& Info)
{
    cout << "Please,enter the FirstName?\n";
    cin >> Info.FristName;
    cout << "Please,enter the LastName?\n";
    cin >> Info.LastName;
    cout << "Please,enter the Age?\n";
    cin >> Info.Age;
    cout << "Please,enter the Phone?\n";
    cin >> Info.Phone;
}

void PrintInfo(strInfo Info)
{
    cout << "**************************************\n";
    cout << "FristName = " << Info.FristName << endl;
    cout << "LastName = " << Info.LastName << endl;
    cout << "Age = " << Info.Age << endl;
    cout << "Phone = " << Info.Phone << endl;
    cout << "**************************************\n\n";
}

void ReadPersonsInfo(strInfo Persons[100], int& NumberOfPersons)
{
    cout << "How many persons?\n";
    cin >> NumberOfPersons;

    for (int i = 0; i <= NumberOfPersons - 1; i++)
    {
        cout << "\nPlease,enter Person's " << i + 1 << " Info : \n";
        ReadInfo(Persons[i]);
    }
}

void PrintPersonsInfo(strInfo Persons[100], int NumberOfPersons)
{
    for (int i = 0; i <= NumberOfPersons - 1; i++)
    {
        cout << "\nPerson's " << i + 1 << " Info : \n";
        PrintInfo(Persons[i]);
    }
}

int main()
{
    strInfo Persons[100];
    int NumberOfPersons;

    ReadPersonsInfo(Persons, NumberOfPersons);
    PrintPersonsInfo(Persons, NumberOfPersons);

    return 0;
}
