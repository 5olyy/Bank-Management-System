#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsFindClientScreen : clsScreen
{
private:


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

    static void ShowFindScreen()
    {

        if (!CheckAccessRight(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\t Find Client Screen");

        string AccountNumber;

        cout << "Please Enter Client Account Number\n";
        cin >> AccountNumber;

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "Not Found, Please Enter Another Client Account Number\n";
            cin >> AccountNumber;
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
       
        if(!Client1.isEmpty())
        {
            cout << "\nClient Found -:)\n\n";
        }
        else
        {
            cout << "\nClient was not found\n";
        }
        
        _PrintClientCard(Client1);
     
    }

};

