#include <iostream>
using namespace std;

void ReadTriangleData(float& A, float& B, float& C)
{
    cout << "Please,enter triangle side A ?" << endl;
    cin >> A;
    cout << "Please,enter triangle base B ?" << endl;
    cin >> B;
    cout << "Please,enter triangle side C ?" << endl;
    cin >> C;
}

float CalculateCircleAreaByArbitraryTriangle(float A, float B, float C)
{
    const float PI = 3.141592653589793238;
    float P;
    P = (A + B + C) / 2;

    float T;
    T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));

    float Area = PI * pow(T, 2);

    return Area;
}

void PrintResult(float Area)
{
    cout << "\n Circle Area = " << Area << endl;
}

int main()
{
    float A, B, C;
    ReadTriangleData(A, B, C);
    PrintResult(CalculateCircleAreaByArbitraryTriangle(A, B, C));

    return 0;
}