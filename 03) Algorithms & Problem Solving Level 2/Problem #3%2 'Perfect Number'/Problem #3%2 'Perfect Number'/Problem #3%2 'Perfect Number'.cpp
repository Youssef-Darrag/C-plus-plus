#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

bool isPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum += i;
        }
    }

    return Sum == Number;
}

void PrintResult(int Number)
{
    if (isPerfectNumber(Number))
        cout << Number << " is Perfect Number.\n";
    else
        cout << Number << " is not Perfect Number.\n";
}

int main()
{
    PrintResult(ReadPositiveNumber("Please,enter a positive number?"));

    return 0;
}