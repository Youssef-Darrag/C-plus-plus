#include <iostream>
using namespace std;

// Problem #61 " Count Overlap Days "
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

short ReadDay()
{
    short Day = 0;
    
    cout << "\nPlease, Enter a Day? ";
    cin >> Day;

    return Day;
}

short ReadMonth()
{
    short Month = 0;

    cout << "Please, Enter a Month? ";
    cin >> Month;

    return Month;
}

short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a Year? ";
    cin >> Year;

    return Year;
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

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
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

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
    return !(
        CompareDates(Date, Period.StartDate) == enDateCompare::Before
        ||
        CompareDates(Date, Period.EndDate) == enDateCompare::After
        );
}

int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (IsDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++;

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverlapDays;
}

int main()
{
    cout << "Enter Period 1 :";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2 :";
    stPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Days Count is: " << CountOverlapDays(Period1, Period2);

    system("pause>0");

    return 0;
}










// Problem #62 " Validate Date "
struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadDay()
{
    short Day = 0;

    cout << "\nPlease, Enter a Day? ";
    cin >> Day;

    return Day;
}

short ReadMonth()
{
    short Month = 0;

    cout << "Please, Enter a Month? ";
    cin >> Month;

    return Month;
}

short ReadYear()
{
    short Year = 0;

    cout << "Please, Enter a Year? ";
    cin >> Year;

    return Year;
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

bool IsValidDate(stDate Date)
{
    if (Date.Day < 1 || Date.Day > 31)
        return false;

    if (Date.Month < 1 || Date.Month > 12)
        return false;

   /* if (Date.Month == 2)
    {
        if (IsLeapYear(Date.Year))
        {
            if (Date.Day > 29)
                return false;
        }
        else
        {
            if (Date.Day > 28)
                return false;
        }
    }*/

    // this is faster
    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > DaysInMonth)
        return false;

    return true;
}

int main()
{
    stDate Date = ReadFullDate();

    if (IsValidDate(Date))
        cout << "\nYes, Date is a valide date.\n";
    else
        cout << "\nNo, Date is a NOT valide date.\n";

    system("pause>0");

    return 0;
}










// Problem #63/64 " Read/Print Date String "
#include <string>
#include <vector>

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string ReadStringDate(string Message)
{
    string DateString = "";

    cout << Message;
    getline(cin >> ws, DateString);

    return DateString;
}

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;

    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stDate StringToDate(string DateString)
{
    stDate Date;
    vector<string> vDate;

    vDate = SplitString(DateString, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
    string DateString = ReadStringDate("\nPlease, Enter Date dd/mm/yyyy? ");

    stDate Date = StringToDate(DateString);

    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;

    cout << "\nYou Entered: " << DateToString(Date) << endl;

    system("pause>0");

    return 0;
}










// Problem #65 " FormatDate "
// #include <string>
// #include <vector>

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string ReadStringDate(string Message)
{
    string DateString = "";

    cout << Message;
    getline(cin >> ws, DateString);

    return DateString;
}

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;

    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stDate StringToDate(string DateString)
{
    stDate Date;
    vector<string> vDate;

    vDate = SplitString(DateString, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);

        pos = S1.find(StringToReplace);
    }

    return S1;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";

    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

int main()
{
    string DateString = ReadStringDate("\nPlease, Enter Date dd/mm/yyyy? ");

    stDate Date = StringToDate(DateString);

    cout << "\n" << FormateDate(Date) << "\n";
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");

    return 0;
}