#include"header.h"

void probabilityMenu()
{
   while(1)
   {
        system("cls||clear");
        int choice;
        printf("\n\n\n\n\n\n\n\n\n\n");
        cout<<"\n\t\t\t\t\t\t\t\tPROBABILITY MENU\n\t\t\t\t\t\t\t  ========================\n\n"
            <<"\t\t\t\t\t\t\t1. BINOMIAL DISTRIBUTION\n"
            <<"\t\t\t\t\t\t\t2. POISSION DISTRIBUTION(P given)\n"
            <<"\t\t\t\t\t\t\t3. POISSION DISTRIBUTION(u given)\n"
            <<"\t\t\t\t\t\t\t4. GEOMETRIC DISTRIBUTION\n"
            <<"\t\t\t\t\t\t\t5. NEGATIVE BINOMIAL DISTRIBUTION\n"
            <<"\t\t\t\t\t\t\t6. Hyper-GEOMETRIC DISTRIBUTION\n"
            <<"\t\t\t\t\t\t\t7. BACK TO MAIN MENU\n"
            <<"\t\t\t\t\t\t\t8. EXIT\n\n\n"
            <<"\t\t\t\t\t\t\tEnter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: {bio_dis(); break;}
            case 2: {pois_dis_p_given(); break;}
    //        case 3: {pois_disU(); break;}
    //        case 4: {geo_dis(); break;}
    //        case 5: {neg_bio_dis(); break;}
            case 6: {Hyper_geo_dis(); break;}
            case 7: {system("cls||clear"); return;}
            case 8: exit(0);
            default:
            {

                system("cls||clear");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"\n\t\t\t\t\t\t\tWRONG INPUT!!! YOU HAVE TO SELECT A NUMBER BETWEEN 1-7. \n";
                cout<<"\n\n\t\t\t\t\t\t\tPress Any key to try again...............";
                _getch();
                system("cls||clear");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                break;
            }
        }
   }
}
