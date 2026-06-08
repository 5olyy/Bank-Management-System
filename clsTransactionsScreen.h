#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransfersLogScreen.h"

class clsTransactionsScreen : clsScreen
{

private:

    enum enTransactionMenuOptions {
        eDeposite = 1, eWithdraw = 2, eTotalBalances = 3,
        eTransfer = 4, etransferLog = 5, eMainMenu = 6
    };

    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToCurrenciesMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _ShowDepositeScreen()
    {
        //cout << "\n\n\t\t Deposite Screen Will be here...\n\n\n";

        clsDepositeScreen::ShowDepositeScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n\n\t\t Withdraw Screen Will be here...\n\n\n";

        clsWithdrawScreen::ShowDepositeScreen();
    }

    static void _ShowTotalBalanceScreen()
    {
        //cout << "\n\n\t\t TotalBalance Screen Will be here...\n\n\n";

        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        //cout << "Transfer Screen Will be Here...\n";

        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransfersLogScreen::ShowTransfersLogScreen();
    }

    static void _PerfromTransactionMenueOption(enTransactionMenuOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionMenuOptions::eDeposite:
        {
            system("cls");
            _ShowDepositeScreen();
            _GoBackToCurrenciesMenue();
            break;
        }
        case enTransactionMenuOptions::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enTransactionMenuOptions::eTotalBalances:
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enTransactionMenuOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enTransactionMenuOptions::etransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enTransactionMenuOptions::eMainMenu:
           
            break;

        }

    }

public:

    static void ShowTransactionsMenu()
    {

        if (!CheckAccessRight(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionMenueOption(enTransactionMenuOptions(_ReadTransactionMenueOption()));
    }

};

