#include<math.h>


float hyperGeoProbCalculator(float N,float k,float n,float x)
{
    float f1,f2,f3,kCx,N_kCn_x,NCn;

    //calculation for the combination of k and x
    f1 = tgamma(k+1);//factorial of k
    f2 = tgamma(x+1);//factorial of k
    f3 = tgamma(k-x+1);//factorial of k-x
    kCx = f1/(f2*f3);//combination of k and x

    //calculation for the combination of N-k and n-x
    f1 = tgamma(N-k+1);//factorial of N-k
    f2 = tgamma(n-x+1);//factorial of n-x
    f3 = tgamma(N-k-n+x+1);//factorial of (N-k)-(n-x)
    N_kCn_x = f1/(f2*f3);//combination of N-k and n-x

    //calculation for the combination of N and n
    f1 = tgamma(N+1);//factorial of N
    f2 = tgamma(n+1);//factorial of n
    f3 = tgamma(N-n+1);//factorial of N-n
    NCn = f1/(f2*f3);//combination of N and n

    return (kCx*N_kCn_x)/NCn;
}

