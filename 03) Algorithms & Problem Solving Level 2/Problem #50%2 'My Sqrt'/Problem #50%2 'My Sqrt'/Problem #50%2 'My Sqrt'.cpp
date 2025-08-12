#include <iostream>
using namespace std;

float ReadNumber()
{
    float Number;
    cout << "Please,enter a float number? ";
    cin >> Number;

    return Number;
}

float MySqrt(float Number)
{
    return pow(Number, 0.5);
}

int main()
{
    float Number = ReadNumber();

    cout << "\n My Sqrt Result : " << MySqrt(Number) << endl;
    cout << " C++ Sqrt Result: " << sqrt(Number) << endl;

    return 0;
}