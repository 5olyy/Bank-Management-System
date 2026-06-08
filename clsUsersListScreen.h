#pragma once
#include "clsString.h"
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsUsersListScreen : public clsScreen
{
private:

	static void _PrintUserRecordLine(clsUser User)
	{

		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(18) << User.UserName
			<< "| " << setw(18) << User.FullName()
			<< "| " << setw(14) << User.Phone
			<< "| " << setw(20) << User.Email
			<< "| " << setw(10) << User.Password
			<< "| " << setw(15) << User.Permissions;

	}

public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t  Users List Screen";
		string SubTitle = "\t    " + to_string(vUsers.size()) + " User(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t ____________________________________________________________________________________________________\n\n";
		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(18) << "UserName"
			<< "| " << setw(18) << "Full Name"
			<< "| " << setw(14) << "Phone"
			<< "| " << setw(20) << "Email"
			<< "| " << setw(10) << "Password"
			<< "| " << setw(15) << "Permissions";
		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsUser User : vUsers)
			{

				_PrintUserRecordLine(User);
				cout << endl;
			}


		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		cout << "\n\n";
	}

};


