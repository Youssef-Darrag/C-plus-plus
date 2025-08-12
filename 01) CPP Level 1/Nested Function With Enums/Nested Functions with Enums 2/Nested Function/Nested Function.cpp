#include <iostream> 
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yellow = 4 };

void ShowScreenColorMenue()
{
    cout << "*****************************************\n";
    cout << "Please,enter the number of The color?\n";
    cout << "(1) Red\n";
    cout << "(2) Blue\n";
    cout << "(3) Green\n";
    cout << "(4) Yellow\n";
    cout << "*****************************************\n\n";
    cout << "Your choice?  ";
}

enScreenColor ReadScreenColor()
{
    int R;
    enScreenColor Color;

    cin >> R;
    return enScreenColor(R);
}

int GetScreenColor(enScreenColor Color)
{
    switch (Color)
    {
    case enScreenColor::Red:
        return system("color 4F");
        break;
    case enScreenColor::Blue:
        return system("color 1F");
        break;
    case enScreenColor::Green:
        return system("color 2F");
        break;
    case enScreenColor::Yellow:
        return system("color 6F");
        break;
    default:
        return system("color 7F");
    }
}

int main()
{
    ShowScreenColorMenue();

    cout << "My Fav Color is " << GetScreenColor(ReadScreenColor()) << endl;
}