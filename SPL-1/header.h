#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;


void AltEnter();

void main_menu();
void unGroupMenu();
void Sort(double *Data,int dataNum);
double sum(double *Data,int dataNum);
double sum_square(double *Data,int dataNum);
double* max_min_calculator(double *Data,int dataNum);
double median_calculator(double *Data,int dataNum);
double qt_calculator(double *Data,int dataNum,int k);
double mean_calculator(double *Data, int dataNum);
double gmean_calculator(double* Data,int dataNum);
double hmean_calculator(double *Data,int dataNum);
double mode_calculator(double *Data,int dataNum);
double variance_calculator(double *Data,int dataNum);

void groupMenu();
void printFDtable(double *LB,double* UB,int *,int );
void printFinalResults(double *LB,double* UB,int *F,int n);
double group_mean_calculator(double *LB,double *UB,int *F,int n);
double group_gmean_calculator(double *LB,double *UB,int *F,int n);
double group_hmean_calculator(double *LB,double *UB,int *F,int n);
double group_median_calculator(double *LB,double *UB,int *F,int n,int q);
double group_mode_calculator(double *LB,double *UB,int *F,int n);
double group_variance_calculator(double *LB,double *UB,int *F,int n);
void printFrequencyPolygon(double *LB,double* UB,int *F,int n);

void unGroupToGroupMenu();
void unGroupToGroupConverter(double* Data,double* LB,double* UB,int *F,int G,int N);

void CoRelationAndRegressionMenu();
void RegPrintResults(double *X,double *Y,double *XY ,int n);
double sb1_calculator(double* X,double* Y,int n);

void formulaSheetsMenu();
void read_file(char *filename);
