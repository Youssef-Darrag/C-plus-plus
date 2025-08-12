#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Please,enter the number?" << endl;
    cin >> Number;

    return Number;
}

void PowerOf2_3_4(int Number)
{
    int A, B, C;

    A = Number * Number;
    B = Number * Number * Number;
    C = Number * Number * Number * Number;

    cout << "\n " << A << "  " << B << "  " << C << endl;

}

int main()
{
    PowerOf2_3_4(ReadNumber());

    return 0;
}