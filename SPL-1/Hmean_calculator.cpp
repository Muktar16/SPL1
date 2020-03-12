#include"header.h"

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
