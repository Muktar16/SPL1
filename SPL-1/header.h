#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;


//void AltEnter();
void initGraph(char *,int, int,int,int);
void main_menu();

void getGrString(char *inputString);
void newLine();
void doCursor(int);
//ungrouped data related functions
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

//grouped data related functions
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
void printOgive(double *LB,double* UB,int *F,int n);
void printPieChart(int *F,int n);
void printHistogram(double *LB,double *UB,int *F,int n);

//ungrouped to grouped converter related functions
void unGroupToGroupMenu();
void unGroupToGroupConverter(double* Data,double* LB,double* UB,int *F,int G,int N);

//correlation and regression related functions
void CoRelationAndRegressionMenu();
void RegPrintResults(double *X,double *Y,double *XY ,int n);
void printScatterDiagram(double* X,double *Y,int n,double r);
double sb1_calculator(double* X,double* Y,int n);

void probabilityMenu();
void binomial_distribution();
void printBinoResults(int n,float p,int X,int sign);
void poison_distribution(int type);
float calculate_pois_dist_prob(float u,int x);
void printPoissionResults(int n,float p,float u,int x,int sign,int type);
double calculate_b(int n,int x,double p);
void geometric_distribution();
void printGeometricResults(float p,int x,int sign);
float calculate_geometric_probability(int x,float p);
void Hyper_geo_dis();
float hyperGeoProbCalculator(float N,float k,float n,float x);
void neg_bio_dis();
float calculate_neg_bino_prob(int n,int X,float P);
void printNegBinoResults(int n,float p,int X,int sign);
//void intermediateMenu();

//void graphMenu();

void formulaSheetsMenu();
//void read_file(char *filename);
