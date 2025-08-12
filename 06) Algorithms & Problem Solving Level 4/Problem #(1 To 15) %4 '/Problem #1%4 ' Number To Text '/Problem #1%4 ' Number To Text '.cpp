#include <iostream>
using namespace std;

// Problem #1 " Number to Text "
int ReadNumber()
{
    int Number = 0;

    cout << "Please, Enter a Number? ";
    cin >> Number;

    return Number;
}

string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }

    if (Number >= 1 && Number <= 19)
    {
        string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
        "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        return "one Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }
}

int main()
{
    int Number = ReadNumber();

    cout << NumberToText(Number) << endl;

    system("pause>0");

    return 0;
}










// Problem #2 " Leap Year "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year to check? ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    // leap year if perfectly divisible by 400
    if (Year % 400 == 0)
    {
        return true;
    }
    // not a leap year if divisible by 100, but not divisible by 400
    else if (Year % 100 == 0)
    {
        return false;
    }
    // leap year if not divisible by 100, but divisible by 4
    else if (Year % 4 == 0)
    {
        return true;
    }
    // all other years are not leap years
    else
    {
        return false;
    }
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";

    system("pause>0");

    return 0;
}










// Problem #3 " Leap Year (One Line Of Code) "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year to check? ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";

    system("pause>0");

    return 0;
}










// Problem #4 " Number of Days-Hours-Minutes-Seconds In a Year "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year to check? ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}

int main()
{
    short Year = ReadYear();

    cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year);

    system("pause>0");

    return 0;
}










// Problem #5 " Number of Days-Hours-Minutes-Seconds In a Month "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year to check? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nPlease, Enter a month to check? ";
    cin >> Month;

    return Month;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    if (Month == 2)
    {
        return IsLeapYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };

    for (short i = 0; i < 7; i++)
    {
        if (arr31Days[i] == Month)
            return 31;
    }

    return 30;
}

short NumberOfHoursInAMonth(short Month, short Year)
{
    return NumberOfDaysInAMonth(Month, Year) * 24;
}

int NumberOfMinutesInAMonth(short Month, short Year)
{
    return NumberOfHoursInAMonth(Month, Year) * 60;
}

int NumberOfSecondsInAMonth(short Month, short Year)
{
    return NumberOfMinutesInAMonth(Month, Year) * 60;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);
    cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInAMonth(Month, Year);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Month, Year);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Month, Year);

    system("pause>0");

    return 0;
}










// Problem #6 " Number of Days In a Month (Short Logic) "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year to check? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nPlease, Enter a month to check? ";
    cin >> Month;

    return Month;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    
    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);

    system("pause>0");

    return 0;
}










// Problem #7 " Day Name "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nPlease, Enter a month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a day? ";
    cin >> Day;

    return Day;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\nDate       :" << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order  : " << DayOfWeekOrder(Day, Month, Year);
    cout << "\nDay Name   : " << DayShortName(DayOfWeekOrder(Day, Month, Year));

    system("pause>0");

    return 0;
}










// Problem #8 " Month Calendar "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nPlease, Enter a month? ";
    cin >> Month;

    return Month;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder];
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return Months[MonthNumber - 1];
}

void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;

    int Current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < Current; i++)
        printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }

    printf("\n  _________________________________\n");
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    PrintMonthCalendar(Month, Year);

    system("pause>0");

    return 0;
}










// Problem #9 " Year Calendar "
short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year? ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder];
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return Months[MonthNumber - 1];
}

void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;

    int Current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < Current; i++)
        printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }

    printf("\n  _________________________________\n");
}

void PrintYearCalendar(short Year)
{
    printf("\n  _________________________________\n");
    printf("\n            Calendar - %d\n", Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
        PrintMonthCalendar(i, Year);
}

int main()
{   
    PrintYearCalendar(ReadYear());

    system("pause>0");

    return 0;
}










// Problem #10 " Days from the beginning of Year "
short ReadYear()
{
    short Year = 0;

    cout << "\nPlease, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nPlease, Enter a month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a day? ";
    cin >> Day;

    return Day;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\nNumber of Days from the beginning of the year is " << NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year) << endl;

    system("pause>0");

    return 0;
}










// Problem #11 " Date from Day Order In a Year "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year = 0;

    cout << "\nPlease, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nPlease, Enter a month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a day? ";
    cin >> Day;

    return Day;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

stDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
{
    stDate Date;
    short RemainingDays = DayOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
        
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short DaysOrderInYear = NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year);

    cout << "\nNumber of Days from the beginning of the year is " << DaysOrderInYear << endl << endl;

    stDate Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
    cout << "Date for [" << DaysOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    system("pause>0");

    return 0;
}










// Problem #12 " Add Days to Date "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year = 0;

    cout << "\nPlease, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nPlease, Enter a month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a day? ";
    cin >> Day;

    return Day;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

short ReadDaysToAdd()
{
    short Days = 0;

    cout << "\nHow many days to add? ";
    cin >> Days;

    return Days;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

stDate DateAddDays(short Days, stDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;

    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

int main()
{
    stDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = DateAddDays(Days, Date);
    cout << "\nDate after adding [" << Days << "] days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    system("pause>0");

    return 0;
}










// Problem #13 " Date1 Less Than Date2 "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "Please, Enter a month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a day? ";
    cin >> Day;

    return Day;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (IsDate1BeforeDate2(Date1, Date2))
        cout << "\nYes, Date1 is less than Date2.\n";
    else
        cout << "\nNo, Date1 is NOT less than Date2.\n";
  
    system("pause>0");

    return 0;
}










// Problem #14 " Date1 Equals to Date2 "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "Please, Enter a month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a day? ";
    cin >> Day;

    return Day;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\nYes, Date1 is equal to Date2.\n";
    else
        cout << "\nNo, Date1 is NOT equal to Date2.\n";

    system("pause>0");

    return 0;
}










// Problem #15 " Last Day, Last Month "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "Please, Enter a month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a day? ";
    cin >> Day;

    return Day;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

int main()
{
    stDate Date1 = ReadFullDate();

    if (IsLastDayInMonth(Date1))
        cout << "\nYes, Day is Last Day in Month.";
    else
        cout << "\nNo, Day is NOT Last Day in Month.";

    if (IsLastMonthInYear(Date1.Month))
        cout << "\nYes, Month is Last Month in Year.";
    else
        cout << "\nNo, Month is NOT Last Month in Year.";

    system("pause>0");

    return 0;
}