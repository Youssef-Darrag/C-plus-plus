#include <iostream>
using namespace std;

float ReadDiameter()
{
    float D;

    cout << "Please,enter diameter D ?" << endl;
    cin >> D;

    return D;
}

float CalculateCircleAreaByDiameter(float D)
{
    const float PI = 3.141592653589793238;
    float Area = (PI * pow(D, 2)) / 4;

    return Area;
}

void PrintResult(float Area)
{
    cout << "\n Circle Area = " << Area << endl;
}

int main()
{
    PrintResult(CalculateCircleAreaByDiameter(ReadDiameter()));

    return 0;
}