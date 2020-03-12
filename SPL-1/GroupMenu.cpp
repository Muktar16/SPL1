#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;


void groupMenu()
{
    system("cls||clear");
    int n;
    cout<<"\n\tEnter number of classes: ";
    cin>>n;

    double Class[n][n];
    int F[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n\tClass "<<i+1<<"\n";
        cout<<"\tEnter Lower Boundary and Upper Boundary (like: 10 15): ";
        scanf("%lf %lf",&Class[i][0],&Class[i][1]);
        printf("\n\tFrequency: ");
        scanf("%d",&F[i]);
    }


}
