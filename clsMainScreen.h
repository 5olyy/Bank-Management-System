#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "Global.h"



using namespace std;

class clsMainScreen :protected clsScreen
{

private:
        enum enTransactionMenuOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7,eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
        };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
       // cout << "\nClient List Screen Will be here...\n";

        clsClientsListScreen::ShowClientsListScreen();

    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";

        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";

        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
       // cout << "\nUpdate Client Screen Will be here...\n";

        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
       // cout << "\nFind Client Screen Will be here...\n";

        clsFindClientScreen::ShowFindScreen();
    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";

        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenue()
    {
        //cout << "\nUsers Menue Will be here...\n";

        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginListScreen();
    }

    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");

    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
    }

    static void _PerfromMainMenueOption(enTransactionMenuOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enTransactionMenuOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enTransactionMenuOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;

        case enTransactionMenuOptions::eExit:
            system("cls");
            _Logout();
            //Login();
      
            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Clients List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enTransactionMenuOptions)_ReadMainMenueOption());
    }

};

