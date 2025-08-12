#include <iostream>
using namespace std;

int main()
{
    float Grade[3];

    cout << "Please,enter Grade1?\n";
    cin >> Grade[0];
    cout << "Please,enter Grade2?\n";
    cin >> Grade[1];
    cout << "Please,enter Grade3?\n";
    cin >> Grade[2];
    cout << "******************************\n";

    float Average = (Grade[0] + Grade[1] + Grade[2]) / 3;
    cout << "The average of grade is : " << Average << endl;
  

}

