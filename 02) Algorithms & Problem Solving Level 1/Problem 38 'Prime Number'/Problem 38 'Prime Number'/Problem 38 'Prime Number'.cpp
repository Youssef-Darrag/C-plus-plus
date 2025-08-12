#include <iostream>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckNumber(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}

void PrintNumberType(int Number)
{
    switch(CheckNumber(Number))
    {
    case enPrimeNotPrime::Prime:
        cout << "The Number is Prime\n";
        break;
    case enPrimeNotPrime::NotPrime:
        cout << "The Number is Not Prime\n";
        break;
    }
}

int main()
{
    PrintNumberType(ReadPositiveNumber("Please,enter a positive number?"));

    return 0;
}