#include <iostream>
using namespace std;

int main()
{
    int Sum = 0;
    int Number;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter a number:  ";
        cin >> Number;

        // continue condition 
        if (Number > 50)
        {
            cout << "The number is greater than 50 and won't be calculated." << endl;
            continue;
        }
        Sum += Number;
    }

    cout << "\nThe Sum is  " << Sum << endl;

    return 0;
}
