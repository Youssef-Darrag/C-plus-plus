#include <iostream>
using namespace std;

int main()
{
    int Number;
    cout << "Please,enter the number?\n";
    cin >> Number;

    int i = 1;
    while (i <= Number)
    {
        cout << i << endl;
        i++;
    }

    return 0;
}
