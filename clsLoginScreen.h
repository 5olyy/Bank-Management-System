#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen : public clsScreen
{
private:

	static void _Login()
	{
		bool LoginFaild = false;

		string username, password;


		do
		{
			if (LoginFaild)
			{
				cout << "\nInvalid Username/Password! ";
				cout << "\nYou have " << NumofTrails << " Trail(s) to Login. \n\n";
			}

			cout << "Enter Username ? ";
			cin >> username;
			cout << "Enter Password ? ";
			cin >> password;

			CurrentUser = clsUser::Find(username, password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild && --NumofTrails);

		if (NumofTrails)
		{
			NumofTrails = 3;
			CurrentUser.LoginRegister();
			clsMainScreen::ShowMainMenue();
		}
		else
		{
			cout << "\nYou are locked after 3 faild trails.\n\n";
			
		}
	}


public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen", "",true);
		_Login();
		
	}

};

