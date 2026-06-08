#include <iostream>
#include "clsLoginScreen.h"


int main()

{
    while(true)
    {
        clsLoginScreen::ShowLoginScreen();

        if (NumofTrails == 0)
        {
            break;
        }
    }


    system("pause>0");
    return 0;
}