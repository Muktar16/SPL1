
double group_median_calculator(double *LB,double *UB,int *F,int n)
{
    int N=0,cF[n];
    cF[-1]=0;
    for(int i=0;i<n;i++)
    {
        N+=F[i];
        cF[i]=cF[i-1]+F[i];
    }
    double t = (double)N/2;


    int m=0;
    for(int i=0;i<n;i++)
    {
        if(cF[i]>t)
        {
            m = i;
            break;
        }
    }

    double cfm ;
    if(m == 0) cfm=0;
    else cfm = cF[m-1];

    double fm = F[m];
    double h = UB[m]-LB[m];

    return (LB[m] + ((t-cfm)/fm)*h);
}
