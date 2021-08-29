

double group_hmean_calculator(double *LB,double *UB,int *F,int n)
{
    int N=0;
    double fibyxi=0,x[n];
    for(int i=0;i<n;i++)
    {
        x[i]=(LB[i]+UB[i])/2;
        fibyxi+=(double)F[i]/x[i];
        N+=F[i];
    }
    return (double)N/fibyxi;
}
