#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include"header.h"
using namespace std;


void groupMenu()
{
    system("cls||clear");
    int n;
    cout<<"\n\tEnter number of classes: ";
    cin>>n;

    double LB[n],UB[n];
    int F[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n\tClass "<<i+1<<"\n";
        cout<<"\tEnter Lower Boundary and Upper Boundary (like: 10 15): ";
        scanf("%lf %lf",&LB[i],&UB[i]);
        printf("\n\tFrequency: ");
        scanf("%d",&F[i]);
    }

//    while(1)
//    {
//        system("cls||clear");
//        int ch;
//        cout<<"\n\t1.Display Frequency Distribution Table"
//            <<"\n\t2.Display Other Calculations(Mean,Mode,Median,SD etc.)"
//            <<"\n\n\tEnter your Choice: ";
//        cin>>ch;
//
//        if(ch==1)
//        {
            printFDtable(LB,UB,F,n);
//            return;
//        }
//        else if(ch==1)
//        {
//
//        }
//    }
}
