#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "Global.h"

using namespace std;



class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double  _AccountBalance;
	bool   _MarkForDelete = false;

	struct stTransferRecord;

	static clsBankClient _ConvertLineToCUserObject(string Line, string Separetor = "#//#")
	{
		vector <string> vClients = clsString::Split(Line, Separetor);

		return clsBankClient(enMode::UpdateMode, vClients[0], vClients[1], vClients[2],
			vClients[3], vClients[4], vClients[5], stoi(vClients[6]));
	}

	static string _ConvertUserObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static  vector <clsBankClient> _LoadUserDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineToCUserObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if (!C.MarkForDelete)
				{
					DataLine = _ConvertUserObjectToLine(C);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsBankClient> vClients;
		vClients = _LoadUserDataFromFile();


		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}
		_SaveCleintsDataToFile(vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareTransferLog(double TransferAmount, clsBankClient DestinationClient, string Seperator = "#//#")
	{
		string DataLine = "";

		DataLine = clsDate::GetTodayDateTime() + Seperator;
		DataLine += AccountNumber() + Seperator;
		DataLine += DestinationClient.AccountNumber() + Seperator;
		DataLine += to_string(TransferAmount) + Seperator;
		DataLine += to_string(AccountBalance) + Seperator;
		DataLine += to_string(DestinationClient.AccountBalance) + Seperator;
		DataLine += CurrentUser.UserName;
		return DataLine;
	}

	void _RegisterTransferLog(double TransferAmount, clsBankClient DestinationClient)
	{
		fstream File;
		File.open("TransferLog.txt", ios::out | ios::app);

		string DataLine;

		DataLine = _PrepareTransferLog(TransferAmount, DestinationClient);


		if (File.is_open())
		{

			File << DataLine << endl;

			File.close();

		}
	}

	static stTransferRecord _ConvertTransferLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferRecord Record;
		vector <string> vRecord = clsString::Split(Line,Seperator);
		
		Record.DateTime = vRecord[0];
		Record.SourceAcc = vRecord[1];
		Record.DestinationAcc = vRecord[2];
		Record.Amount = stoi(vRecord[3]);
		Record.SourceBal = vRecord[4];
		Record.DestinationBal = vRecord[5];
		Record.User = vRecord[6];
		return Record;
	}

	static vector <stTransferRecord> _LoadTransferDataFromFile()
	{
		vector <stTransferRecord> vRecords;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				stTransferRecord record = _ConvertTransferLineToRecord(Line);

				vRecords.push_back(record);
			}

			MyFile.close();

		}

		return vRecords;
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string AccNum, string PinCode, float AccBal)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccNum;
		_PinCode = PinCode;
		_AccountBalance = AccBal;
	}

	struct stTransferRecord
	{
		string DateTime;
		string SourceAcc;
		string DestinationAcc;
		double Amount;
		string SourceBal;
		string DestinationBal;
		string User;
	};

	bool isEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void SetMarkForDelete(bool MarkForDelete)
	{
		_MarkForDelete = MarkForDelete;
	}

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;


	// this method in the UI add screen
	// 
	// void Print()
	//{
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << FirstName;
	//	cout << "\nLastName    : " << LastName;
	//	cout << "\nFull Name   : " << FullName();
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nAcc. Number : " << _AccountNumber;
	//	cout << "\nPassword    : " << _PinCode;
	//	cout << "\nBalance     : " << _AccountBalance;
	//	cout << "\n___________________\n";

	//}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCUserObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCUserObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool isClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return !Client.isEmpty();
	}

	enum enSaveResults { svSucceeded = 1, svFaildEmptyObject = 2, svFaildAccountNumberExists = 3 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:

			_Update();

			return enSaveResults::svSucceeded;

		case enMode::AddNewMode:
			//This will add new record to file or database
			if (clsBankClient::isClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadUserDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;
			}
		}
		_SaveCleintsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadUserDataFromFile();
	}

	static float GetTotalBalances()
	{
		vector <clsBankClient> vClints = _LoadUserDataFromFile();

		float TotalBalances = 0;
		for (clsBankClient& C : vClints)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}

    void Deposite(double Amount)
	{
		 AccountBalance += Amount;
		 Save();
	}

	bool Withdraw(double Amount)
	{
		if (!isWithdrawalValid(Amount))
			return false;

		AccountBalance -= Amount;
		Save();
		return true;
	}

	bool isWithdrawalValid(double Amount)
	{
		return Amount <= AccountBalance;
	}

	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{
		if (!isWithdrawalValid(Amount))
			return false;

		Withdraw(Amount);
		DestinationClient.Deposite(Amount);

		_RegisterTransferLog(Amount,DestinationClient);

		return true;
	}

	void TransferLog(clsBankClient DestinationClient)
	{
		fstream File;
		File.open("TransferLog.txt", ios::out | ios::app);

		string DataLine;

		//DataLine = _PrepareLoginRecord();


		if (File.is_open())
		{

			File << DataLine << endl;

			File.close();

		}
	}

	static vector<stTransferRecord> GetTransfersList()
	{
		return _LoadTransferDataFromFile();
	}
};

