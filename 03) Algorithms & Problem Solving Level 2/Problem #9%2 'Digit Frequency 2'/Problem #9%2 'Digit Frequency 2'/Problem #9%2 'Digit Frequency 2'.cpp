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

int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Remainder = 0, FreqCount = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        if (Remainder == DigitToCheck)
        {
            FreqCount++;
        }
    }

    return FreqCount;
}

void PrintAllDigitsFrequency()
{
    int Number = ReadPositiveNumber("Please,enter a positive number?");
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        if (CountDigitFrequency(i, Number) > 0)
        {
            cout << " Digit " << i << " Frequency is " << CountDigitFrequency(i, Number) << " time(s)\n";
        }
    }
}

int main()
{
    PrintAllDigitsFrequency();

    return 0;
}