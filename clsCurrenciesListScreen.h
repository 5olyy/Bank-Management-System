#pragma once
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"

class clsCurrenciesListScreen : public clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Record)
	{

		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(30) << Record.Country()
			<< "| " << setw(8)  << Record.CurrencyCode()
			<< "| " << setw(35) << Record.CurrencyName()
			<< "| " << setw(15) << Record.Rate();
	}

public:

	static void ShowCurrenciesListScreen()
	{

		vector <clsCurrency> vData = clsCurrency::GetCurrenciesList();

		string Title = "     Currency List Screen";
		string SubTitle = "\t    " + to_string(vData.size()) + " Record(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t ____________________________________________________________________________________________________\n\n";
		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(30) << "Country"
			<< "| " << setw(8) << "Code"
			<< "| " << setw(35) << "Name"
			<< "| " << setw(15) << "Rate/(1$)";
		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		if (vData.size() == 0)
			cout << "\t\t\t\tNo Records Available In the System!";
		else
		{
			for (clsCurrency Record : vData)
			{
				_PrintCurrencyRecordLine(Record);
				cout << endl;
			}
		}


		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		cout << "\n\n";
	}

};

