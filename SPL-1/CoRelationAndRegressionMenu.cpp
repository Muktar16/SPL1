#include"header.h"
#include<graphics.h>

void CoRelationAndRegressionMenu()
{
    char tempStr[2000];
    int n,i,j;
    float X[100],Y[100],XY[100];

    initGraph("Input data window for Co-relation and Regration",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,2);
    setcolor(11);

    moveto(0,0);
    newLine();
    outtext("Enter values of class X separated with comma: ");
    newLine();
    getGrString(tempStr);//getting data values as a string separated with comma


    //convert string data to double data
    char *token = strtok(tempStr, ",");  // Returns first token
    X[0]=stod(token);

    i=1;
    while (token != NULL)
    {
        token = strtok(NULL, ",");
        if(token !=NULL)
        {
            X[i]=stod(token);
            i=i+1;
        }
    }
    n=i;//sample size
    int y = gety();

    while(1)
    {

        setcolor(11);
        newLine();
        newLine();
        outtext("Enter values of class Y separated with comma: ");
        newLine();

        getGrString(tempStr);//getting data values as a string separated with comma


        //convert string data to double data
        char *token = strtok(tempStr, ",");  // Returns first token
        X[0]=stod(token);

        i=1;
        while (token != NULL)
        {
            token = strtok(NULL, ",");
            if(token !=NULL)
            {
                Y[i]=stod(token);
                i=i+1;
            }
        }
        if(i==n) break;
        else
        {
            newLine();
            newLine();
            setcolor(LIGHTRED);
            outtext("Please Enter valid values. Amount of values for both classes should be equal.");
            newLine();
            sprintf(tempStr,"You should Enter %d values of Y.",n);
            outtext(tempStr);
            newLine();
            newLine();
            outtext("Press any key to try again..........");
            getch();
            cleardevice();
        }
    }

    //calculation of XY
    for(i=0;i<n;i++) XY[i]=X[i]*Y[i];

    //print results
    RegPrintResults(X,Y,XY,n);

}


//    system("cls||clear");
//
//    int n;
//    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//    printf("\n\t\t\t\t\t\t\tENTER SAMPLE SIZE: ");
//    scanf("%d",&n);
//
//    double X[n],Y[n],XY[n];
//
//    printf("\n\t\t\t\t\t\t\tENTER EXACTLY %d VALUES OF X WITH SPACE: ",n);
//    for(int i=0;i<n;i++) scanf("%lf",&X[i]);
//
//    printf("\n\t\t\t\t\t\t\tENTER EXACTLY %d VALUES OF Y WITH SPACE: ",n);
//    for(int i=0;i<n;i++)
//    {
//        scanf("%lf",&Y[i]);
//        XY[i]=X[i]*Y[i];
//    }
//    system("cls||clear");
//    RegPrintResults(X,Y,XY,n);
//
//
//    int choice;
//    printf("\n\n\n");
//
//    while(1)
//    {
//        printf("\n\t\t\t\t\t\t\t1.ANOTHER OPERATION\n\t\t\t\t\t\t\t2.BACK TO MAIN MENU\n\t\t\t\t\t\t\t3.DISPLAY GRAPH\n\t\t\t\t\t\t\t4.EXIT\n\t\t\t\t\t\t\t");
//        scanf("%d",&choice);
//
//        switch(choice)
//        {
//            case 1:
//            {
//                system("cls||clear");
//                CoRelationAndRegressionMenu();
//                break;
//            }
//            case 2:
//            {
//                system("cls||clear");
//                cout<<"\n\n\n\n\n\n\n\n\n";
//                return;
//            }
//            case 3:
//            {
//                system("cls||clear");
//                //printRegGraph(X,Y,n);
//                break;
//            }
//            case 4: exit(0);
//            default:
//            {
//                system("cls||clear");
//                printf("\n\t\t\t\t\t\t\tWRONG INPUT!!! PRESS ANY KEY TRY AGAIN.");
//                _getch();
//                system("cls||clear");
//            }
//
//        }
//    }

