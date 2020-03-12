#include"header.h"
#include<stdlib.h>
double* max_min_calculator(double *Data,int dataNum)
{
    double* max_min = new double [2];
    //double *max_min=(double*)malloc(2);
    max_min[0]=max_min[1]=Data[0];

    for(int i=0;i<dataNum; i++)
    {
        if(max_min[0]<Data[i]) max_min[0]=Data[i];
        if(max_min[1]>Data[i]) max_min[0]=Data[i];
    }
    return max_min;
}
