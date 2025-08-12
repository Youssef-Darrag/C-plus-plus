#include <iostream>
using namespace std;

// Problem #21 " Fibonacci Series "
void PrintFibonacciUsingLoop(short Number)
{
    int FebNumber = 0;
    int Prev1 = 1, Prev2 = 0;

    cout << "1     ";
    for (short i = 2; i <= Number; i++)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << "     ";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main()
{
    PrintFibonacciUsingLoop(10);

    system("pause>0");
}










// Problem #22 " Fibonacci Series With Recursion "
void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
{
    int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << "      ";
        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    PrintFibonacciUsingRecursion(10, 0, 1);

    system("pause>0");
}










// Problem #23 " Print First Letter of Each Word "

#include <string>

string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

void PrintFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;

    cout << "\nFirst letters of this string:\n";
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            cout << S1[i] << endl;
        }

        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }
}

int main()
{
    PrintFirstLetterOfEachWord(ReadString());

    system("pause>0");
}










// Problem #24 " Upper First Letter of Each Word "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

string UpperFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }

        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();
    
    cout << "\nString after conversion:\n";

    S1 = UpperFirstLetterOfEachWord(S1);
    cout << S1 << endl;
    
    system("pause>0");
}










// Problem #25 " Lower First Letter of Each Word "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

string LowerFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }

        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after conversion:\n";

    S1 = LowerFirstLetterOfEachWord(S1);
    cout << S1 << endl;

    system("pause>0");
}










// Problem #26 " Upper/Lower All Letters of a String "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

string UpperAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
            S1[i] = toupper(S1[i]);
    }

    return S1;
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
            S1[i] = tolower(S1[i]);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after Upper:\n";
    S1 = UpperAllString(S1);
    cout << S1 << endl;

    cout << "\nString after Lower:\n";
    S1 = LowerAllString(S1);
    cout << S1 << endl;

    system("pause>0");
}










// Problem #27 " Invert Character Case "
char ReadChar()
{
    char Ch1;

    cout << "Please, Enter a Character?\n";
    cin >> Ch1;

    return Ch1;
}

char InvertLetterCase(char Ch1)
{
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

int main()
{
    char Ch1 = ReadChar();

    cout << "\nChar after inverting case:\n";
    Ch1 = InvertLetterCase(Ch1);
    cout << Ch1 << endl;

    system("pause>0");
}










// Problem #28 " Invert All Letters Case "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

char InvertLetterCase(char Ch1)
{
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

string InvertAllStringLettersCase(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertLetterCase(S1[i]);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after Inverting All Letters Case:\n";
    S1 = InvertAllStringLettersCase(S1);
    cout << S1 << endl;

    system("pause>0");
}










// Problem #29 " Count Small/Capital Letters "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

short CountCapitalLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }

    return Counter;
}

short CountSmallLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString Length = " << S1.length() << endl;
    cout << "Capital Letters Count = " << CountCapitalLetters(S1) << endl;
    cout << "Small Letters Count = " << CountSmallLetters(S1) << endl;

    system("pause>0");
}










// Problem #30 " Count Letters "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

char ReadChar()
{
    char Ch1;

    cout << "\nPlease, Enter a Character?\n";
    cin >> Ch1;

    return Ch1;
}

short CountLetter(string S1, char Letter)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Letter)
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1) << endl;

    system("pause>0");
}










// Problem #31 " Count Letters ( Match Case ) "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

char ReadChar()
{
    char Ch1;

    cout << "\nPlease, Enter a Character?\n";
    cin >> Ch1;

    return Ch1;
}

char InvertLetterCase(char Ch1)
{
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

short shCountLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\nLetter \'" << Ch1 << "\' Count = " << shCountLetter(S1, Ch1) << endl;
    cout << "Letter \'" << Ch1 << "\' Or \'" << InvertLetterCase(Ch1) << "\' Count = " << shCountLetter(S1, Ch1, false) << endl;

    system("pause>0");
}










// Problem #32 " Is Vowel? (حروف متحركة (أحرف العلة"
char ReadChar()
{
    char Ch1;

    cout << "\nPlease, Enter a Character?\n";
    cin >> Ch1;

    return Ch1;
}

bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);

    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

int main()
{
    char Ch1 = ReadChar();

    if (IsVowel(Ch1))
        cout << "\nYes, Letter \'" << Ch1 << "\' is vowel.\n";
    else
        cout << "\nNo, letter \'" << Ch1 << "\' is NOT vowel.\n";

    system("pause>0");
}










// Problem #33 " Count Vowels "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);

    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

short CountVowels(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << "\nNumber of vowels is: " << CountVowels(S1) << endl;

    system("pause>0");
}










// Problem #34 " Print All Vowels in String "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);

    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

void PrintVowels(string S1)
{
    cout << "\nVowels in string are: ";
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            cout << S1[i] << "      ";
    }
}

int main()
{
    string S1 = ReadString();

    PrintVowels(S1);

    system("pause>0");
}










// Problem #35 " Print Each Word in String "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

void PrintEachWordInString(string S1)
{
    string delim = " "; // delimiter

    cout << "\nYour string words are:\n\n";
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos) // std::string::npos = S1.npos
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << sWord << endl;
        }

        S1.erase(0, pos + delim.length()); // erase() until position and move to next word.
    }
    if (S1 != "")
    {
        cout << S1 << endl; // it print last word of the string.
    }
}

int main()
{
    string S1 = ReadString();

    PrintEachWordInString(S1);

    system("pause>0"); 
}










// Problem #36 " Count Each Words in String "
// #include <string>
string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

short CountWords(string S1)
{
    string delim = " "; // delimiter
    short Counter = 0;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos) // std::string::npos = S1.npos
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            Counter++;
        }

        S1.erase(0, pos + delim.length()); // erase() until position and move to next word.
    }
    if (S1 != "")
    {
        Counter++; // it print last word of the string.
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << "\nThe number of words in your string is: " << CountWords(S1) << endl;

    system("pause>0");
}










// Problem #37 " Split String "
// #include <string>

#include <vector>

string ReadString()
{
    string S1;

    cout << "Please, Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

vector <string> SplitString(string S1, string Delim)
{
    vector <string> vString;

    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) // std::string::npos = S1.npos
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length()); // erase() until position and move to next word.
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it print last word of the string.
    }

    return vString;
}

int main()
{
    vector <string> vString;

    vString = SplitString(ReadString(), " ");

    cout << "Tokens = " << vString.size() << endl;

    for (string& s : vString)
    {
        cout << s << endl;
    }

    system("pause>0");
}










// Problem #38 " TrimLeft, TrimRight, Trim "
string TrimLeft(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
    return "";
}

string TrimRight(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}

string Trim(string S1)
{
    return TrimLeft(TrimRight(S1));
}

int main()
{
    string S1 = "     Youssef Fawzy Darrag     ";

    cout << "\nString     = " << S1 << endl << endl;
    cout << "Trim Left  = " << TrimLeft(S1) << endl;
    cout << "Trim Right = " << TrimRight(S1) << endl;
    cout << "Trim       = " << Trim(S1) << endl;

    system("pause>0");
}










// Problem #39 " Join String "
// #include <vector>
string JoinString(vector <string> vString, string Delim)
{
    string S1;

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
    vector <string> vString = { "Mohammed" , "Fadi" , "Ali" , "Maher" };

    cout << "Vector after join:\n";
    cout << JoinString(vString, " ") << endl;

    system("pause>0");
}










// Problem #40 " Join String ( Overloading ) "
// #include <vector>
string JoinString(vector <string> vString, string Delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arrString[], short Length, string Delim)
{
    string S1 = "";

    for (short i = 0; i < Length; i++)
    {
        S1 = S1 + arrString[i] + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
    vector <string> vString = { "Mohammed" , "Fadi" , "Ali" , "Maher" };
    string arrString[] = { "Mohammed" , "Fadi" , "Ali" , "Maher" };

    cout << "\nVector after join:\n";
    cout << JoinString(vString, " ") << endl;

    cout << "\nArray after join:\n";
    cout << JoinString(arrString, 4, " ") << endl;

    system("pause>0");
}