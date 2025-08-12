#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Please,enter a number?  ";
    cin >> Number;

    return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;
    do
    {
        AddArrayElement(ReadNumber(),arr,arrLength);

        cout << "Do you want to add more numbers? [0]:No,[1]:Yes ?  ";
        cin >> AddMore;
        cout << endl;
    } while (AddMore);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100], arrLength = 0;
    InputUserNumbersInArray(arr, arrLength);

    cout << "\n Array Length : " << arrLength << endl;
    cout << " Array elements : ";
    PrintArray(arr, arrLength);

    return 0;
}