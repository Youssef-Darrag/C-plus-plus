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

int main()
{
    int Number = ReadPositiveNumber("Please,enter the main number?");
    short DigitToCheck = ReadPositiveNumber("Please,enter one digit to check?");

    cout << "\n Digit " << DigitToCheck << " Frequency is "
        << CountDigitFrequency(DigitToCheck, Number) << " time(s)" << endl;

    return 0;
}