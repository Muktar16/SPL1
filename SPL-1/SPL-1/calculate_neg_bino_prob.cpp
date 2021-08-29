#include<math.h>

float calculate_neg_bino_prob(int r,int X,float P)
{
    float prob;//probability
    float xf=1;//X-1 factorial
    float rf=1;//r-1 factorial
    float xrf=1;//(X-1)-(r-1) factorial
    float X_1Cr_1=1;//X-1Cr-1(combination)

    //calculation
    xf=tgamma(X);//X-1 factorial
    rf=tgamma(r);//r-1 factorial
    xrf=tgamma((X-1)-(r-1)+1);//(X-1)-(r-1) factorial
    X_1Cr_1=xf/(rf*xrf);//X-1Cr-1
    prob=X_1Cr_1*pow(P,r)*pow(1-P,X-r);//negative binomial distribution using formula

    return prob;

}
