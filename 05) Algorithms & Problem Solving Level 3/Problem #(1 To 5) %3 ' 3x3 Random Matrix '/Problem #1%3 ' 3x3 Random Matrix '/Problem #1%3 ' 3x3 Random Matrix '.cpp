#include <iostream>
#include <iomanip>
using namespace std;

// Problem #1 " 3x3 Random Matrix " 
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Raws, short Cols)
{
    for (short i = 0; i < Raws; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << " The following is a 3x3 random matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    system("pause>0");
}










// Problem #2 " Sum Each Row in Matrix Without Using arr for Sum "
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Raws, short Cols)
{
    for (short i = 0; i < Raws; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumber][j];
    }

    return Sum;
}

void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << RowSum(arr,i,Cols) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The following is a 3x3 random matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each row in the matrix:" << endl;
    PrintEachRowSum(arr, 3, 3);

    system("pause>0");
}










// Problem #3 " Sum Each Row in Matrix With Using arr for Sum "
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Raws, short Cols)
{
    for (short i = 0; i < Raws; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumber][j];
    }

    return Sum;
}

void SumMatrixRowsInArray(int arrSum[3], int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(arr, i, Cols);
    }
}

void PrintRowsSumArray(int arrSum[3], short Rows)
{
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << arrSum[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The following is a 3x3 random matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    SumMatrixRowsInArray(arrSum, arr, 3, 3);

    cout << "\nThe following are the sum of each row in the matrix:" << endl;
    PrintRowsSumArray(arrSum, 3);

    system("pause>0");
}










// Problem #4 " Sum Each Col in Matrix Without Using arr for Sum "
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Raws, short Cols)
{
    for (short i = 0; i < Raws; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColNumber];
    }

    return Sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
    for (short j = 0; j < Cols; j++)
    {
        cout << " Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The following is a 3x3 random matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each col in the matrix:" << endl;
    PrintEachColSum(arr, 3, 3);

    system("pause>0");
}










// Problem #5 " Sum Each Col in Matrix With Using arr for Sum "
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Raws, short Cols)
{
    for (short i = 0; i < Raws; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColNumber];
    }

    return Sum;
}

void SumMatrixColsInArray(int arrSum[3], int arr[3][3], short Rows, short Cols)
{
    for (short j = 0; j < Cols; j++)
    {
        arrSum[j] = ColSum(arr, Rows, j);
    }
}

void PrintColsSumArray(int arrSum[3], short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << arrSum[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The following is a 3x3 random matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    SumMatrixColsInArray(arrSum, arr, 3, 3);

    cout << "\nThe following are the sum of each col in the matrix:" << endl;
    PrintColsSumArray(arrSum, 3);

    system("pause>0");
}