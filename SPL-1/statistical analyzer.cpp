#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<stdlib.h>
//#include<conio.h>
using namespace std;



void main_menu();

void groupMenu();
void unGroupToGroupMenu();
void regAndCorMenu();
void probabilityMenu();
void formulaSheetsMenu();
double sum(double *data,int dataNum);
double sum_square(double *Data,int dataNum);
void max_min_calculator(double *Data);
double qt_calculator(double *Data,int dataNum,int k);
double mean_calculator(double* Data,int dataNum);
double gmean_calculator(double* Data,int dataNum);
double hmean_calculator(double *Data,int dataNum);
double median_calculator(double* Data,int dataNum);
double mode_calculator(double* Data,int dataNum);
double variance_calculator(double *Data,int dataNum);
void printFDtable(double **Class,int *F,int n);

void printFDtable(double **Class,int *F,int n)
{

}

void groupMenu()
{
    system("cls");
    int n;
    printf("\n\t\t\t\t\t\t\tEnter number of classes: ");
    scanf("%d",&n);

    double Class[n][n];
    int F[n];
    for(int i=0;i<n;i++)
    {
        printf("\n\t\t\t\t\t\t\tClass %d: ",i+1);
        printf("\tLower Boundary-Upper Boundery: ");
        scanf("%lf %lf",&Class[i][0],&Class[i][1]);
        printf("\n\t\t\t\t\t\t\tFrequency: ");
        scanf("%d",&F[i]);
    }

}

//Ungrouped functions

















