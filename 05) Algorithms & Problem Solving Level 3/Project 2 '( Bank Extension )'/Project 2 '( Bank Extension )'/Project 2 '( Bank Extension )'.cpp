#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenue();

void ShowTransactionsMenue();

enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eExit = 7 };

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

short ReadMainMenueOption()
{
    short YourChoice = 0;

    cout << "Choose what do you want to do? [1 to 7]? ";
    cin >> YourChoice;

    return YourChoice;
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

void ShowAllClientsScreen()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n__________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n__________________________________________________________________________________________________\n\n";

    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }
    else
    {
        for (stClient& Client : vClients)
        {
            PrintClientRecord(Client);
            cout << endl;
        }
    }

    cout << "\n__________________________________________________________________________________________________\n";
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
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
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return false;
}

stClient ReadNewClient()
{
    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

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

void AddNewClients()
{
    char AddMore = 'Y';

    do
    {
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void ShowAddNewClientsScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-------------------------------------\n";

    AddNewClients();
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease, Enter AccountNumber? ";
    cin >> AccountNumber;

    return AccountNumber;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "------------------------------------\n";
    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
    cout << "------------------------------------\n";
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

void AddClientsToFilesAfterDelete(string AccountNumber, vector <stClient> vClients)
{
    stClient Client;
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
        cout << "\nClient with Account Number [" << AccountNumber << "] is Not Found!" << endl;
    }
}

void ShowDeleteClientScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    AddClientsToFilesAfterDelete(AccountNumber, vClients);
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

void UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
    stClient Client;
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
        cout << "\nClient with Account Number [" << AccountNumber << "] is Not Found!" << endl;
    }
}

void ShowUpdateClientScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    stClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number [" << AccountNumber << "] is Not Found!" << endl;
    }
}

void ShowEndScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-------------------------------------\n";
}

enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eShowMainMenue = 4 };

short ReadTransactionsMenueOption()
{
    short YourChoice = 0;

    cout << "Choose what do you want to do? [1 to 4]? ";
    cin >> YourChoice;

    return YourChoice;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <stClient>& vClients)
{
    char Answer = 'Y';

    cout << "\n\nAre you sure you want to perform this transaction? Y/N? ";
    cin >> Answer;

    if (toupper(Answer) == 'Y')
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveClientsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New Balance is: " << C.AccountBalance << endl;
                return true;
            }
        }

        return false;
    }
}

void ShowDepositScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    stClient Client;

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;

    cout << "\nPlease, Enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowWithdrawScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    stClient Client;

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;

    cout << "\nPlease, Enter withdraw amount? ";
    cin >> Amount;

    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please, Enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void PrintClientRecordBalanceLine(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n__________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n__________________________________________________________________________________________________\n\n";

    double TotalBalances = 0;

    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }
    else
    {
        for (stClient& Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
            TotalBalances += Client.AccountBalance;
        }
    }

    cout << "\n__________________________________________________________________________________________________\n\n";
    cout << "\t\t\t\t\t    Total Balances = " << TotalBalances << endl;
}

void ShowTotalBalancesScreen()
{
    ShowTotalBalances();
}

void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();
}

void PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
{
    switch (TransactionsMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;

    case enTransactionsMenueOptions::eWithdraw:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionsMenue();
        break;

    case enTransactionsMenueOptions::eShowTotalBalances:
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;

    case enTransactionsMenueOptions::eShowMainMenue:
        ShowMainMenue();
        break;
    }
}

void ShowTransactionsMenue()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "=============================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "=============================================\n";

    PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

void PerformMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eTransactions:
        system("cls");
        ShowTransactionsMenue();
        break;

    case enMainMenueOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    }
}

void ShowMainMenue()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "=============================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "=============================================\n";

    PerformMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main()
{
    ShowMainMenue();

    system("pause>0");

    return 0;
}