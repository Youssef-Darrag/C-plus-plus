#include <iostream>
using namespace std;

// Code Recursion ' Print Numbers From N To M '
void PrintNumbers(int N, int M)
{
    if (N <= M)
    {
        cout << N << endl;
        PrintNumbers(N + 1, M);
    }
}

int main()
{
    PrintNumbers(1, 10);

    return 0;
}




// Homework 1 ' Print Numbers From M To N '
void PrintNumbersFromMtoN(int M, int N)
{
    if (M >= N)
    {
        cout << M << endl;
        PrintNumbersFromMtoN(M - 1, N);
    }
}

int main()
{
    PrintNumbersFromMtoN(10, 1);

    return 0;
}




// Homework 2 ' Calculate Power N^M '
int MyPower(int Base, int Power)
{
    if (Power == 0)
        return 1;
    else
        return (Base * MyPower(Base, Power - 1));
}

int main()
{
    cout << MyPower(2, 4);

    return 0;
}