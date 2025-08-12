#include <iostream>
using namespace std;

// Pointers and Arrays
int main()
{
    int arr[4] = { 10,20,30,40 };
    int* ptr;
    ptr = arr;

    // ptr is equivalent to &arr[0];
    // ptr + 1 is equivalent to &arr[1];
    // ptr + 2 is equivalent to &arr[2];
    // ptr + 3 is equivalent to &arr[3];

    cout << "Addresses are:\n";
    cout << ptr << endl;
    cout << ptr + 1 << endl;
    cout << ptr + 2 << endl;
    cout << ptr + 3 << endl;

    cout << "\nValues are:\n";
    cout << *(ptr) << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;
    cout << *(ptr + 3) << endl;

    return 0;
}





// Pointers and Structure
struct stEmployee
{
    string Name;
    float Salary;
};

int main()
{
    stEmployee Employee1, * ptr;

    Employee1.Name = "Reham Bint Youssef";
    Employee1.Salary = 10000;

    cout << Employee1.Name << endl;
    cout << Employee1.Salary << endl;

    ptr = &Employee1;

    cout << "\nUsing Pointer:\n";
    cout << ptr->Name << endl;
    cout << ptr->Salary << endl;

    return 0;
}