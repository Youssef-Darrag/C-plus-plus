#include <iostream>
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yellow = 4 };

int main()
{
    cout << "**********************************************\n";
    cout << "Please chose the number of your color?\n";
    cout << "(1) Red\n";
    cout << "(2) Blue\n";
    cout << "(3) Green\n";
    cout << "(4) Yellow\n";
    cout << "**********************************************\n\n";
    cout << "Your choice?  ";

    int R;
    enScreenColor Color;

    cin >> R;
    Color = enScreenColor(R);

    if (Color == enScreenColor::Red)
    {
        system("color 4F");
    }
    else if (Color == enScreenColor::Blue)
    {
        system("color 1F");
    }
    else if (Color == enScreenColor::Green)
    {
        system("color 2F");
    }
    else if (Color == enScreenColor::Yellow)
    {
        system("color 6F");
    }
    else
    {
        system("color 7F");
    };

    return 0;
}