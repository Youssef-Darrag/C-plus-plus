#include <iostream>
using namespace std;

void ReadNumbers(int& Num1,int& Num2)
{
    cout << "Please,enter the number 1 ?" << endl;
    cin >> Num1;
    cout << "Please,enter the number 2 ?" << endl;
    cin >> Num2;
}

int MaxOf2Numbers(int Num1, int Num2)
{
    if (Num1 > Num2)
        return Num1;
    else
        return Num2;
}

void PrintResult(int Max)
{
    cout << "\n The Maximum Number is: " << Max << endl;
}
int main()
{
    int Num1, Num2;

    ReadNumbers(Num1, Num2);
    PrintResult(MaxOf2Numbers(Num1, Num2));

    return 0;
}