#include <iostream>
using namespace std;

int main()
{
    int Num1, Num2; char OperationType;

    cout << "Please,enter the Num1?\n";
    cin >> Num1;
    cout << "Please,enter the Num2?\n";
    cin >> Num2;
    cout << "Please,enter the OperationType?\n";
    cin >> OperationType;

    switch (OperationType)
    {
    case '+':
        cout << "Add the two numbers = " << Num1 + Num2 << endl;
        break;
    case '-':
        cout << "Subtract the two numbers = " << Num1 - Num2 << endl;
        break;
    case '*':
        cout << "Multiply the two numbers = " << Num1 * Num2 << endl;
        break;
    case '/':
        cout << "Devide the two numbers = " << Num1 / Num2 << endl;
    }

    return 0;
}
