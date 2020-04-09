#include"header.h"
void formulaSheetsMenu()
{
    while(1)
    {
        system("cls||clear");
        int choice;
        printf("\n\n\n\n\n\n");
        cout<<"\n\t\t\t\t\t\t\t\tFORMULA SHEETS MENU\n\t\t\t\t\t\t\t==============================\n\n"
            <<"\t\t\t\t\t\t\t1. UNGROUPED DATA\n"
            <<"\t\t\t\t\t\t\t2. GROUPED DATA\n"
            <<"\t\t\t\t\t\t\t3. REGRESSION & CO-RELATION\n"
            <<"\t\t\t\t\t\t\t4. PROBABILITY DISTRIBUTION\n"
            <<"\t\t\t\t\t\t\t5. ALL FORMULA SHEETS\n"
            <<"\t\t\t\t\t\t\t6. BACK TO MAIN MENU\n"
            <<"\t\t\t\t\t\t\t7. EXIT\n\n\n"
            <<"\t\t\t\t\t\t\tEnter your Choice: ";
        cin>>choice;
        getchar();

        switch(choice)
        {
            case 1:
            {

                system("cls||clear");
                read_file("formula_sheet_1.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            case 2:
            {
                system("cls||clear");
                read_file("formula_sheet_2.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            case 3:
            {
                system("cls||clear");
                read_file("formula_sheet_3.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            case 4:
            {
                system("cls||clear");
                read_file("formula_sheet_4.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }

            case 5:
            {
                system("cls||clear");
                read_file("formula_sheet_1.txt");
                printf("\n\n\n\n\n\n");
                read_file("formula_sheet_2.txt");
                printf("\n\n\n\n\n\n");
                read_file("formula_sheet_3.txt");
                printf("\n\n\n\n\n\n");
                read_file("formula_sheet_4.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            case 6:
            {
                system("cls||clear");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n";
                return;
            }
    //        case 7: exit(0);
            default:
            {
                system("cls||clear");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"\n\t\t\t\t\t\t\tWRONG INPUT!!! YOU HAVE TO SELECT A NUMBER BETWEEN 1-7. \n";
                cout<<"\n\n\t\t\t\t\t\t\tPress Any key to try again...............";
                _getch();
                system("cls||clear");
            }
        }
    }
}
