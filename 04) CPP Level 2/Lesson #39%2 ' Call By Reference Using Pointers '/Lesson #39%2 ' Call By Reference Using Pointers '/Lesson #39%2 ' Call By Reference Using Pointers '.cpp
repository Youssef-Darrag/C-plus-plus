#include <iostream>
using namespace std;

// Reference 
void Swap(int& n1, int& n2)
{
    int Temp;

    Temp = n1;
    n1 = n2;
    n2 = Temp;
}

int main()
{
    int a = 1, b = 2;

    cout << "Before Swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    Swap(a, b);

    cout << "\nAfter Swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}





// Pointer
void Swap(int* n1, int* n2)
{
    int Temp;

    Temp = *n1;
    *n1 = *n2;
    *n2 = Temp;
}

int main()
{
    int a = 1, b = 2;

    cout << "Before Swapping" << endl;;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    Swap(&a, &b);

    cout << "\nAfter Swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}