#include <iostream>
#include <string>
using namespace std;

string ReadName()
{
    string Name;
    cout << "Please,enter your Name?" << endl;
    getline(cin, Name);

    return Name;
}

void PrintName(string Name)
{
    cout << "\n Your Name is: " << Name << endl;
}

int main()
{
    string Name;

    PrintName(ReadName());
    
    return 0;
}
