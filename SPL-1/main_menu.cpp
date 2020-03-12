#include<iostream>
#include"header.h"
#include<stdlib.h>
using namespace std;

void main_menu()
{

    int choice;
    cout<<"\n\t\t\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t\t     ===============\n\n"
        <<"\t\t\t\t\t\t\t1. UNGROUPED DATA\n"
        <<"\t\t\t\t\t\t\t2. GROUPED DATA\n"
        <<"\t\t\t\t\t\t\t3. UNGROUPED TO GROUPED DATA CONVERTER\n"
        <<"\t\t\t\t\t\t\t4. REGRESSION & CO-RELATION\n"
        <<"\t\t\t\t\t\t\t5. PROBABILITY DISTRIBUTION\n"
        <<"\t\t\t\t\t\t\t6. FORMULA SHEETS\n"
        <<"\t\t\t\t\t\t\t7. EXIT\n\n\n"
        <<"\t\t\t\t\t\t\tEnter your Choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1: {unGroupMenu(); break;}
        case 2: {groupMenu(); break;}
//        case 3: {unGroupToGroupMenu(); break;}
//        case 4: {regAndCorMenu(); break;}
//        case 5: {probabilityMenu(); break;}
//        case 6: {formulaSheetsMenu(); break;}
        case 7: exit(0);
        default:
        {
            system("cls||clear");
            cout<<"\n\t\t\t\t\t\t\tWRONG INPUT!!! TRY AGAIN\n";
            main_menu();
        }
    }
}
