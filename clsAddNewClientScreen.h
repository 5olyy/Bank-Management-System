#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsAddNewClientScreen : public  clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

     static void _PrintClientCard(clsBankClient Client)
    {
    	cout << "\nClient Card:";
    	cout << "\n___________________";
    	cout << "\nFirstName   : " << Client.FirstName;
    	cout << "\nLastName    : " << Client.LastName;
    	cout << "\nFull Name   : " << Client.FullName();
    	cout << "\nEmail       : " << Client.Email;
    	cout << "\nPhone       : " << Client.Phone;
    	cout << "\nAcc. Number : " << Client.AccountNumber();
    	cout << "\nPassword    : " << Client.PinCode;
    	cout << "\nBalance     : " << Client.AccountBalance;
    	cout << "\n___________________\n";

    }

public:

	static void ShowAddNewClientScreen()
	{

        if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }

        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber;

        cout << "Please Enter Account Number\n";
        cin >> AccountNumber;

        while (clsBankClient::isClientExist(AccountNumber))
        {
            cout << "Already Used!, Please Enter Another Account Number\n";
            cin >> AccountNumber;
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClientCard(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }

	}

};

