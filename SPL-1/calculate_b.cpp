#include"header.h"

double calculate_b(int n,int x,double p)
{
    double b;
    int m,r;
    double nf=1,xf=1,nxf=1;;

    nf=tgamma(n+1);
    xf=tgamma(x+1);
    nxf=tgamma(n-x+1);

    return (nf/xf)*((pow(p,x)*pow(1-p,n-x))/nxf);
}
