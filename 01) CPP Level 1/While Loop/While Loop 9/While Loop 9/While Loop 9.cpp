#include <iostream>
using namespace std;

int main()
{
    int Number, M;
    cout << "Please,enter the Number?\n";
    cin >> Number;
    cout << "Please,enter the M?\n";
    cin >> M;

    int i = 0;
    int j = 1;
    if (M == 0)
    {
        cout << j << endl;
    }
    else
    {
        while (i != M)
        {
            j = j * Number;
            i++;
        }

        cout << j << endl;
    }

    return 0;
}
