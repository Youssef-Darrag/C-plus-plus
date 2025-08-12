#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void PrintLetterPattern(int Number)
{
    cout << endl;
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        for (int j = 65; j <= i; j++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}

int main()
{
    PrintLetterPattern(ReadPositiveNumber("Please,enter a positive number?"));

    return 0;
}