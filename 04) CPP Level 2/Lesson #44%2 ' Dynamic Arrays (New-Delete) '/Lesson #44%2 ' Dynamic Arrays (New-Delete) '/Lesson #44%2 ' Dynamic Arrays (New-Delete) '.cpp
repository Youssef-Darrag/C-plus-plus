#include <iostream>
using namespace std;

int main()
{
    int Num;

    cout << "Enter total number of students: ";
    cin >> Num;

    float* ptr;

    ptr = new float[Num];

    cout << "Enter grades of students." << endl;
    for (int i = 0; i < Num; i++)
    {
        cout << "Student" << i + 1 << " : ";
        cin >> *(ptr + i);
    }

    cout << "\nDisplaying grades of students." << endl;
    for (int i = 0; i < Num; i++)
    {
        cout << "Student" << i + 1 << " : " << *(ptr + i) << endl;
    }

    delete[] ptr;

    return 0;
}