#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Please,enter a Number?\n";
    cin >> Number;

    return Number;
}

void CheckNumber(int Number)
{
    if (Number % 2 == 0)
    {
        cout << "The Number is Even\n";
    }
    else
    {
        cout << "The Number is Odd\n";
    }
}

int main()
{
    int Number;

    CheckNumber(ReadNumber());

    return 0;
}
