#pragma once
#include "clsString.h"
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientsListScreen : public clsScreen
{
private:

	static void _PrintClientRecordLine(clsBankClient Client)
	{
		
		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(18) << Client.AccountNumber()
			<< "| " << setw(18) << Client.FullName()
			<< "| " << setw(14) << Client.Phone
			<< "| " << setw(20) << Client.Email
			<< "| " << setw(10) << Client.PinCode
			<< "| " << setw(15) << Client.AccountBalance;
		
	}

public:

	static void ShowClientsListScreen()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pListClients))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t  Clients List Screen";
		string SubTitle = "\t    " + to_string(vClients.size()) + " Client(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t ____________________________________________________________________________________________________\n\n";
		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(18) << "Account Number"
			<< "| " << setw(18) << "Client Name"
			<< "| " << setw(14) << "Phone"
			<< "| " << setw(20) << "Email"
			<< "| " << setw(10) << "PIN Code"
			<< "| " << setw(15) << "Balance";
		cout << "\n\t ____________________________________________________________________________________________________\n\n";
		
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}


		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		cout << "\n\n";
    }

};

