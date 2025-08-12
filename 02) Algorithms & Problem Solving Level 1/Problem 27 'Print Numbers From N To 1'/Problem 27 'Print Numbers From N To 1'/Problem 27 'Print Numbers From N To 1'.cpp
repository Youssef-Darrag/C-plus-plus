#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Please,enter the number?" << endl;
    cin >> Number;

    return Number;
}

void PrintRangeFromNTo1_UsingWhile(int Number)
{
    cout << "Range printed using while statement:" << endl;

    int i = Number;
    while (i >= 1)
    {
        cout << i << endl;
        i--;
    }
}

void PrintRangeFromNTo1_UsingDoWhile(int Number)
{
    cout << "Range printed using Do..While statement:" << endl;

    int i = Number;
    do
    {
        cout << i << endl;
        i--;
    } while (i >= 1);
}

void PrintRangeFromNTo1_UsingFor(int Number)
{
    cout << "Range printed using For statement:" << endl;

    for (int i = Number; i >= 1; i--)
    {
        cout << i << endl;
    }
}

int main()
{
    int N = ReadNumber();

    PrintRangeFromNTo1_UsingWhile(N);
    PrintRangeFromNTo1_UsingDoWhile(N);
    PrintRangeFromNTo1_UsingFor(N);

    return 0;
}