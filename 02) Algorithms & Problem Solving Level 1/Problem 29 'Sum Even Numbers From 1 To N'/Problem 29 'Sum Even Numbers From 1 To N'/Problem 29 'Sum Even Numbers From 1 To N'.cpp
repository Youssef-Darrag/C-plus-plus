#include <iostream>
using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
    int Number;

    cout << "Please,enter the number?" << endl;
    cin >> Number;

    return Number;
}

enOddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 == 0)
        return enOddOrEven::Even;
    else
        return enOddOrEven::Odd;
}

int SumEvenNumbersFrom1ToN_UsingWhile(int Number)
{
    cout << "Sum even numbers using while statement:" << endl;

    int Sum = 0;
    int i = 1;
    while (i <= Number)
    {
        if (CheckOddOrEven(i) == enOddOrEven::Even)
        {
            Sum += i;
        }
        i++;
    }

    return Sum;
}

int SumEvenNumbersFrom1ToN_UsingDoWhile(int Number)
{
    cout << "Sum even numbers using Do..While statement:" << endl;

    int Sum = 0;
    int i = 1;
    do
    {
        if (CheckOddOrEven(i) == enOddOrEven::Even)
        {
            Sum += i;
        }
        i++;
    } while (i <= Number);

    return Sum;
}

int SumEvenNumbersFrom1ToN_UsingFor(int Number)
{
    cout << "Sum even numbers using For statement:" << endl;

    int Sum = 0;
    for (int i = 1; i <= Number; i++)
    {
        if (CheckOddOrEven(i) == enOddOrEven::Even)
        {
            Sum += i;
        }
    }

    return Sum;
}

int main()
{
    int N = ReadNumber();

    cout << SumEvenNumbersFrom1ToN_UsingWhile(N) << endl;
    cout << SumEvenNumbersFrom1ToN_UsingDoWhile(N) << endl;
    cout << SumEvenNumbersFrom1ToN_UsingFor(N) << endl;

    return 0;
}