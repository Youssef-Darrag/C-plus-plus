#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Please,enter the number?" << endl;
    cin >> Number;

    return Number;
}

void PrintRangeFrom1ToN_UsingWhile(int Number)
{
    cout << "Range printed using while statement:" << endl;

    int i = 1;
    while (i <= Number)
    {
        cout << i << endl;
        i++;
    }
}

void PrintRangeFrom1ToN_UsingDoWhile(int Number)
{
    cout << "Range printed using Do..While statement:" << endl;

    int i = 1;
    do
    {
        cout << i << endl;
        i++;
    } while (i <= Number);
}

void PrintRangeFrom1ToN_UsingFor(int Number)
{
    cout << "Range printed using For statement:" << endl;

    for (int i = 1; i <= Number; i++)
    {
        cout << i << endl;
    }
}

int main()
{
    int Number = ReadNumber();

    PrintRangeFrom1ToN_UsingWhile(Number);
    PrintRangeFrom1ToN_UsingDoWhile(Number);
    PrintRangeFrom1ToN_UsingFor(Number);

    return 0;
}