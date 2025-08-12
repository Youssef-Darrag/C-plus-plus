#include <iostream>
using namespace std;

string ReadPassword()
{
    string Password;
    cout << "Please,enter a 3-Letter Password (All Capital)?" << endl;
    cin >> Password;

    return Password;
}

bool GuessPassword(string OriginalPassword)
{
    int Counter = 0; string Word = "";
    cout << endl;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int x = 65; x <= 90; x++)
            {
                Counter++;
                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(x);
                cout << " Trial [" << Counter << "]: " << Word << endl;

                if (Word == OriginalPassword)
                {
                    cout << "\n Password is " << Word << endl;
                    cout << " Found after " << Counter << " Trial(s)" << endl;
                    return true;
                }
                Word = "";
            }
        }
    }
    return false;
}

int main()
{
    GuessPassword(ReadPassword());

    return 0;
}