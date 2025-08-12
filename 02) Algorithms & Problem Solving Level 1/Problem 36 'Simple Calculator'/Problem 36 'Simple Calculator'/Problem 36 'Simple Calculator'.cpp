#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Message)
{
    float Number;

    cout << Message << endl;
    cin >> Number;

    return Number;
}

enOperationType ReadOperationType()
{
    char OperationType = '+';
     
    cout << "Please,enter Operation Type ( + , - , * , / ) ?" << endl;
    cin >> OperationType;

    return (enOperationType)OperationType;
}

float Calculate(float Number1, float Number2, enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Subtract:
        return Number1 - Number2;
    case enOperationType::Multiply:
        return Number1 * Number2;
    case enOperationType::Divide:
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

int main()
{
    float Number1 = ReadNumber("Please,enter the first number?");
    float Number2 = ReadNumber("Please,enter the second number?");
    enOperationType OperationType = ReadOperationType();

    cout << "\n Result = " << Calculate(Number1, Number2, OperationType) << endl;
    
    return 0;
}