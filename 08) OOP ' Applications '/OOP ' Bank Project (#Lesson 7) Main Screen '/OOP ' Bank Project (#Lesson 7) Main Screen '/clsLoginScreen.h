#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;
        string UserName, Password;

        do
        {
            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvalid Username/Password!";
                cout << "\nYou have " << (3 - FaildLoginCount) << " Trial(s) to login.\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\nYour are locked after 3 faild trails.\n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> UserName;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t     Login Screen");
        return _Login();
    }
};

