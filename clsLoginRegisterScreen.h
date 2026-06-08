#pragma once
#include "clsBankClient.h"

class clsLoginRegisterScreen : public clsScreen
{
private:

	static void _PrintLoginRecordLine(clsUser::stLoginRecord Record)
	{

		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(40) << Record.DateTime
			<< "| " << setw(22) << Record.UserName
			<< "| " << setw(15) << Record.Password
			<< "| " << setw(15) << Record.Permissions;

	}

public:

	static void ShowLoginListScreen()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRecord> vData = clsUser::GetLoginsList();

		string Title = "     Login Register List Screen";
		string SubTitle = "\t    " + to_string(vData.size()) + " Record(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t ____________________________________________________________________________________________________\n\n";
		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(40) << "Date - Time"
			<< "| " << setw(22) << "UserName"
			<< "| " << setw(15) << "Password"
			<< "| " << setw(15) << "Permissions";
		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		if (vData.size() == 0)
			cout << "\t\t\t\tNo Records Available In the System!";
		else

			for (clsUser::stLoginRecord Record : vData)
			{

				_PrintLoginRecordLine(Record);
				cout << endl;
			}


		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		cout << "\n\n";
	}

};

