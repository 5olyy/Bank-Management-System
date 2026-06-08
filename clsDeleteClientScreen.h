#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsDeleteClientScreen : clsScreen
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

    static void ShowDeleteClientScreen()
    {

        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\t Delete Client Screen");

        string AccountNumber;

        cout << "Please Enter Client Account Number\n";
        cin >> AccountNumber;

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "Not Found, Please Enter Another Client Account Number\n";
            cin >> AccountNumber;
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClientCard(Client1);

        cout << "\nAre you sure you want to delete this Client ? ";
        char check = 'n';
        cin >> check;

        if (check == 'y' || check == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient was Deleted Successfully\n\n";
                _PrintClientCard(Client1);
            }
            else
            {
                cout << "\nErorr, Client was not Deleted\n";
            }
        }

    }

};

