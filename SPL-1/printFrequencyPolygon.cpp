#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


void printFrequencyPolygon(double *LB,double* UB,int *F,int n)
{
    int y,maxF=0;
    system("cls||clear");
    double MidPoint[n];
    for(int i=0;i<n;i++)
    {
        if(maxF<F[i]) maxF = F[i];
        MidPoint[i]=(LB[i]+UB[i])/2;
    }

    printf("\n\n");
    printf("\n\t\t\t\t\t\t\t============================");
    printf("\n\t\t\t\t\t\t\t      FREQUENCY POLYGON");
    printf("\n\t\t\t\t\t\t\t============================");

    printf("\n\n\n\n\n");
    for(y=maxF;y>=0;y--)
    {
        printf("\t\t\t\t\t\t\t%4d |      ",y);
        for(int i=0;i<n;i++)
        {
            if(F[i]==y) printf("*       ");
            else printf("        ");
        }
        printf("\n");
        if(maxF<=30) printf("\t\t\t\t\t\t\t     |\n");
    }
    printf("\t\t\t\t\t\t\t    ");
    for(int i=0;i<n;i++)
    {
        printf("------------");
    }
    printf("\n\t\t\t\t\t\t\t\t    ");
    for(int i=0;i<n;i++)
    {
        printf("%4.2lf   ",MidPoint[i]);
    }
}
