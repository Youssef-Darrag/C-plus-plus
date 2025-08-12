#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Problem #41 " Reverse Words in String "
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

string ReverseWordsInString(string S1)
{
    vector <string> vString;
    string S2 = "";

    vString = SplitString(S1, " ");

    vector <string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        S2 += *iter + " ";
    }

    S2.substr(0, S2.length() - 1); // remove last space

    return S2;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after reversing words:\n";
    cout << ReverseWordsInString(S1) << endl;

    system("pause>0");
}










// Problem #42 " Replace Word in String "
string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
        pos = S1.find(StringToReplace);
    }

    return S1;
}

int main()
{
    string S1 = "Welcome to Jordan, Jordan is a nice country";
    string StringToReplace = "Jordan";
    string ReplaceTo = "USA";

    cout << "\nOrigial String\n" << S1;
    cout << "\n\nString After Replace:\n";
    cout << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo) << endl;

    system("pause>0");
}










// Problem #43 " Replace Words ( Custom ) "
vector <string> SplitString(string S1, string Delim)
{
    vector <string> vString;

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

string LowerAllString(string Word)
{
    for (short i = 0; i < Word.length(); i++)
    {
        Word[i] = tolower(Word[i]);
    }

    return Word;
}

string JoinString(vector <string> vString, string Delim)
{
    string S1;

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{
    vector <string> vString = SplitString(S1, " ");

    for (string& s : vString)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = ReplaceTo;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = ReplaceTo;
            }
        }
    }

    return JoinString(vString, " ");
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "jordan";
    string ReplaceTo = "USA";

    cout << "\nOrigial String\n" << S1 << endl;
    cout << "\nReplace with match case:\n";
    cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo) << endl;
    cout << "\nReplace with don't match case:\n";
    cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false) << endl;

    system("pause>0");
}










// Problem #44 " Remove Punctuations "
string RemovePunctuationsFromString(string S1)
{
    string S2 = "";

    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }

    return S2;
}

int main()
{
    string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing";

    cout << "\nOrigial String\n" << S1 << endl;
    cout << "\nPunctuations Removed:\n";
    cout << RemovePunctuationsFromString(S1) << endl;

    system("pause>0");
}










// Problem #45 " Convert Record to Line "
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient ReadNewClient()
{
    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);


    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    
    return stClientRecord;
}

int main()
{
    cout << "\nPlease, Enter Client Data:\n\n";

    stClient Client;
    Client = ReadNewClient();

    cout << "\n\nClient Record for Saving is:\n";
    cout << ConvertRecordToLine(Client) << endl;

    system("pause>0");

}










// Problem #46 " Convert Line Data to Record "
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector <string> SplitString(string S1, string Delim)
{
    vector <string> vString;

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

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector <string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

void PrintClientRecord(stClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

int main()
{
    string stLine = "A150#//#1234#//#Youssef Fawzy Darrag#//#001002135#//#5270.000000";

    cout << "\nLine Record is:\n";
    cout << stLine << endl;

    stClient Client = ConvertLineToRecord(stLine);

    PrintClientRecord(Client);

    system("pause>0");

    return 0;
}










// Problem #47 " Add Clients to File "

#include <fstream>

const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient ReadNewClient()
{
    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);


    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client;

    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls");

        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

int main()
{
    AddClients();

    system("pause>0");

    return 0;
}