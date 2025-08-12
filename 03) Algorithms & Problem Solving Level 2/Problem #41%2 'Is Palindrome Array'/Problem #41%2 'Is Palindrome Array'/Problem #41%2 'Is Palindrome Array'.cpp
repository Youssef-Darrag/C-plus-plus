#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool IsPalindromeArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] == arr[Length - 1 - i])
            return true;
    }
    return false;
}

int main()
{
    int arr[100], Length = 0;
    FillArray(arr, Length);

    cout << "\n Array Elements: " << endl;
    PrintArray(arr, Length);

    if (IsPalindromeArray(arr, Length))
        cout << "\n Yes,Array is Palindrome." << endl;
    else
        cout << "\n No,Array is not Palindrome." << endl;
    
    return 0;
}