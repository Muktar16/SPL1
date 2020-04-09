#include"header.h"

void unGroupToGroupMenu()
{
    system("cls||clear");
    int N,G;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\tENTER SAMPLE SIZE: ");
    scanf("%d",&N);

    double Data[N];

    printf("\n\t\t\t\t\t\t\tENTER EXACTLY %d VALUES WITH SPACE: ",N);
    for(int i=0; i<N; i++)
    {
        scanf("%lf",&Data[i]);
    }
    printf("\n\t\t\t\t\t\t\tENTER NUMBER GROUPS: ");
    scanf("%d",&G);

    double LB[G],UB[G];
    int F[G];

    unGroupToGroupConverter(Data,LB,UB,F,G,N);

    while(1)
    {
        system("cls||clear");
        int ch;
        printf("\n\n\n\n\n\n\n\n");
        cout<<"\n\t\t\t\t\t\t\t\t1.Display Frequency Distribution Table"
            <<"\n\t\t\t\t\t\t\t\t2.Display Final Results"
            <<"\n\t\t\t\t\t\t\t\t3.Display Frequency Distribution Table and Final Results"
            <<"\n\t\t\t\t\t\t\t\t4.Display Frequency Polygon"
            <<"\n\t\t\t\t\t\t\t\t5.Display Ogive"
            <<"\n\t\t\t\t\t\t\t\t6.Back to Main Menu"
            <<"\n\t\t\t\t\t\t\t\t7.Exit"
            <<"\n\n\t\t\t\t\t\t\t\tEnter your Choice: ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            {
                system("cls||clear");
                printFDtable(LB,UB,F,G);
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                getch();
                break;
            }
        case 2:
            {
                system("cls||clear");
                printf("\n\n\n\n\n\n\n\n\n");
                printFinalResults(LB,UB,F,G);
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                getch();
                break;
            }
        case 3:
            {
                system("cls||clear");
                printFDtable(LB,UB,F,G);
                printf("\n\n\n");
                printFinalResults(LB,UB,F,G);
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                getch();
                break;
            }
        case 6:
            {
                system("cls||clear");
                return;
            }
        case 7:
            {
                exit(0);
            }
        }
    }
}
