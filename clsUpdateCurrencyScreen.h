#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen : public clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card : \n";
		cout << "----------------------------------\n";
		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.CurrencyCode() << endl;
		cout << "Name      : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)  : " << Currency.Rate() << endl;
		cout << "----------------------------------\n";
	}

	static string _GetCurrency()
	{
		string Code;
		cout << "\nPlease Enter Currency Code : ";
		Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "Not Found, Please Enter another Currency Code : ";
			Code = clsInputValidate::ReadString();
			cout << endl;
		}
		return Code;
	}

	static float _ReadRate()
	{
		cout << "Enter New Rate: ";
		float NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen");

		string Code = _GetCurrency();

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you want to update this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "_____________________\n\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully\n";

			_PrintCurrencyCard(Currency);
		}
	}
};

