#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"


using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "",bool isLoginScreen = false)
    {
        clsDate _Date = clsDate::GetSystemDate();
        string TodayDate = clsDate::DateToString(_Date);

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        if (!isLoginScreen)
        {
            cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << "\n";
            cout << "\n\t\t\t\t\tDate : " << TodayDate << "\n\n";
        }

    }

    static bool CheckAccessRight(clsUser::enPermissions Permissions)
    {
        if (!CurrentUser.CheckAccessPoint(Permissions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";

            return false;
        }
        else
        {
            return true;
        }
    }

};

