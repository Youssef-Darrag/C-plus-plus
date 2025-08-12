#include <iostream>
using namespace std;

int main()
{
    int Number;

    do
    {
        cout << "Please,enter the Positive Number?\n";
        cin >> Number;

    } while (Number <= 0);

    int i = Number;
    int Factorial = 1;
    while (i >= 1)
    {
        Factorial = Factorial * i;
        i--;
    }
    cout << "Factorial = " << Factorial << endl;

    return 0;
}
