#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& D)
{
    cout << "Please,enter rectangle side A ?" << endl;
    cin >> A;
    cout << "Please,enter rectangle diagonal D ?" << endl;
    cin >> D;
}

float RectangleAreaBySideAndDiagonal(float A, float D)
{
    float Area = A * sqrt(pow(D, 2) - pow(A, 2));

    return Area;
}

void PrintResult(float Area)
{
    cout << "\n Rectangle Area = " << Area << endl;
}

int main()
{
    float A, D;

    ReadNumbers(A, D);
    PrintResult(RectangleAreaBySideAndDiagonal(A, D));

    return 0;
}