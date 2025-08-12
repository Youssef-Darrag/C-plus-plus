#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLogout = 8 };

enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eShowMainMenue = 4 };

enum enManageUsersMenueOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6 };

enum enMainMenuePermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64 };

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

struct stUser
{
    string UserName;
    string Password;
    int Permissions;
};

stUser CurrentUser;

void ShowMainMenue();

void ShowTransactionsMenue();

void ShowManageUsersMenue();

bool CheckAccessPermission(enMainMenuePermissions Permission);

void Login();

short ReadMainMenueOption()
{
    short YourChoice = 0;

    cout << "Choose what do you want to do? [1 to 8]? ";
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

stUser ConvertUserLineToRecord(string Line, string Seperator = "#//#")
{
    stUser User;
    vector <string> vUserData;

    vUserData = SplitString(Line, Seperator);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);

    return User;
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

string ConvertUserRecordToLine(stUser User, string Seperator = "#//#")
{
    string stUserRecord = "";

    stUserRecord += User.UserName + Seperator;
    stUserRecord += User.Password + Seperator;
    stUserRecord += to_string(User.Permissions);

    return stUserRecord;
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

vector <stUser> LoadUsersDataFromFile(string FileName)
{
    vector <stUser> vUsers;
    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertUserLineToRecord(Line);

            vUsers.push_back(User);
        }

        MyFile.close();
    }

    return vUsers;
}

void PrintClientRecord(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintUserRecordLine(stUser User)
{
    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(10) << left << User.Password;
    cout << "| " << setw(40) << left << User.Permissions;
}

void ShowAccessDeniedMessage()
{
    cout << "\n-----------------------------------------------\n";
    cout << "Access Denied, \nYou don't have Permission to do this, \nPlease connect your Admin.";
    cout << "\n-----------------------------------------------\n";
}

void ShowAllClientsScreen()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

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

void ShowAllUsersScreen()
{
    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n__________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n__________________________________________________________________________________________________\n\n";

    if (vUsers.size() == 0)
    {
        cout << "\t\t\t\tNo Users Available In the System!";
    }
    else
    {
        for (stUser& User : vUsers)
        {
            PrintUserRecordLine(User);
            cout << endl;
        }
    }

    cout << "\n__________________________________________________________________________________________________\n";
}

void ShowListUsersScreen()
{
    ShowAllUsersScreen();
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

bool UserExistsByUserName(string Username, string FileName)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertUserLineToRecord(Line);
            if (User.UserName == Username)
            {
                MyFile.close();
                return true;
            }
        }

        MyFile.close();
    }

    return false;
}

int ReadPermissionsToSet()
{
    int Permissions = 0;
    char Answer = 'n';

    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
        return -1;

    cout << "\nDo you want to give access to : \n";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pListClients;
    }

    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pUpdateClient;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pTransactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pManageUsers;
    }

    return Permissions;
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

stUser ReadNewUser()
{
    stUser User;

    cout << "Enter Username? ";
    getline(cin >> ws, User.UserName);

    while (UserExistsByUserName(User.UserName, UsersFileName))
    {
        cout << "\nUser with [" << User.UserName << "] already exists, Enter another Username? ";
        getline(cin >> ws, User.UserName);
    }

    cout << "Enter Password? ";
    getline(cin, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
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

void AddNewUser()
{
    stUser User;

    User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));
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

void AddNewUsers()
{
    char AddMore = 'Y';

    do
    {
        cout << "Adding New User:\n\n";

        AddNewUser();
        cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void ShowAddNewClientsScreen()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-------------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-------------------------------------\n";

    AddNewClients();
}

void ShowAddNewUsersScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tAdd New Users Screen";
    cout << "\n-------------------------------------\n";

    AddNewUsers();
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease, Enter AccountNumber? ";
    cin >> AccountNumber;

    return AccountNumber;
}

string ReadUserName()
{
    string Username = "";

    cout << "\nPlease, Enter Username? ";
    cin >> Username;

    return Username;
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

void PrintUserCard(stUser User)
{
    cout << "\nThe following are the user details:\n";
    cout << "------------------------------------\n";
    cout << "User Name   : " << User.UserName << endl;
    cout << "Password    : " << User.Password << endl;
    cout << "Permissions : " << User.Permissions << endl;
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

bool FindUserByUserName(string Username, vector <stUser> vUsers, stUser& User)
{
    for (stUser& U : vUsers)
    {
        if (U.UserName == Username)
        {
            User = U;
            return true;
        }
    }

    return false;
}

bool FindUserByUsernameAndPassword(string Username, string Password, stUser& User)
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    for (stUser& U : vUsers)
    {
        if (U.UserName == Username && U.Password == Password)
        {
            User = U;
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

vector <stUser> DeleteUserByUserName(string Username, vector <stUser> vUsers)
{
    vector <stUser> vUsersAfterDelete;

    for (stUser& U : vUsers)
    {
        if (U.UserName == Username)
        {
            continue;
        }

        vUsersAfterDelete.push_back(U);
    }

    return vUsersAfterDelete;
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

void SaveUsersDataToFile(string FileName, vector <stUser> vUsersAfterDelete)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out); // Write Mode

    if (MyFile.is_open())
    {
        string DataLine;
        for (stUser& U : vUsersAfterDelete)
        {
            DataLine = ConvertUserRecordToLine(U);

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

bool AddUsersToFilesAfterDelete(string Username, vector <stUser> vUsers)
{
    if (Username == "Admin")
    {
        cout << "\n\nYou cannot Delete This User.";
        return false;
    }
    stUser User;
    char Answer = 'Y';

    if (FindUserByUserName(Username,vUsers,User))
    {
        PrintUserCard(User);

        cout << "\nAre you sure you want delete this user? N/Y? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            vector <stUser> vUsersAfterDelete = DeleteUserByUserName(Username, vUsers);

            SaveUsersDataToFile(UsersFileName, vUsersAfterDelete);

            cout << "\n\nUser Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nUser with Username [" << Username << "] is Not Found!" << endl;
        return false;
    }
}

void ShowDeleteClientScreen()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-------------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    AddClientsToFilesAfterDelete(AccountNumber, vClients);
}

void ShowDeleteUserScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tDelete Users Screen";
    cout << "\n-------------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadUserName();

    AddUsersToFilesAfterDelete(Username, vUsers);
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

stUser ChangeUserRecord(string Username)
{
    stUser User;

    User.UserName = Username;

    cout << "\n\nEnter Password? ";
    getline(cin >> ws, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
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

void UpdateUserByUserName(string Username, vector <stUser>& vUsers)
{
    stUser User;
    char Answer = 'Y';

    if (FindUserByUserName(Username, vUsers, User))
    {
        PrintUserCard(User);

        cout << "\nAre you sure you want update this User? N/Y? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            for (stUser& U : vUsers)
            {
                if (U.UserName == Username)
                {
                    U = ChangeUserRecord(Username);
                    break;
                }
            }

            SaveUsersDataToFile(UsersFileName, vUsers);

            cout << "\n\nUser Updated Successfully.\n";
        }
    }
    else
    {
        cout << "\nUser with Username [" << Username << "] is Not Found!" << endl;
    }
}

void ShowUpdateClientScreen()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-------------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateUserScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tUpdate User Info Screen";
    cout << "\n-------------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadUserName();

    UpdateUserByUserName(Username, vUsers);
}

void ShowFindClientScreen()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pFindClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

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

void ShowFindUserScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-------------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadUserName();
    stUser User;

    if (FindUserByUserName(Username, vUsers, User))
    {
        PrintUserCard(User);
    }
    else
    {
        cout << "\nUser with Username [" << Username << "] is Not Found!" << endl;
    }
}

void ShowEndScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-------------------------------------\n";
}

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

bool CheckAccessPermission(enMainMenuePermissions Permission)
{
    if (CurrentUser.Permissions == enMainMenuePermissions::eAll)
        return true;

    if ((Permission & CurrentUser.Permissions) == Permission)
        return true;
    else
        return false;
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();
}

void GoBackToManageUsersMenue()
{
    cout << "\n\nPress any key to go back to Manage Users Menue...";
    system("pause>0");
    ShowManageUsersMenue();
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
    if (!CheckAccessPermission(enMainMenuePermissions::pTransactions))
    {
        ShowAccessDeniedMessage();
        GoBackToMainMenue();
        return;
    }

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

short ReadManageUsersMenueOption()
{
    short YourChoice = 0;

    cout << "Choose what do you want to do? [1 to 6]? ";
    cin >> YourChoice;

    return YourChoice;
}

void PerformManageUsersMenueOPtion(enManageUsersMenueOptions ManageUsersMenueOption)
{
    switch (ManageUsersMenueOption)
    {
    case enManageUsersMenueOptions::eListUsers:
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersMenue();
        break;

    case enManageUsersMenueOptions::eAddNewUser:
        system("cls");
        ShowAddNewUsersScreen();
        GoBackToManageUsersMenue();
        break;

    case enManageUsersMenueOptions::eDeleteUser:
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersMenue();
        break;

    case enManageUsersMenueOptions::eUpdateUser:
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersMenue();
        break;

    case enManageUsersMenueOptions::eFindUser:
        system("cls");
        ShowFindUserScreen();
        GoBackToManageUsersMenue();
        break;

    case enManageUsersMenueOptions::eMainMenue:
        ShowMainMenue();
        break;
    }
}

void ShowManageUsersMenue()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
    {
        ShowAccessDeniedMessage();
        GoBackToMainMenue();
        return;
    }

    system("cls");
    cout << "=============================================\n";
    cout << "\tManage Users Menue Screen\n";
    cout << "=============================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "=============================================\n";

    PerformManageUsersMenueOPtion((enManageUsersMenueOptions)ReadManageUsersMenueOption());
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

    case enMainMenueOptions::eManageUsers:
        system("cls");
        ShowManageUsersMenue();
        break;

    case enMainMenueOptions::eLogout:
        Login();
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
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout\n";
    cout << "=============================================\n";

    PerformMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

bool LoadUserInfo(string Username, string Password)
{
    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
        return true;
    else
        return false;
}

void Login()
{
    bool LoginFaild = false;
    string UserName, Password;

    do
    {
        system("cls");
        cout << "\n--------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n--------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invalid Username/Password!\n";
        }

        cout << "Enter Username? ";
        cin >> UserName;

        cout << "Enter Password? ";
        cin >> Password;

        LoginFaild = !LoadUserInfo(UserName, Password);

    } while (LoginFaild);

    ShowMainMenue();
}

int main()
{
    Login();

    system("pause>0");

    return 0;
}