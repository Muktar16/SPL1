#include<math.h>
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
