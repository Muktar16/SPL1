#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

double Max,Min;

void mainMenu();
void unGroupMenu();
void groupMenu();
void unGroupToGroupMenu();
void regAndCorMenu();
void probabilityMenu();
void formulaSheetsMenu();
double sum(double *data,int dataNum);
void max_min_calculator(double *Data);
double mean_calculator(double* Data,int dataNum);
double gmean_calculator(double* Data,int dataNum);
double hmean_calculator(double *Data,int dataNum);
double median_calculator(double* Data,int dataNum);
double mode_calculator(double* Data,int dataNum);
double variance_calculator(double *Data,int dataNum);

double variance_calculator(double *Data,int dataNum)
{
    double mean = mean_calculator(Data,dataNum);
    double Sum=0;
    for(int i=0;i<dataNum;i++)
    {
        Sum=Sum+(Data[i]-mean)*(Data[i]-mean);
    }
    return Sum/(dataNum-1);
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

void max_min_calculator(double *Data,int dataNum)
{
    Max=Min=Data[0];

    for(int i=0;i<dataNum; i++)
    {
        if(Max<Data[i]) Max=Data[i];
        if(Min>Data[i]) Min=Data[i];
    }
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

void print_Growing_sequence(double *Data,int dataNum)
{
    for(int i=0;i<dataNum;i++)
    {
        for(int j=0;j<dataNum-i-1;j++)
        {
            if(Data[j]>Data[j+1])
            {
                double temp = Data[j];
                Data[j]=Data[j+1];
                Data[j+1]=temp;
            }
        }
    }

    for(int i=0;i<dataNum;i++)
    {
        printf("%.2f  ",Data[i]);
    }
}

void unGroupMenu()
{
    system("cls");
    int dataNum;
    double Sum,Mean,GMean,HMean,Median,Mode,Range,Variance,SD,PCS;
    double *MaxMin;

    printf("\n\n\n\n\t\t\t\t\t\t\tSAMPLE SIZE: ");
    scanf("%d",&dataNum);

    double Data[dataNum];

    printf("\n\t\t\t\t\t\t\tENTER %d VALUES WITH SPACE: ",dataNum);
    for(int i=0; i<dataNum; i++)
    {
        scanf("%lf",&Data[i]);
    }

    //print all data
//    Sum = sum(Data,dataNum);
//    max_min_calculator(Data,dataNum);
//    Mean = mean_calculator(Data, dataNum);
//    GMean = gmean_calculator(Data, dataNum);
//    HMean = hmean_calculator(Data,dataNum);
//    Median = median_calculator(Data,dataNum);
//    Mode = mode_calculator(Data,dataNum);
//    Range = Max-Min;
//    Variance = variance_calculator(Data,dataNum);

    //print all values
    system("cls");
    printf("\n\n\t\t\t\t\t\t-> SAMPLE SEQUENCE = ");   //print data sequence
    for(int i=0;i<dataNum; i++)
    {
        printf("%.2f  ",Data[i]);
    }
    printf("\n\t\t\t\t\t\t\t\t-> GROWING SEQUENCE = ");
    print_Growing_sequence(Data,dataNum);
    printf("\n");
    printf("\n\t\t\t\tSummation -> %.2f",sum(Data,dataNum));
    max_min_calculator(Data,dataNum);
    printf("\n\t\t\t\tHighest value -> %.2f",Max);
    printf("\n\t\t\t\tLowest value -> %.2f",Min);
    printf("\n\t\t\t\tMean -> %.2f",Mean);
    printf("\n\t\t\t\tGeometric Mean -> %.2f",GMean);
    printf("\n\t\t\t\tHarmonic Mean -> %.2f",HMean);
    printf("\n\t\t\t\tMedian -> %.2f",Median);
    printf("\n\t\t\t\tMode -> %.2f",Mode);
    printf("\n\t\t\t\tRange -> %.2f",Range);
    printf("\n\t\t\t\tVariance -> %.2f",Variance);

}

void main_menu()
{
    int choice;
    cout<<"\n\t\t\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t\t     ===============\n\n"
        <<"\t\t\t\t\t\t\t1. UNGROUPED DATA\n"
        <<"\t\t\t\t\t\t\t2. GROUPED DATA\n"
        <<"\t\t\t\t\t\t\t3. UNGROUPED TO GROUPED DATA CONVERTER\n"
        <<"\t\t\t\t\t\t\t4. REGRESSION & CO-RELATION\n"
        <<"\t\t\t\t\t\t\t5. PROBABILITY DISTRIBUTION\n"
        <<"\t\t\t\t\t\t\t6. FORMULA SHEETS\n"
        <<"\t\t\t\t\t\t\t7. EXIT\n\n\n"
        <<"\t\t\t\t\t\t\tEnter your Choice: ";
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
        default:
            {
                printf("\nWrong Input.Try again.\n");
                main_menu();
            }


    }
}

int main()
{
    cout<<"\n\n";
    cout<<"\t\t\t\t\t\t================================================\n";
    cout<<"\t\t\t\t\t\t\tWELCOME TO STATISTICAL CALCULATOR\n";
    cout<<"\t\t\t\t\t\t================================================\n\n\n";
    main_menu();
}
