#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : public clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
	
		cout << "----------------------------------\n\n";
		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.CurrencyCode() << endl;
		cout << "Name      : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)  : " << Currency.Rate() << endl;
		cout << "\n----------------------------------\n";
	}

	static string _GetCurrency(string Message)
	{
		string Code;
		cout << endl << Message;
		Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nNot Found, Please Enter another Currency Code : ";
			Code = clsInputValidate::ReadString();
			cout << endl;
		}
		return Code;
	}

	static void _PrintCalculationsResult(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		cout << "\nConvert From : \n\n";
		_PrintCurrencyCard(CurrencyFrom);
		cout << endl << Amount << " " << CurrencyFrom.CurrencyCode() << " = " <<
			CurrencyFrom.ExchangeAmountToUSD(Amount) << " " << "USD\n\n";

		if (CurrencyTo.CurrencyCode() != "USD")
		{
			cout << "Converting from USD to : \n\n";
			_PrintCurrencyCard(CurrencyTo);

			cout << endl << Amount << " " << CurrencyFrom.CurrencyCode() << " = " <<
				CurrencyFrom.Exchange(CurrencyTo, Amount) << " " << CurrencyTo.CurrencyCode();
			cout << "\n\n";
		}
	}

public:

	static void ShowCurrenciesCalculatorScreen()
	{
		_DrawScreenHeader("\tCurrency Calculator Screen");

		clsCurrency CurrencyFrom = clsCurrency::FindByCode(_GetCurrency("Please Enter Currency1 Code : "));

		clsCurrency CurrencyTo = clsCurrency::FindByCode(_GetCurrency("Please Enter Currency2 Code : "));

		cout << "\nEnter Amount to Exchange : ";
		float Amount = clsInputValidate::ReadFloatNumber();

		_PrintCalculationsResult(CurrencyFrom, CurrencyTo, Amount);

		cout << "Do you perform another calculation ? ";
		char C = 'n';
		cin >> C;

		if (C == 'Y' || C == 'y')
		{
			system("cls");
			ShowCurrenciesCalculatorScreen();
		}
	}
};

