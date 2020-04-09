#include"header.h"

void CoRelationAndRegressionMenu()
{
    system("cls||clear");

    int n;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\tENTER SAMPLE SIZE: ");
    scanf("%d",&n);

    double X[n],Y[n],XY[n];

    printf("\n\t\t\t\t\t\t\tENTER EXACTLY %d VALUES OF X WITH SPACE: ",n);
    for(int i=0;i<n;i++) scanf("%lf",&X[i]);

    printf("\n\t\t\t\t\t\t\tENTER EXACTLY %d VALUES OF Y WITH SPACE: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&Y[i]);
        XY[i]=X[i]*Y[i];
    }
    system("cls||clear");
    RegPrintResults(X,Y,XY,n);


    int choice;
    printf("\n\n\n");

    while(1)
    {
        printf("\n\t\t\t\t\t\t\t1.ANOTHER OPERATION\n\t\t\t\t\t\t\t2.BACK TO MAIN MENU\n\t\t\t\t\t\t\t3.DISPLAY GRAPH\n\t\t\t\t\t\t\t4.EXIT\n\t\t\t\t\t\t\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                system("cls||clear");
                CoRelationAndRegressionMenu();
                break;
            }
            case 2:
            {
                system("cls||clear");
                cout<<"\n\n\n\n\n\n\n\n\n";
                return;
            }
            case 3:
            {
                system("cls||clear");
                //printRegGraph(X,Y,n);
                break;
            }
            case 4: exit(0);
            default:
            {
                system("cls||clear");
                printf("\n\t\t\t\t\t\t\tWRONG INPUT!!! PRESS ANY KEY TRY AGAIN.");
                getch();
                system("cls||clear");
            }

        }
    }


}
