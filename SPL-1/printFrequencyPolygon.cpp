#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


void printFrequencyPolygon(double *LB,double* UB,int *F,int n)
{
    int x,y,maxF=0;
    system("cls||clear");
    double MidPoint[n];
    for(int i=0;i<n;i++)
    {
        if(maxF<F[i]) maxF = F[i];
        MidPoint[i]=(LB[i]+UB[i])/2;
    }

//    int plot[maxF][n];
//    for(int i=)
//
//    for(y=maxF;y>=0;y--)
//    {
//        for(x=0;x<=n;x++)
//        {
//            if()
//        }
//    }
}
