#include <iostream>
using namespace std;

int main()
{
    // Sum the even numbers 
    int Number;
    cout << "Please,enter the number?\n";
    cin >> Number;

    int Sum = 0;
    int i = 2;
    while (i <= Number)
    {
        Sum += i;
        i = i + 2;
    }
    cout << "Sum = " << Sum << endl;

    return 0;
}