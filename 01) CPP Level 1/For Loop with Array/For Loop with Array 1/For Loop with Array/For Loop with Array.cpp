#include <iostream>
using namespace std;

void ReadArrayData(int Arr[100], int& Length)
{
    cout << "How many Numbers do you want to enter? 1 to 100?\n";
    cin >> Length;

    for (int i = 0; i <= Length - 1; i++)
    {
        cout << "Please,enter Number " << i + 1 << endl;
        cin >> Arr[i];
    }
}

void PrintArrayData(int Arr[100], int Length)
{
    for (int i = 0; i <= Length - 1; i++)
    {
        cout << "Number [" << i + 1 << "] : " << Arr[i] << endl;
    }
}

int CalculateArraySum(int Arr[100], int Length)
{    
    int Sum = 0;
    for (int i = 0; i <= Length - 1; i++)
    {
        Sum += Arr[i];
    } 
    return Sum;
}

float CalculateArrayAverage(int Arr[100], int Length)
{
    return float(CalculateArraySum(Arr , Length)) / Length;
}
int main()
{
    int Arr[100], Length;
    ReadArrayData(Arr, Length);
    PrintArrayData(Arr, Length);
    
    int Sum = CalculateArraySum(Arr, Length);

    cout << "\n*******************************************\n";
    cout << "Sum = " << Sum << endl;
    cout << "Average = " << float(Sum) / Length << endl;

}
