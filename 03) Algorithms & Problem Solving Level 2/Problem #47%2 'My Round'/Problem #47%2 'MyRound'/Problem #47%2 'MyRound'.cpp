#include <iostream>
using namespace std;

float ReadNumber()
{
    float Number;
    cout << "Please,enter a float number? ";
    cin >> Number;

    return Number;
}

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{
    int IntPart;
    IntPart = int(Number);

    float FractionPart = GetFractionPart(Number);

    if (abs(FractionPart) >= 0.5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
        return IntPart;
}

int main()
{
    float Number = ReadNumber();

    cout << "\n My Round Result : " << MyRound(Number) << endl;
    cout << " C++ Round Result: " << round(Number) << endl;

    return 0;
}