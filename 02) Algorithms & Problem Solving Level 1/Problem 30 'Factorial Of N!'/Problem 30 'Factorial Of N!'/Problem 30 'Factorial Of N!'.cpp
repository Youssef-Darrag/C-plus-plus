#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

int Factorial(int Number)
{
    int Factorial = 1;

    for (int i = Number; i >= 1; i--)
    {
        Factorial = Factorial * i;
    }

    return Factorial;
}

int main()
{
    cout << "\n Factorial = " << Factorial(ReadPositiveNumber("Enter Number ?")) << endl;

    return 0;
}