#include <iostream>
using namespace std;

// Problem #16 " Increase Date By One Day "
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

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int main()
{
    stDate Date1 = ReadFullDate();

    Date1 = IncreaseDateByOneDay(Date1);

    cout << "\nDate after adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    system("pause>0");

    return 0;
}










// Problem #17 " Diff In Days "
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    cout << "\nDifference is: " << GetDifferenceInDays(Date1, Date2) << " Day(s).";

    cout << "\nDifference (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

    system("pause>0");

    return 0;
}










// Problem #18 " Your Age In Days "

#pragma warning(disable : 4996)

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

stDate GetSystemDate()
{
    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}

int main()
{
    cout << "\nPlease, Enter Your Date of Birth:\n";
    stDate Date1 = ReadFullDate();

    stDate Date2 = GetSystemDate();

    cout << "\nYour Age is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

    system("pause>0");

    return 0;
}










// Problem #19 " Diff In Days (Negative Days) "
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate;

    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;

    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    cout << "\nDifference is: " << GetDifferenceInDays(Date1, Date2) << " Day(s).";

    cout << "\nDifference (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

    system("pause>0");

    return 0;
}










// Problem #20-32 " Increase Date Problems "
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

    int Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

stDate IncreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year += Years;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    return Date;
}

stDate IncreaseDateByXDecades(short Decades, stDate Date)
{
    for (short i = 1; i <= Decades; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decades, stDate Date)
{
    Date.Year += (Decades * 10);
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    stDate Date1 = ReadFullDate();

    cout << "\nDate After:\n\n";

    Date1 = IncreaseDateByOneDay(Date1);
    cout << "01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXDays(10, Date1);
    cout << "02-Adding 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneWeek(Date1);
    cout << "03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXWeeks(10, Date1);
    cout << "04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneMonth(Date1);
    cout << "05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXMonths(5, Date1);
    cout << "06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneYear(Date1);
    cout << "07-Adding one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXYears(10, Date1);
    cout << "08-Adding 10 years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXYearsFaster(10, Date1);
    cout << "09-Adding 10 years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "10-Adding one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXDecades(10, Date1);
    cout << "11-Adding 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXDecadesFaster(10, Date1);
    cout << "12-Adding 10 Decades (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "13-Adding one Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "14-Adding one Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    system("pause>0");

    return 0;
}










// Problem #33-46 " Decrease Date Problems "
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

    int Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year -= Years;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecades(short Decades, stDate Date)
{
    for (short i = 1; i <= Decades; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decades, stDate Date)
{
    Date.Year -= (Decades * 10);
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    stDate Date1 = ReadFullDate();

    cout << "\nDate After:\n\n";

    Date1 = DecreaseDateByOneDay(Date1);
    cout << "01-Subtracting one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByXDays(10, Date1);
    cout << "02-Subtracting 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByOneWeek(Date1);
    cout << "03-Subtracting one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByXWeeks(10, Date1);
    cout << "04-Subtracting 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByOneMonth(Date1);
    cout << "05-Subtracting one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByXMonths(5, Date1);
    cout << "06-Subtracting 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByOneYear(Date1);
    cout << "07-Subtracting one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByXYears(10, Date1);
    cout << "08-Subtracting 10 years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByXYearsFaster(10, Date1);
    cout << "09-Subtracting 10 years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByOneDecade(Date1);
    cout << "10-Subtracting one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByXDecades(10, Date1);
    cout << "11-Subtracting 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByXDecadesFaster(10, Date1);
    cout << "12-Subtracting 10 Decades (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByOneCentury(Date1);
    cout << "13-Subtracting one Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByOneMillennium(Date1);
    cout << "14-Subtracting one Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    system("pause>0");

    return 0;
}