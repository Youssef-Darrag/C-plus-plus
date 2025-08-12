#include <iostream>
using namespace std;

int ReadIntNumberInRange(int From, int To)
{
    int Number;
    cout << "Please,enter a number between " << From << " and " << To << endl;
    cin >> Number;

    while (Number < From || Number > To)
    {
        cout << "Wrong Number,";
        cout << "Please,enter a number between " << From << " and " << To << endl;
        cin >> Number;
    }

    return Number;
}
int main()
{
    cout << "\n The Number is " << ReadIntNumberInRange(18, 45) << endl;

    return 0;
}
