#include<math.h>

float calculate_neg_bino_prob(int n,int X,float P)
{
    float prob;//probability
    int nf=1;//n-1 factorial
    int xf=1;//x-1 factorial
    int nxf=1;//(n-1)-(x-1) factorial
    float n_1Cx_1=1;//n-1Cx-1

    //calculation
    nf=tgamma(n);//n-1 factorial
    xf=tgamma(X);//x-1 factorial
    nxf=tgamma((n-1)-(X-1)+1);//(n-1)-(x-1) factorial
    n_1Cx_1=nf/(xf*nxf);//n-1Cx-1
    prob=n_1Cx_1*pow(P,X)*pow(1-P,n);//negative binomial distribution using formula

    return prob;

}
