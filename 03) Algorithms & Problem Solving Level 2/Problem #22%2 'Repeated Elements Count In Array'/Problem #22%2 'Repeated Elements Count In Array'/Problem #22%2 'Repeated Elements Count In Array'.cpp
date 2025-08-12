#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void ReadArray(int arr[100], int& arrLength)
{
    cout << "Enter number of elements:" << endl;
    cin >> arrLength;

    cout << "\nEnter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
    cout << "\n Original array: ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (Number == arr[i])
        {
            Counter++;
        }
    }

    return Counter;
}

int main()
{
    int arr[100], arrLength, NumberToCheck;

    ReadArray(arr, arrLength);

    NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");

    PrintArray(arr, arrLength);

    cout << "\n Number " << NumberToCheck << " is repeated "
        << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)." << endl;

    return 0;
}