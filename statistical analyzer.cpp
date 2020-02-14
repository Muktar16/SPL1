#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
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
double median_calculator(double* Data,int dataNum);
double mode_calculator(double* Data,int dataNum);
double variance_calculator(double *Data,int dataNum);

double variance_calculator(double *Data,int dataNum)
{

}

double mode_calculator(double *Data,int dataNum)
{
   double maxValue = 0, maxCount = 0;

   for (int i=0;i<dataNum;i++)
   {
      int count=0;
      for (int j=0;j<dataNum;j++)
      {
         if(Data[j]==Data[i])
         count++;
      }
      if(count>maxCount)
      {
         maxCount = count;
         maxValue = Data[i];
      }
   }
   return maxValue;
}

double median_calculator(double *Data,int dataNum)
{
    int n=dataNum-1;
    if(dataNum%2==0)
    {
        return (Data[n/2]+Data[(n/2)+1])/2.0;
    }
    else
    {
        return Data[(n+1)/2];
    }
}

double hmean_calculator(double *Data,int dataNum)
{
    double HMean,Sum=0;
    for(int i=0; i<dataNum; i++)
    {
        Sum = Sum+(double)1/Data[i];
    }
    HMean = (double)dataNum/Sum;
    return HMean;
}

double gmean_calculator(double* Data,int dataNum)
{
    double product=1,GMean;
    for(int i=0; i<dataNum;i++)
    {
        product*=Data[i];
    }
    GMean = pow(product,(double)1/dataNum);
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

    printf("\n\t\t\t\tEnter the number of Data: ");
    scanf("%d",&dataNum);

    double Data[dataNum];

    printf("\n\t\t\t\tEnter data values with space: ");
    for(int i=0; i<dataNum; i++)
    {
        scanf("%lf",&Data[i]);
    }

    //print all data
    printf("\n\n\t\t\t\tYour Data are:  ");
    for(int i=0;i<dataNum; i++)
    {
        printf("%.2f  ",Data[i]);
    }
    printf("\n");

    Sum = sum(Data,dataNum);
    MaxMin = max_min_calculator(Data,dataNum);
    Mean = mean_calculator(Data, dataNum);
    GMean = gmean_calculator(Data, dataNum);
    HMean = hmean_calculator(Data,dataNum);
    Median = median_calculator(Data,dataNum);
    Mode = mode_calculator(Data,dataNum);
    Range =
    Variance = variance_calculator(Data,dataNum);

    //print all values
    system("cls");
    printf("\n\t\t\t\tSummation -> %.2f",Sum);
//    printf("\n\t\t\t\tHighest value -> %.2f",MaxMin[0]);
//    printf("\n\t\t\t\tLowest value -> %.2f",MaxMin[1]);
    printf("\n\t\t\t\tMean -> %.2f",Mean);
    printf("\n\t\t\t\tGeometric Mean -> %.2f",GMean);
    printf("\n\t\t\t\tHarmonic Mean -> %.2f",HMean);
    printf("\n\t\t\t\tMedian -> %.2f",Median);
    printf("\n\t\t\t\tMode -> %.2f",Mode);
    printf("\n\t\t\t\tRange -> %.2f",Range);

}

void main_menu()
{
    int choice;
    cout<<"\t\t\t\t1. UNGROUPED DATA\n";
    cout<<"\t\t\t\t2. GROUPED DATA\n";
    cout<<"\t\t\t\t3. UNGROUPED TO GROUPED DATA CONVERTER\n";
    cout<<"\t\t\t\t4. REGRESSION & CO-RELATION\n";
    cout<<"\t\t\t\t5. PROBABILITY DISTRIBUTION\n";
    cout<<"\t\t\t\t6. FORMULA SHEETS\n";
    cout<<"\t\t\t\t7. EXIT\n\n\n";
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
