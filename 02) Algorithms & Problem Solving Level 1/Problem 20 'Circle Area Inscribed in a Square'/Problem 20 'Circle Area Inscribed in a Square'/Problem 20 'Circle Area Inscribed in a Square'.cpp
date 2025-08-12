#include <iostream>
using namespace std;

float ReadSquareSide()
{
    float A;

    cout << "Please,enter square side A ?" << endl;
    cin >> A;

    return A;
}

float CalculateCircleAreaInscribedInSquare(float A)
{
    const float PI = 3.141592653589793238;
    float Area = (PI * pow(A, 2)) / 4;

    return Area;
}

void PrintResult(float Area)
{
    cout << "\n Circle Area = " << Area << endl;
}

int main()
{
    PrintResult(CalculateCircleAreaInscribedInSquare(ReadSquareSide()));

    return 0;
}