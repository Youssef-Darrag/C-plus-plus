#include <iostream>
using namespace std;

float ReadCircumference()
{
    float L;

    cout << "Please,enter circumference L ?" << endl;
    cin >> L;

    return L;
}

float CalculateCircleAreaByCircumference(float L)
{
    const float PI = 3.141592653589793238;
    float Area = pow(L, 2) / (4 * PI);

    return Area;
}

void PrintResult(float Area)
{
    cout << "\n Circle Area = " << Area << endl;
}

int main()
{
    PrintResult(CalculateCircleAreaByCircumference(ReadCircumference()));

    return 0;
}