#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& B)
{
    cout << "Please,enter rectangle width A ?" << endl;
    cin >> A;
    cout << "Please,enter rectangle length B ?" << endl;
    cin >> B;
}

float CalculateRectangleArea(float A, float B)
{
    return A * B;
}

void PrintResult(float Area)
{
    cout << "\n Rectangle Area = " << Area << endl;
}

int main()
{
    float A, B;

    ReadNumbers(A, B);
    PrintResult(CalculateRectangleArea(A, B));

    return 0;
}