#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsTransferScreen : public clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		string AccNum;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		cin >> AccNum;

		while (!clsBankClient::isClientExist(AccNum))
		{
			cout << "Client With [" << AccNum << "] Does Not Exist, Please Enter Another Client Account Number: ";
			cin >> AccNum;
		}
		return AccNum;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount : ";
		double Amount = 0;
		cin >> Amount;

		while (!SourceClient.isWithdrawalValid(Amount))
		{
			cout << "\nAmount Exceeds the availale balance, Enter another amount : ";
			cin >> Amount;
		}
		return Amount;
	}

public:
	
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(DestinationClient);

		
		double Amount = _ReadAmount(SourceClient);
		

		cout << "\nAre you sure you want to perform this transaction? ";
		char Check = 'n';
		cin >> Check;

		if (Check == 'Y' || Check == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{

				cout << "\nTransfer done successfully.\n\n";

			}
			else
				cout << "Erorr";
		}
		else
		{
			cout << "The Transaction has been Cancelled\n";
		}

		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);
	}
};

