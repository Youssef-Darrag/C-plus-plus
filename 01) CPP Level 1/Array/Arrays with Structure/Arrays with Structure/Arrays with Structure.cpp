#include <iostream>
using namespace std;

struct stInfo
{
    string FristName;
    string LastName;
    int Age;
    string Phone;
};

int main()
{
    stInfo Persons[2];

    Persons[0].FristName = "Youssef";
    Persons[0].LastName = "Darrag";
    Persons[0].Age = 20;
    Persons[0].Phone = "01056644654";

    Persons[1].FristName = "Ali";
    Persons[1].LastName = "Maher";
    Persons[1].Age = 25;
    Persons[1].Phone = "01254648484";

    cout << Persons[1].FristName << endl;
}

