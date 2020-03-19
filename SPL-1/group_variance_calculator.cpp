#include"header.h"

double group_variance_calculator(double *LB,double *UB,int *F,int n)
{
    double mean = group_mean_calculator(LB,UB,F,n);
    double x[n],sum=0;
    int N =0;
    for(int i = 0;i<n;i++)
    {
        N+=F[i];
        x[i]=(LB[i]+UB[i])/2;
        sum = sum+ F[i]*(mean-x[i])*(mean-x[i]);
    }

    return sum/(double)N;
}
