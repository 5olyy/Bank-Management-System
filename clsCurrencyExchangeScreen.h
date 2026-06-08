#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyExchangeScreen : public clsScreen
{
private:

    enum enCurrencyMenuOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalc = 4,
        eMainMenu = 5
    };

    static short _ReadCurrenciesMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToCurrenciesMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeMenu();
    }

    static void _ShowCurrenciesListScreen()
    {
        //cout << "Currencies List Will be Here....\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
       // cout << "Find Currency Screen Will be Here....\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "Update Rate Screen Will be Here....\n";
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }

    static void _ShowCurrenciesCalculatorScreen()
    {
        //cout << "Currencies Claculator Will be Here....\n";
        clsCurrencyCalculatorScreen::ShowCurrenciesCalculatorScreen();
    }


    static void _PerfromTransactionMenueOption(enCurrencyMenuOptions CurrencyMenueOption)
    {
        switch (CurrencyMenueOption)
        {
        case enCurrencyMenuOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
            break;
        }
        case enCurrencyMenuOptions::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enCurrencyMenuOptions::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enCurrencyMenuOptions::eCurrencyCalc:
            system("cls");
            _ShowCurrenciesCalculatorScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enCurrencyMenuOptions::eMainMenu:

            break;

        }

    }


public:

	static void ShowCurrencyExchangeMenu()
	{

        if (!CheckAccessRight(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionMenueOption(enCurrencyMenuOptions(_ReadCurrenciesMenueOption()));
	}
};

