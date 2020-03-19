

double group_mean_calculator(double *LB,double* UB,int *F,int n)
{
    int N=0;
    double fixi=0,x[n];
    for(int i=0;i<n;i++)
    {
        x[i]=(LB[i]+UB[i])/2;
        fixi+=x[i]*(double)F[i];
        N+=F[i];
    }
    return fixi/(double)N;
}
