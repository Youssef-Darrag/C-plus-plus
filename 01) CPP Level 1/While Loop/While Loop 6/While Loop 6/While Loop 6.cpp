#include <iostream>
using namespace std;

int main()
{ 
    // Sum the odd nembers
    int Number;
    cout << "Please,enter the Number?\n";
    cin >> Number;

    int Sum = 0;
    int i = 1;
    while (i <= Number)
    {
        Sum += i;
        i = i + 2;
    }
    cout << "Sum = " << Sum << endl;

    return 0;
}
