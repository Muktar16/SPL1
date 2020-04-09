
#include"header.h"

#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
void AltEnter()

{

    keybd_event(VK_MENU,0x38,0,0);

    keybd_event(VK_RETURN,0x1c,0,0);

    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);

    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);

}

int main( void )
{
    AltEnter();
    //SetConsoleTitle("\n\n\n\nWELCOME TO STATISTICAL CALCULATOR");
    cout<<"\n\n";
    cout<<"\t\t\t\t\t\t================================================\n";
    cout<<"\t\t\t\t\t\t\tWELCOME TO STATISTICAL CALCULATOR\n";
    cout<<"\t\t\t\t\t\t================================================\n\n\n";

    while(1)
    {
        main_menu();
    }

  return 0;
}



