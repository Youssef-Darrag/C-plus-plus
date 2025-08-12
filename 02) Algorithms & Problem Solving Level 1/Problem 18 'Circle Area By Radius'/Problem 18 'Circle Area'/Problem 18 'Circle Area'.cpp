#include <iostream>
using namespace std;

float ReadRadius()
{
    float R;

    cout << "Please,enter radius R ?" << endl;
    cin >> R;

    return R;
}

float CalculateCircleArea(float R)
{
    const float PI = 3.141592653589793238;
    float Area = PI * pow(R, 2);
    
    return Area;
}

void PrintResult(float Area)
{
    cout << "\n Circle Area = " << Area << endl;
}

int main()
{
    PrintResult(CalculateCircleArea(ReadRadius()));

    return 0;
}