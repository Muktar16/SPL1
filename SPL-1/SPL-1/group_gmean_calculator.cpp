#include<math.h>

double group_gmean_calculator(double *LB,double *UB,int *F,int n)
{
    double x[n],temp=1;
    int N=0;
    for(int i=0;i<n;i++)
    {
        N+=F[i];
        x[i]=(LB[i]+UB[i])/2;
        temp*=pow(x[i],F[i]);
    }
    return pow(temp,(1/(double)N));
}
