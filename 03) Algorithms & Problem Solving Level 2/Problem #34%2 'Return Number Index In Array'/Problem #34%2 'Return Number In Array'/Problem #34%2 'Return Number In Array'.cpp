#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;

    cout << "\nPlease,enter a number to search for?\n";
    cin >> Number;

    return Number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Enter number of elements: " << endl;
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\n Array 1 elements: " << endl;
    PrintArray(arr, arrLength);

    int Number = ReadNumber();
    cout << "\n Number you are looking for is: " << Number << endl;

    short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);

    if (NumberPosition == -1)
        cout << " The number is not found :-(" << endl;
    else
    {
        cout << " The number found at position: " << NumberPosition << endl;
        cout << " The number found its order  : " << NumberPosition + 1 << endl;
    }

    return 0;
}