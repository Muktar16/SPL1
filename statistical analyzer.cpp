#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

void mainMenu();
void unGroupMenu();
void groupMenu();
void unGroupToGroupMenu();
void regAndCorMenu();
void probabilityMenu();
void formulaSheetsMenu();
double sum(double *data,int dataNum);
double* max_min_calculator(double *Data);
double mean_calculator(double* Data,int dataNum);
double gmean_calculator(double* Data,int dataNum);
double hmean_calculator(double *Data,int dataNum);

double hmean_calculator(double *Data,int dataNum)
{
    for(int i=0; i<dataNum; i++)
    {

    }
}

double gmean_calculator(double* Data,int dataNum)
{
    double product=1,GMean;
    for(int i=0; i<dataNum;i++)
    {
        product*=Data[i];
    }
    GMean = pow(product,(1/dataNum));
    return GMean;
}

double mean_calculator(double *Data, int dataNum)
{
    double Sum;
    Sum=sum(Data,dataNum);
    return Sum/dataNum;
}

double* max_min_calculator(double *Data,int dataNum)
{
    double MaxMin[2];
    MaxMin[0]=MaxMin[1]=Data[0];

    for(int i=0;i<dataNum; i++)
    {
        if(MaxMin[0]<Data[i]) MaxMin[0]=Data[i];
        if(MaxMin[1]>Data[i]) MaxMin[1]=Data[i];
    }
    return MaxMin;

}

double sum(double *Data,int dataNum)
{
    double sum=0;
    for(int i=0;i<dataNum;i++)
    {
        sum+=Data[i];
    }
    return sum;
}

void unGroupMenu()
{
    int dataNum;
    double Sum,Mean,GMean,HMean,Median,Mode,Range,Variance,SD,PCS;
    double *MaxMin;

    cout<<"\n\t\t\t\tEnter the number of Data: ";
    scanf("%d",&dataNum);

    double Data[dataNum];

    cout<<"\n\t\t\t\tEnter data values with space: ";
    for(int i=0; i<dataNum; i++)
    {
        cin>>Data[i];
    }

    //print all data
    cout<<"\n\n\t\t\t\tYour Data:  ";
    for(int i=0;i<dataNum; i++)
    {
        printf("%.2f  ",Data[i]);
    }

    Sum = sum(Data,dataNum);
    MaxMin = max_min_calculator(Data,dataNum);
    Mean = mean_calculator(Data, dataNum);
    GMean = gmean_calculator(Data, dataNum);
    HMean = hmean_calculator(Data,dataNum);

}

void main_menu()
{
    int choice;
    cout<<"\t\t\t\t1. Un Group Data\n";
    cout<<"\t\t\t\t2. Group Data\n";
    cout<<"\t\t\t\t3. Conversion from Un Group to Group Data\n";
    cout<<"\t\t\t\t4. Regression and Co-Relation\n";
    cout<<"\t\t\t\t5. Probability Distributions\n";
    cout<<"\t\t\t\t6. Formula Sheets Menu\n";
    cout<<"\t\t\t\t7. Exit\n\n\n";
    cout<<"\t\t\t\tEnter your Choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1: unGroupMenu();
//        case 2: groupMenu();
//        case 3: unGroupToGroupMenu();
//        case 4: regAndCorMenu();
//        case 5: probabilityMenu();
//        case 6: formulaSheetsMenu();
          case 7: exit(0);
    }
}

int main()
{
    cout<<"\n\n";
    cout<<"\t\t\t\t================================================\n";
    cout<<"\t\t\t\t\tWELCOME TO STATISTICAL CALCULATOR\n";
    cout<<"\t\t\t\t================================================\n\n\n\n";
    main_menu();
}
