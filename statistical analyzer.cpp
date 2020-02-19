#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<stdlib.h>
//#include<conio.h>
using namespace std;

double Max,Min;

void main_menu();
void unGroupMenu();
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
double variance_calculator(double *Data,int dataNum)
{
    if(dataNum==1) return -1;
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
    if(dataNum==1) return 0.0;

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
   if(maxCount==1) return 0.0;
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

double qt_calculator(double *Data,int dataNum,int k)
{

    if(dataNum%2!=0)
    {
        int index = (k*(dataNum+1))/4;
        int i = (dataNum+1)%4;

        if(i==0)  return Data[index-1];
        else return (Data[index-1]+Data[index])/2;
    }
    else
    {
        int index = (k*dataNum)/4;
        int i=dataNum%4;

        if(i==0) return (Data[index-1]+Data[index])/2;
        else return Data[index];
    }

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

double sum_square(double *Data,int dataNum)
{
    double sumSQR=0;
    for(int i=0;i<dataNum;i++)
    {
        sumSQR+=(Data[i]*Data[i]);
    }
    return sumSQR;
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

void Sort(double *Data,int dataNum)
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
}

void unGroupMenu()
{
    system("cls");
    int dataNum;
    double Mean,Median,Variance;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\tENTER SAMPLE SIZE: ");
    scanf("%d",&dataNum);

    double Data[dataNum],Data2[dataNum];

    printf("\n\t\t\t\t\t\t\tENTER %d VALUES WITH SPACE: ",dataNum);
    for(int i=0; i<dataNum; i++)
    {
        scanf("%lf",&Data[i]);
        Data2[i]=Data[i];
    }

    //print all values
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t-> SAMPLE SEQUENCE    = ");   //print data sequence
    for(int i=0;i<dataNum; i++)
    {
        if(dataNum>10 && (i+1)%10==0) printf("\n\t\t\t\t\t\t\t                        ");
        printf("%.2f  ",Data[i]);
    }
    printf("\n");
    printf("\n\t\t\t\t\t\t\t-> GROWING SEQUENCE   = ");
    Sort(Data2,dataNum);
    for(int i=0;i<dataNum;i++)
    {
        if(dataNum>10 && (i+1)%10==0) printf("\n\t\t\t\t\t\t\t                        ");
        printf("%.2f  ",Data2[i]);
    }
    printf("\n");

    printf("\n\t\t\t\t\t\t\t-> SAMPLE SIZE        = %d",dataNum);
    printf("\n\t\t\t\t\t\t\t-> SUM OF X           = %.2f",sum(Data,dataNum));
    printf("\n\t\t\t\t\t\t\t-> SUM OF SQUARE X    = %.2f",sum_square(Data,dataNum));
    printf("\n");

    max_min_calculator(Data,dataNum);
    Median = median_calculator(Data2,dataNum);
    printf("\n\t\t\t\t\t\t\t-> MINIMUM VALUE      = %.2f",Min);
    printf("\n\t\t\t\t\t\t\t-> 1st QUARTILE       = %.2f",qt_calculator(Data2,dataNum,1));
    printf("\n\t\t\t\t\t\t\t-> MEDIAN             = %.2f",Median);
    printf("\n\t\t\t\t\t\t\t-> 3rd QUARTILE       = %.2f",qt_calculator(Data2,dataNum,3));
    printf("\n\t\t\t\t\t\t\t-> MAXIMUM VALUE      = %.2f",Max);
    printf("\n\t\t\t\t\t\t\t-> RANGE              = %.2f",Max-Min);
    printf("\n");

    Mean = mean_calculator(Data,dataNum);
    printf("\n\t\t\t\t\t\t\t-> MEAN (AVERAGE)     = %.2f",Mean);
    printf("\n\t\t\t\t\t\t\t-> GEOMETRIC MEAN     = %.2f",gmean_calculator(Data,dataNum));
    printf("\n\t\t\t\t\t\t\t-> HARMONIC MEAN      = %.2f",hmean_calculator(Data,dataNum));
    printf("\n\t\t\t\t\t\t\t-> MODE               = %.2f",mode_calculator(Data,dataNum));
    Variance = variance_calculator(Data,dataNum);
    if(Variance==-1) printf("\n\t\t\t\t\t\t\t-> VARIANCE OF X      = NaN");
    else printf("\n\t\t\t\t\t\t\t-> VARIANCE OF X      = %.2f",Variance);
    printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION = %.2f",sqrt(Variance));
    printf("\n\t\t\t\t\t\t\t-> STANDARD ERROR     = %.2f",sqrt(Variance)/sqrt(dataNum));
    printf("\n");

    printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF VARIANCE = %.2f\%",(sqrt(Variance)/Mean)*100);
    printf("\n\t\t\t\t\t\t\t-> PEARSONS COEFFICIENT OF SKEWNESS = %.2f",(3*(Mean-Median))/sqrt(Variance));

    int choice;
    printf("\n\n\n");

    label:
    printf("\n\t\t\t\t\t\t\t1.ANOTHER OPERATION\n\t\t\t\t\t\t\t2.MENU\n\t\t\t\t\t\t\t3.EXIT\n\t\t\t\t\t\t\t");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            system("cls");
            unGroupMenu();
            break;
        }
        case 2:
        {
            system("cls");
            main_menu();
            break;
        }
        case 3: exit(0);
        default:
            {
                printf("\n\t\t\t\t\t\t\tWRONG INPUT!!! TRY AGAIN.");
                goto label;
            }
    }
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
        case 1: {unGroupMenu(); break;}
        case 2: {groupMenu(); break;}
//        case 3: {unGroupToGroupMenu(); break;}
//        case 4: {regAndCorMenu(); break;}
//        case 5: {probabilityMenu(); break;}
//        case 6: {formulaSheetsMenu(); break;}
        case 7: exit(0);
        default:
        {
            system("cls");
            printf("\n\t\t\t\t\t\t\tWRONG INPUT!!! TRY AGAIN\n");
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
