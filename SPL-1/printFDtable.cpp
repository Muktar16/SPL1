#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void printFDtable(double *LB,double *UB,int *F,int n)
{
    system("cls||clear");
    double LCB[n],UCB[n],RF[n];
    int CF[n],Total=0;
    double MV[n];

    //Class Boundary
    for(int i=0;i<n;i++)
    {
        LCB[i]=LB[i]-0.5;
        UCB[i]=UB[i]+0.5;
    }
    //Cumulative Frequency
    CF[0]=F[0];
    for(int i=1;i<n;i++)
    {
        CF[i]=CF[i-1]+F[i];
    }
    //Mid Value
    for(int i=0;i<n;i++)
    {
        MV[i] = (LB[i]+UB[i])/2;
    }
    //Total Frequency
    for(int i=0;i<n;i++)
    {
        Total=Total+F[i];
    }
    //Relative Frequency
    for(int i=0;i<n;i++)
    {
        RF[i]=(double)F[i]/(double)Total;
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t\t\t\t\t=========================================\n";
    cout<<"\t\t\t\t\t\t\t\t        FREQUENCY DISTRIBUTION TABLE\n";
    cout<<"\t\t\t\t\t\t\t\t=========================================\n\n";

    cout<<"\t\t  |--------------------------------------------------------------------------------------------------------------------------------|\n";
    cout<<"\t\t  |                                                                                                                                |\n";
    cout<<"\t\t  |\tClass_Interval\t   Class_Boundary\t Mid_Value\tFrequency\tRelative_Frequency\tCumulative_Frequency\t   |\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t\t  |                                                                                                                                |\n";
        printf("\t\t  |    %6.1lf -%6.1lf     %6.1lf -%6.1lf          %6.2lf          %4d               %6.2lf                  %4d\t\t   |",LB[i],UB[i],LCB[i],UCB[i],MV[i],F[i],RF[i],CF[i]);
        cout<<"\n\t\t  |                                                                                                                                |\n";
    }
    cout<<"\t\t  |                                                                                                                                |\n";
    cout<<"\t\t  |--------------------------------------------------------------------------------------------------------------------------------|\n\n";
}
