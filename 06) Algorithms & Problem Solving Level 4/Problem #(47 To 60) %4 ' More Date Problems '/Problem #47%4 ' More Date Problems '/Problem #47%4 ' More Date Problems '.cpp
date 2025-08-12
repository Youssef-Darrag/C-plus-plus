#include <iostream>
using namespace std;

// Problem #47-53 " More Date Problems "

#pragma warning(disable : 4996)

struct stDate
{
    short Year;
    short Month;
    short Day;
};

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

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date1)
{
    stDate EndOfMonthDate;

    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
    EndOfMonthDate.Month = Date1.Month;
    EndOfMonthDate.Year = Date1.Year;

    return GetDifferenceInDays(Date1, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date1)
{
    stDate EndOfYearDate;

    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date1.Year;

    return GetDifferenceInDays(Date1, EndOfYearDate, true);
}

int main()
{
    stDate Date1 = GetSystemDate();

    cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1)) << " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    cout << "\nIs it End of Week?\n";
    if (IsEndOfWeek(Date1))
        cout << "Yes, it is Saturday, it's of Week.";
    else
        cout << "No, it's Not end of Week.";

    cout << "\n\nIs it Weekend?\n";
    if (IsWeekEnd(Date1))
        cout << "Yes, it is a weekend.";
    else
        cout << "No, today is " << DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";

    cout << "\n\nIs it Business Day?\n";
    if (IsBusinessDay(Date1))
        cout << "Yes, it is a business day.";
    else
        cout << "No, it is Not a business day.";

    cout << "\n\nDays until end of week : " << DaysUntilTheEndOfWeek(Date1) << " Day(s).";

    cout << "\nDays until end of month : " << DaysUntilTheEndOfMonth(Date1) << " Day(s).";

    cout << "\nDays until end of year : " << DaysUntilTheEndOfYear(Date1) << " Day(s).";

    system("pause>0");

    return 0;
}










// Problem #54 " Calculate Vacation Days "
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder];
}

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DaysCount++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DaysCount;
}

int main()
{
    cout << "\nVacation Starts: ";
    stDate DateFrom = ReadFullDate();

    cout << "\nVacation Ends: ";
    stDate DateTo = ReadFullDate();

    cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(DateFrom)) << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;
    cout << "Vacation To: " << DayShortName(DayOfWeekOrder(DateTo)) << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

    cout << "\n\nActucal Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo);

    system("pause>0");

    return 0;
}










// Problem #55 " Calculate Vacation Return Date "
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

short ReadVacationDays()
{
    short VacationDays = 0;

    cout << "\n\nPlease, Enter Vacation Days? ";
    cin >> VacationDays;

    return VacationDays;
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder];
}

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}

stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
    short WeekEndCounter = 0;
    
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
    {
        if (IsWeekEnd(DateFrom))
            WeekEndCounter++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DateFrom;
}

int main()
{
    cout << "\nVacation Starts: ";
    stDate DateFrom = ReadFullDate();

    short VacationDays = ReadVacationDays();

    stDate ReturnDate = CalculateVacationReturnDate(DateFrom, VacationDays);

    cout << "\n\nReturn Date: " << DayShortName(DayOfWeekOrder(ReturnDate)) << " , " << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;

    system("pause>0");

    return 0;
}










// Problem #56 " Is Date1 After Date2 "
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

int main()
{
    cout << "Enter Date1:";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter Date2:";
    stDate Date2 = ReadFullDate();

    if (IsDate1AfterDate2(Date1, Date2))
        cout << "\n\nYes, Date1 is After Date2.";
    else
        cout << "\n\nNo, Date1 is NOT After Date2.";

    system("pause>0");

    return 0;
}










// Problem #57 " Compare Date Function "
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    /*if (IsDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;*/

    // this is faster
    return enDateCompare::After;
}

int main()
{
    cout << "Enter Date1:";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter Date2:";
    stDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << CompareDates(Date1, Date2) << endl;

    system("pause>0");

    return 0;
}










// Problem #58 " Is Overlap Periods "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    /*if (IsDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;*/

        // this is faster
    return enDateCompare::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before 
        ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
        )
        return false;
    else
        return true;
}

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

int main()
{
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();

    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods do not Overlap\n";

    system("pause>0");

    return 0;
}










// Problem #59 " Period Length In Days "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
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

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

int main()
{
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nPeriod Length is: " << PeriodLengthInDays(Period1);
    cout << "\nPeriod Length (Including End Day) is: " << PeriodLengthInDays(Period1, true);

    system("pause>0");

    return 0;
}










// Problem #60 " Is Date Within Period "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    /*if (IsDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;*/

        // this is faster
    return enDateCompare::After;
}

bool IsDateInPeriod(stPeriod Period, stDate Date)
{
    return !(
        CompareDates(Date, Period.StartDate) == enDateCompare::Before
        ||
        CompareDates(Date, Period.EndDate) == enDateCompare::After
        );
}

int main()
{
    cout << "\nEnter Period:";
    stPeriod Period = ReadPeriod();

    cout << "\nEnter Date to check:\n";
    stDate Date = ReadFullDate();

    if (IsDateInPeriod(Period, Date))
        cout << "\nYes, Date is within period.\n";
    else
        cout << "\nNo, Date is NOT within period.\n";

    system("pause>0");

    return 0;
}