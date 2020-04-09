#include"header.h"

double sb1_calculator(double* X,double* Y,int n)
{
    double sum1=0,sum2=0;
    double meanX = mean_calculator(X,n);
    double meanY = mean_calculator(Y,n);

    for(int i=0;i<n;i++)
    {
        sum1 = sum1 + (X[i]-meanX)*(X[i]-meanX);
        sum2 = sum2 + (Y[i]-meanY)*(Y[i]-meanY);
    }

    return sqrt(sum2/((n-2)*sum1));
}
