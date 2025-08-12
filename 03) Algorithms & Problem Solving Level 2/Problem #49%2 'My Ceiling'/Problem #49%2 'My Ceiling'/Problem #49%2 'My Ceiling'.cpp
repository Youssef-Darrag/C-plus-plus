#include <iostream>
using namespace std;

float ReadNumber()
{
    float Number;
    cout << "Please,enter a float number? ";
    cin >> Number;

    return Number;
}

int MyCeil(float Number)
{
    if (Number > 0)
        return int(Number) + 1;
    else
        return int(Number);
}

int main()
{
    float Number = ReadNumber();

    cout << "\n My Ceiling Result : " << MyCeil(Number) << endl;
    cout << " C++ Ceiling Result: " << ceil(Number) << endl;

    return 0;
}