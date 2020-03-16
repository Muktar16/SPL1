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
        int ch;
        cout<<"\n\t\t\t\t\t\t\t\t1.Display Frequency Distribution Table"
            <<"\n\t\t\t\t\t\t\t\t2.Display Final Results"
            <<"\n\t\t\t\t\t\t\t\t3.Display Frequency Polygon"
            <<"\n\t\t\t\t\t\t\t\t3.Display Ogive"
            <<"\n\n\t\t\t\t\t\t\t\tEnter your Choice: ";
        cin>>ch;

        if(ch==1)
        {
            printFDtable(LB,UB,F,n);
            cout<<"\n\t\t\t\t\t\t\t\tPress Any Key To Continue..............";
            getch();
        }
        else if(ch==2)
        {
            printFinalResults(LB,UB,F,n);
            cout<<"\n\t\t\t\t\t\t\t\tPress Any Key To Continue..............";
            getch();
        }
        else if(ch==3)
        {
            //printFrequencyPolygon(LB,UB,F,n);
            cout<<"\n\t\t\t\t\t\t\t\tPress Any Key To Continue..............";
            getch();
        }
    }
}
