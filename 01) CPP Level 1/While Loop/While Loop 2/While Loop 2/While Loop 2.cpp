#include <iostream>
using namespace std;

int main()
{
    int Number;
    cout << "Please,enter the positive number?\n";
    cin >> Number;

    while (Number < 1)
    {
        cout << "Wrong Number, Please,enter the positive number?\n";
        cin >> Number;
    }

    cout << "\nThe number you entered is " << Number << endl;

    return 0;
}
