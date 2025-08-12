#include <iostream>
using namespace std;

int main()
{
    int Number;
    cout << "Please,enter the Number?\n";
    cin >> Number;

    int Sum = 0;
    while (Number != -99)
    {
        Sum += Number;
        cout << "Please,enter the Number?\n";
        cin >> Number;
    }
    cout << "Sum = " << Sum << endl;

    return 0;
}
