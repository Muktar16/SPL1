
double group_mode_calculator(double *LB,double *UB,int *F,int n)
{
    int max = 0 ,m;
    for(int i=0;i<n;i++)
    {
        if(F[i]>max)
        {
            max = F[i];
            m = i;
        }
    }

    double h = UB[m]-LB[m];
    double f1,f2,f0;
    f1 = F[m];

    if(n==1)
    {
        f0=f2=0;
    }
    else if(m==0 && n>1)
    {
        f0=0;
        f2=F[m+1];
    }
    else if(n>1 && m==n-1)
    {
        f2=0;f0=F[m-1];
    }
    else
    {
        f0=F[m-1];
        f2=F[m+1];
    }

    return LB[m] + ((f1-f0)/((2*f1)-f0-f2))*h;
}
