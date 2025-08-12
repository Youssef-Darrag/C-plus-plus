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

void PrintPerfectNumbersFrom1ToN(int Number)
{
    cout << "\n Perfect Numbers from 1 to " << Number << " are : " << endl;
    for (int j = 1; j <= Number; j++)
    {
        if (isPerfectNumber(j))
        {
            cout << j << endl;
        }
    }
}

int main()
{
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please,enter a positive number?"));

    return 0;
}