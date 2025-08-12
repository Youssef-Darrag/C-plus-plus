#include <iostream>
using namespace std;

enum enWeekDay { Sun = 1, Mon = 2, Thus = 3, Wednes = 4, Thurs = 5, Fri = 6, Satur = 7 };

void ShowWeekDayMenue()
{
    cout << "***************************\n";
    cout << "         Week Days         \n";
    cout << "***************************\n";
    cout << "(1) Sunday" << endl;
    cout << "(2) Monday" << endl;
    cout << "(3) Thusday" << endl;
    cout << "(4) Wednesday" << endl;
    cout << "(5) Thursday" << endl;
    cout << "(6) Friday" << endl;
    cout << "(7) Saturday" << endl;
    cout << "***************************\n";
    cout << "Please,enter the number of the day?" << endl;
}

enWeekDay ReadWeekDay()
{
    int Day;
    enWeekDay WeekDay;
    
    cin >> Day;
    return enWeekDay(Day);
}

string GetWeekDayName(enWeekDay WeekDay)
{
    switch (WeekDay)
    {
    case enWeekDay::Sun:
        return "Sunday";
        break;
    case enWeekDay::Mon:
        return "Monday";
        break;
    case enWeekDay::Thus:
        return "Thusday";
        break;
    case enWeekDay::Wednes:
        return "Wednesday";
        break;
    case enWeekDay::Thurs:
        return "Thursday";
        break;
    case enWeekDay::Fri:
        return "Friday";
        break;
    case enWeekDay::Satur:
        return "Saturday";
        break;
    default: 
        return "Not a week day!\n";
    }
}

int main()
{
    ShowWeekDayMenue();

    cout << "Today is " << GetWeekDayName(ReadWeekDay()) << endl;

    return 0;
}
