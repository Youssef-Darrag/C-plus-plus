#include <iostream>
using namespace std;

int main()
{
    int Mark = 90;

    (Mark >= 50) ? cout << "PASS" : cout << "FAIL";

    return 0;
}


// Homework 1 
int main()
{
    int Number = 1;
    string Result;

    Result = (Number > 0) ? "Positive" : "Negative";

    cout << "Number is " << Result << endl;

    return 0;
}


// Homework 2
int main()
{
    int Number = 0;
    string Result;

    Result = (Number == 0) ? "Zero" : (Number > 0) ? "Positive" : "Negative";

    cout << "Number is " << Result << endl;

    return 0;
}