#include"header.h"

double variance_calculator(double *Data,int dataNum)
{
    //variance of a single data is 0
    if(dataNum==1) return 0;
    //calculate mean
    double mean = mean_calculator(Data,dataNum);
    double Sum=0;

    for(int i=0;i<dataNum;i++)
    {
        Sum=Sum+(Data[i]-mean)*(Data[i]-mean);//summation of (xi-x)
    }
    //return variance
    return Sum/(dataNum-1);
}
