#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int& x = a;

    cout << &a << endl;
    cout << &x << endl;
    cout << endl;

    cout << a << endl;
    cout << x << endl;
    cout << endl;

    a = 20;

    cout << a << endl;
    cout << x << endl;
    cout << endl;

    x = 50;

    cout << a << endl;
    cout << x << endl;
    cout << endl;

    return 0;
}