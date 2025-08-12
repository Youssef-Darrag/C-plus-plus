#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAcc.Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumberFrom()
	{
		string AccountNumber = "";

		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static string _ReadAccountNumberTo()
	{
		string AccountNumber = "";

		cout << "\nPlease Enter Account Number to Transfer To: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount = 0;

		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount: ";
			Amount = clsInputValidate::ReadFloatNumber();
		}

		return Amount;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumberFrom());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumberTo());

		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done Successfully.\n";
			}
			else
			{
				cout << "\nTransfer Faild.\n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

