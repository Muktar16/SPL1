#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.h"
using namespace std;


void unGroupMenu()
{
    system("cls||clear");
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

    double *Max_min;
    Max_min = max_min_calculator(Data,dataNum);
    Median = median_calculator(Data2,dataNum);
    printf("\n\t\t\t\t\t\t\t-> MINIMUM VALUE      = %.2f",Max_min[1]);
    printf("\n\t\t\t\t\t\t\t-> 1st QUARTILE       = %.2f",qt_calculator(Data2,dataNum,1));
    printf("\n\t\t\t\t\t\t\t-> MEDIAN             = %.2f",Median);
    printf("\n\t\t\t\t\t\t\t-> 3rd QUARTILE       = %.2f",qt_calculator(Data2,dataNum,3));
    printf("\n\t\t\t\t\t\t\t-> MAXIMUM VALUE      = %.2f",Max_min[0]);
    printf("\n\t\t\t\t\t\t\t-> RANGE              = %.2f",Max_min[0]-Max_min[1]);
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
