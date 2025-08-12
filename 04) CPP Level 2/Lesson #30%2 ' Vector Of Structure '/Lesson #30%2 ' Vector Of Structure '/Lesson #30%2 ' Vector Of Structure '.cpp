#include <iostream>
#include <vector>
using namespace std;
 
// Lesson Vector Of Structure
struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};

int main()
{
    vector <stEmployee> vEmployees;

    stEmployee TempEmployee;

    TempEmployee.FirstName = "Reham";
    TempEmployee.LastName = "Darrag";
    TempEmployee.Salary = 10000;
    vEmployees.push_back(TempEmployee);

    TempEmployee.FirstName = "Youssef";
    TempEmployee.LastName = "Talab";
    TempEmployee.Salary = 5000;
    vEmployees.push_back(TempEmployee);

    TempEmployee.FirstName = "Darrag";
    TempEmployee.LastName = "Talab";
    TempEmployee.Salary = 15000;
    vEmployees.push_back(TempEmployee);

    cout << "Employees Vector : \n\n";

    for (stEmployee& Employee : vEmployees)
    {
        cout << "FirstName: " << Employee.FirstName << endl;
        cout << "LastName : " << Employee.LastName << endl;
        cout << "Salary   : " << Employee.Salary << endl;
        cout << endl;
    }
    cout << endl;

    return 0;
}




// Homework
struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};

void ReadEmployees(vector <stEmployee>& vEmployees)
{
    stEmployee TempEmployee;
    char ReadMore = 'Y';

    do
    {
        cout << "Enter FirstName ? ";
        cin >> TempEmployee.FirstName;

        cout << "Enter LastName ? ";
        cin >> TempEmployee.LastName;

        cout << "Enter Salary ? ";
        cin >> TempEmployee.Salary;

        vEmployees.push_back(TempEmployee);

        cout << "\nDo you want to read more employees ? Y/N ? ";
        cin >> ReadMore;
    } while (ReadMore == 'Y' || ReadMore == 'y');
}

void PrintEmployees(vector <stEmployee>& vEmployees)
{
    cout << "\nEmployees Vector : \n\n";

    for (stEmployee& Employee : vEmployees)
    {
        cout << "FirstName: " << Employee.FirstName << endl;
        cout << "LastName : " << Employee.LastName << endl;
        cout << "Salary   : " << Employee.Salary << endl;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector <stEmployee> vEmployees;

    ReadEmployees(vEmployees);
    PrintEmployees(vEmployees);

    return 0;
}