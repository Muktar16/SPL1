#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include"header.h"
using namespace std;


void groupMenu()
{
    system("cls||clear");
    int n;
    cout<<"\n\n\t\t\t\t\t\t\t\tENTER NUMBER OF CLASSES: ";
    cin>>n;

    double LB[n],UB[n];
    int F[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n\t\t\t\t\t\t\t\tClass "<<i+1<<":\n";
        cout<<"\t\t\t\t\t\t\t\tEnter Lower Boundary and Upper Boundary (like: 10 15): ";
        scanf("%lf %lf",&LB[i],&UB[i]);
        printf("\t\t\t\t\t\t\t\tFrequency: ");
        scanf("%d",&F[i]);
    }

    while(1)
    {
        system("cls||clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        int ch;
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
                printFDtable(LB,UB,F,n);
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
        case 2:
            {
                system("cls||clear");
                printf("\n\n\n\n\n\n\n\n\n");
                printFinalResults(LB,UB,F,n);
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
        case 3:
            {
                system("cls||clear");
                printFDtable(LB,UB,F,n);
                printf("\n\n\n");
                printFinalResults(LB,UB,F,n);
                cout<<"\n\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
        case 4:
            {
                system("cls||clear");
                printFrequencyPolygon(LB,UB,F,n);
                cout<<"\n\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
        case 5:
        {
            system("cls||clear");
            //printOgive(LB,UB,F,n);
            cout<<"\n\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
            _getch();
            break;
        }
        case 6:
            {
                system("cls||clear");
                printf("\n\n\n");
                main_menu();
                return;
            }
        case 7:
            {
                exit(0);
            }
        default:
            {
                system("cls||clear");
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWRONG INPUT!!! PRESS ANY KEY TO TRY AGAIN......");
                _getch();
                break;
            }
        }
    }
}
