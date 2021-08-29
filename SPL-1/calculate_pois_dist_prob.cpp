#include<math.h>

float calculate_pois_dist_prob(float u,int x)
{
    float xf=tgamma(x+1);//x factorial
    float e=exp(1);//e to the power 1
    return pow(u,x)*pow(e,-u)/xf;

}
