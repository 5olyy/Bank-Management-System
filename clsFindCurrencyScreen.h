#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : public clsScreen
{
private:

	enum enChoice {
		eCode = 1,
		eCountry = 2
	};

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card : \n";
		cout << "----------------------------------\n";
		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.CurrencyCode() << endl;
		cout << "Name      : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)  : " << Currency.Rate() << endl;
		cout << "----------------------------------\n\n";
	}

	static short _ReadChoice()
	{
		cout << "\n\nFind by: [1] Code or [2] Country ? ";

		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Invalid!, Enter Another Choice ? ");

		return Choice;
	}

	static string _GetCurrency()
	{
		string Code;
		cout << "\nPlease Enter Currency Code : ";
		Code = clsInputValidate::ReadString();
		return Code;
	}

	static string _ReadCountryName()
	{
		string Country;
		cout << "\nPlease Enter Country Name : ";
		Country = clsInputValidate::ReadString();
		return Country;
	}

	static clsCurrency _FindbyCode()
	{
		string Code = _GetCurrency();

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "Not Found, Please Enter another Currency Code : ";
			Code = clsInputValidate::ReadString();
			cout << endl;
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		return Currency;
	}

	static clsCurrency _FindbyCountry()
	{
		string Country = _ReadCountryName();
		clsCurrency Currency = clsCurrency::FindByCountry(Country);

		while (Currency.IsEmpty())
		{
			cout << "Not Found, Please Enter another Country Name : ";
			Country = clsInputValidate::ReadString();
		    Currency = clsCurrency::FindByCountry(Country);
			cout << endl;
		}
		return Currency;
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		clsCurrency Currency = clsCurrency::GetEmptyCurrencyObject();

		short Choice = _ReadChoice();

		if (Choice == enChoice::eCode) 
		{
			Currency = _FindbyCode();
		}
		if (Choice == enChoice::eCountry)
		{
			Currency = _FindbyCountry();
		}

		cout << "\nCurrency Found :)\n";

		_PrintCurrencyCard(Currency);
	}
};

