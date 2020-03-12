#include"header.h"

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
