#include"header.h"

double calculate_b(int n,int x,double p)
{
    double b;
    int m,r;
    double nf=1,xf=1,nxf=1;;

    nf=tgamma(n+1);//n factorial
    xf=tgamma(x+1);//x factorial
    nxf=tgamma(n-x+1);//n-x factorial

    return (nf/xf)*((pow(p,x)*pow(1-p,n-x))/nxf);
}
