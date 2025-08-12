#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

float HoursToDays(float NumberOfHours)
{
    return NumberOfHours / 24;
}

float HoursToWeeks(float NumberOfHours)
{
    return NumberOfHours / (24 * 7);
}

int main()
{
    float NumberOfHours = ReadPositiveNumber("Please,Enter Number Of Hours?");
    float NumberOfDays = HoursToDays(NumberOfHours);
    float NumberOfWeeks = HoursToWeeks(NumberOfHours);

    cout << endl;
    cout << "Total Hours = " << NumberOfHours << endl;
    cout << "Total Days = " << NumberOfDays << endl;
    cout << "Total Weeks = " << NumberOfWeeks << endl;

    return 0;
}