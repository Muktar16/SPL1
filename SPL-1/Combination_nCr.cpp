#include<math.h>
int combination_nCr(int n,int r)
{
    double nf=tgamma(n+1);//factorial of n
    double rf=tgamma(r+1);//factorial of r
    double nrf=tgamma(n-r+1);//factorial of n-r

    return nf/(rf*nrf);
}
