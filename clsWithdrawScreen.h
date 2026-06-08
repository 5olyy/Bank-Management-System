#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsWithdrawScreen : clsScreen
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

    static void ShowDepositeScreen()
    {
        _DrawScreenHeader("\t   Whithdraw Screen");

        string AccountNumber;

        cout << "Please Enter Client Account Number\n";
        cin >> AccountNumber;

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "Client With [" << AccountNumber << "] Does Not Exist, Please Enter Another Client Account Number\n";
            cin >> AccountNumber;
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClientCard(Client1);

        double Amount = 0;

        cout << "\nPlease Enter Withdrawal Amount? ";
        cin >> Amount;

        cout << "\nAre you sure you want to perform this transaction? ";
        char Check = 'n';
        cin >> Check;

        if (Check == 'Y' || Check == 'y')
        {
            if (Client1.Withdraw(Amount))
            { 
                cout << "\nThe Amount has been withdrawn successfully\n";

                cout << "\nNew Balance is " << Client1.AccountBalance << endl;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;

            }
        }
        else
        {
            cout << "The Transaction has been Cancelled\n";
        }
    }

};

