#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Please,enter the number?" << endl;
    cin >> Number;

    return Number;
}

int ReadPower()
{
    int M;

    cout << "Please,enter the power?" << endl;
    cin >> M;

    return M;
}

int PowerOfM(int Number, int M)
{
    if (M == 0)
    {
        return 1;
    }

    int P = 1;
    for (int i = 1; i <= M; i++)
    {
        P = P * Number;
    }

    return P;
}

int main()
{
    cout << "\n Result = " << PowerOfM(ReadNumber(), ReadPower()) << endl;

    return 0;
}