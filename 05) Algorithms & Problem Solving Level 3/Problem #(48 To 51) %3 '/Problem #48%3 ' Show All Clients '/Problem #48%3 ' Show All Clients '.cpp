#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

// Problem #48 " Show All Clients "
const string ClientsFileName = "Clients.txt";

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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientRecord(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <stClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n__________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n__________________________________________________________________________________________________\n\n";

    for (stClient& Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n__________________________________________________________________________________________________\n";
}

int main()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintAllClientsData(vClients);

    system("pause>0");

    return 0;
}










// Problem #49 " Find Client By Account Number "
const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Please, Enter Account Number ? ";
    cin >> AccountNumber;

    return AccountNumber;
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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n\n";
    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

int main()
{
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!" << endl;
    }

    system("pause>0");

    return 0;
}










// Problem #50 " Delete Client By Account Number "
const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Please, Enter Account Number ? ";
    cin >> AccountNumber;

    return AccountNumber;
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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n\n";
    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
{
    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

vector <stClient> DeleteClientByAccountNumber(string AccountNumber, vector <stClient> vClients)
{
    vector <stClient> vClientsAfterDelete;

    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            continue;
        }

        vClientsAfterDelete.push_back(C);
    }

    return vClientsAfterDelete;
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

void SaveClientsDataToFile(string FileName, vector <stClient> vClientsAfterDelete)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out); // Write Mode

    if (MyFile.is_open())
    {
        string DataLine;
        for (stClient& C : vClientsAfterDelete)
        {
            DataLine = ConvertRecordToLine(C);

            MyFile << DataLine << endl;
        }

        MyFile.close();
    }
}

void AddClientsToFilesAfterDelete(string AccountNumber)
{
    stClient Client;
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    char Answer = 'Y';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\nAre you sure you want delete this client? N/Y? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            vector <stClient> vClientsAfterDelete = DeleteClientByAccountNumber(AccountNumber, vClients);

            SaveClientsDataToFile(ClientsFileName, vClientsAfterDelete);

            cout << "\n\nClient Deleted Successfully.\n";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!" << endl;
    }
}

int main()
{
    string AccountNumber = ReadClientAccountNumber();

    AddClientsToFilesAfterDelete(AccountNumber);

    system("pause>0");

    return 0;
}










// Problem #51 " Update Client By Account Number "
const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Please, Enter Account Number ? ";
    cin >> AccountNumber;

    return AccountNumber;
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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n\n";
    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
{
    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
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

stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter Pin Code? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;

    return Client;
}

void SaveClientsDataToFile(string FileName, vector <stClient> vClients)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out); // Write Mode

    if (MyFile.is_open())
    {
        string DataLine;
        for (stClient& C : vClients)
        {
            DataLine = ConvertRecordToLine(C);

            MyFile << DataLine << endl;
        }

        MyFile.close();
    }
}

void UpdateClientByAccountNumber(string AccountNumber)
{
    stClient Client;
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    char Answer = 'Y';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\nAre you sure you want update this client? N/Y? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            for (stClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.\n";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!" << endl;
    }
}

int main()
{
    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber);

    system("pause>0");

    return 0;
}