#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>

class clsTransfersLogScreen : public clsScreen
{
private:

	static void _PrintTransferRecordLine(clsBankClient::stTransferRecord Record)
	{

		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(22) << Record.DateTime
			<< "| " << setw(8) << Record.SourceAcc
			<< "| " << setw(8) << Record.DestinationAcc
			<< "| " << setw(10) << Record.Amount
			<< "| " << setw(14) << Record.SourceBal
			<< "| " << setw(14) << Record.DestinationBal
			<< "| " << setw(15) << Record.User;
	}


public:

	static void ShowTransfersLogScreen()
	{
		vector <clsBankClient::stTransferRecord> vData = clsBankClient::GetTransfersList();


		string Title = "     Transfers Log List Screen";
		string SubTitle = "\t    " + to_string(vData.size()) + " Record(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t ____________________________________________________________________________________________________\n\n";
		cout << left;
		cout << setw(9) << left << ""
			<< "| " << setw(22) << "Date/Time"
			<< "| " << setw(8)  << "S.Acc"
			<< "| " << setw(8)  << "D.Acc"
			<< "| " << setw(10) << "Amount"
			<< "| " << setw(14) << "S.Balance"
			<< "| " << setw(14) << "D.Balance"
			<< "| " << setw(15) << "User";
		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		if (vData.size() == 0)
			cout << "\t\t\t\tNo Records Available In the System!";
		else

			for (clsBankClient::stTransferRecord Record : vData)
			{

				_PrintTransferRecordLine(Record);
				cout << endl;
			}


		cout << "\n\t ____________________________________________________________________________________________________\n\n";

		cout << "\n\n";
	}
};

