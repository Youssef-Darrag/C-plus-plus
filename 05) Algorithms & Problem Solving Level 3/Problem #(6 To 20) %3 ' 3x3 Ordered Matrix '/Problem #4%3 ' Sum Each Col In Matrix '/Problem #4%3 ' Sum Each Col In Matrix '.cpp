#include <iostream>
using namespace std;

// Problem #6 " 3x3 Ordered Matrix "
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "      ";
		}
		cout << endl;
	}
}

int main()
{
	int arr[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);

	cout << "The following is a 3x3 ordered matrix:" << endl;
	PrintMatrix(arr, 3, 3);

	system("pause>0");
}










// Problem #7 " Transpose Matrix "
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "      ";
		}
		cout << endl;
	}
}

void TransposeMatrix(int arrTransposed[3][3], int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}

int main()
{
	int arr[3][3], arrTransposed[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);

	cout << "The following is a 3x3 ordered matrix:" << endl;
	PrintMatrix(arr, 3, 3);

	TransposeMatrix(arrTransposed, arr, 3, 3);

	cout << "\n\nThe following is the transposed matrix:" << endl;
	PrintMatrix(arrTransposed, 3, 3);

	system("pause>0");
}










// Problem #8 " Multiply Two Matrices "
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
			arr[i][j] = RandomNumber(1, 10);
		}		
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

void MultiplyMatrix(int MatrixResults[3][3], int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n\nMatrix2:" << endl;
	PrintMatrix(Matrix2, 3, 3);

	MultiplyMatrix(MatrixResults, Matrix1, Matrix2, 3, 3);
	cout << "\n\nResults:" << endl;
	PrintMatrix(MatrixResults, 3, 3);

	system("pause>0");
}










// Problem #9 " Print Middle Row and Col of Matrix "
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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;

	for (short j = 0; j < Cols; j++)
	{
		printf(" %0*d    ", 2, arr[MiddleRow][j]);
	}
	cout << endl;
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;

	for (short i = 0; i < Rows; i++)
	{
		printf(" %0*d    ", 2, arr[i][MiddleCol]);
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Row of Matrix1 is:" << endl;
	PrintMiddleRowOfMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Col of Matrix1 is:" << endl;
	PrintMiddleColOfMatrix(Matrix1, 3, 3);

	system("pause>0");
}










// Problem #10 " Sum of Matrix "
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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += Matrix1[i][j];
		}
	}

	return Sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum of Matrix1 is: " << SumOfMatrix(Matrix1, 3, 3) << endl;

	system("pause>0");
}










// Problem #11 " Check Matrices Equality "
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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += Matrix1[i][j];
		}
	}

	return Sum;
}

bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols);
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n\nMatrix2:" << endl;
	PrintMatrix(Matrix2, 3, 3);

	if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYes: both matrices are equal.\n";
	else
		cout << "\nNo: matrices are NOT equal.\n";

	system("pause>0");
}










// Problem #12 " Check Typical Matrices "
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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}

	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n\nMatrix2:" << endl;
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYes: both matrices are typical.\n";
	else
		cout << "\nNo: matrices are NOT typical.\n";

	system("pause>0");
}










// Problem #13 " Check Identity Matrix "
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

bool IsIdentityMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix1[i][j] != 1)
			{
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0)
			{		
				return false;
			}
		}
	}

	return true;
}

int main()
{
	//int Matrix1[3][3] = { {1,2,3} , {4,5,6} , {7,8,9} };
	int Matrix1[3][3] = { {1,0,0} , {0,1,0} , {0,0,1} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	if (IsIdentityMatrix(Matrix1, 3, 3))
		cout << "\nYes: Matrix is identity.\n";
	else
		cout << "\nNo: Matrix is NOT identity.\n";

	system("pause>0");
}










// Problem #14 " Check Scalar Matrix "
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int FirstDiagElement = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix1[i][j] != FirstDiagElement)
			{
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int Matrix1[3][3] = { {9,0,0} , {0,9,0} , {0,0,9} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrix(Matrix1, 3, 3))
		cout << "\nYes: Matrix is scalar.\n";
	else
		cout << "\nNo: Matrix is NOT scalar.\n";

	system("pause>0");
}










// Problem #15 " Count Number in Matrix "

#include <iomanip>

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
				NumberCount++;
		}
	}

	return NumberCount;
}

int main()
{
	int Matrix1[3][3] = { {9,1,12} , {0,9,1} , {0,9,9} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	int Number;
	cout << "\nEnter the number to count in matrix? ";
	cin >> Number;

	cout << "\nNumber " << Number << " count in matrix is "
		<< CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;

	system("pause>0");
}










// Problem #16 " Check Sparse Matrix "
// #include <iomanip>
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
				NumberCount++;
		}
	}

	return NumberCount;
}

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;

	return CountNumberInMatrix(Matrix1, 0, 3, 3) > (MatrixSize / 2);
}

int main()
{
	int Matrix1[3][3] = { {0,0,12} , {0,0,1} , {0,0,9} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	if(IsSparseMatrix(Matrix1, 3, 3))
		cout << "\nYes: Matrix is Sparse.\n";
	else
		cout << "\nNo: Matrix is NOT Sparse.\n";

	system("pause>0");
}










// Problem #17 " Check Number Exists in Matrix "
// #include <iomanip>
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
				return true;
		}
	}

	return false;
}

int main()
{
	int Matrix1[3][3] = { {77,5,12} , {22,20,1} , {1,0,9} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	int Number;
	cout << "\nPlease, Enter the number to look for in matrix? ";
	cin >> Number;

	if (IsNumberInMatrix(Matrix1, Number, 3, 3))
		cout << "\nYes: it is there.\n";
	else
		cout << "\nNo: it's NOT there.\n";

	system("pause>0");
}










// Problem #18 " Intersected Numbers in Matrices "
// #include <iomanip>
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
				return true;
		}
	}

	return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int Number = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];

			if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
			{
				cout << Number << "     ";
			}	
		}
	}
}

int main()
{
	int Matrix1[3][3] = { {77,5,12} , {22,20,1} , {1,0,9} };
	int Matrix2[3][3] = { {5,80,90} , {22,77,1} , {10,8,33} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	cout << "Matrix2:" << endl;
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are:\n";
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	system("pause>0");
}










// Problem #19 " Min/Max Number in Matrix "
// #include <iomanip>
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Min = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] < Min)
			{
				Min = Matrix1[i][j];
			}
		}
	}

	return Min;
}

int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Max = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] > Max)
			{
				Max = Matrix1[i][j];
			}
		}
	}

	return Max;
}

int main()
{
	int Matrix1[3][3] = { {77,5,12} , {22,20,6} , {14,3,9} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMinimum Number is: " << MinNumberInMatrix(Matrix1, 3, 3) << endl;

	cout << "\nMaximum Number is: " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;

	system("pause>0");
}










// Problem #20 " Palindrome Matrix "
// #include <iomanip>
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix1[i][j] != Matrix1[i][2 - j])
				return false;
		}
	}

	return true;
}

int main()
{
	int Matrix1[3][3] = { {1,2,1} , {5,5,5} , {7,3,7} };

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	if (IsPalindromeMatrix(Matrix1, 3, 3))
		cout << "\nYes: Matrix is Palindrome.\n";
	else
		cout << "\nNo: Matrix is NOT Palindrome.\n";

	system("pause>0");
}