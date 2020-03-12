#include"header.h"

double mean_calculator(double *Data, int dataNum)
{
    double Sum;
    Sum=sum(Data,dataNum);
    return Sum/dataNum;
}
