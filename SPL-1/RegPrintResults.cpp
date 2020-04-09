#include"header.h"

void RegPrintResults(double *X,double *Y,double *XY,int n)
{
    double r,a,b;
    double N = (double)n;

    double sumX = sum(X,n);
    double sumY = sum(Y,n);
    double sumX2 = sum_square(X,n);
    double sumY2 = sum_square(Y,n);
    double sumXY = sum(XY,n);
    double meanX = mean_calculator(X,n);
    double meanY = mean_calculator(Y,n);
    double varianceX = variance_calculator(X,n);
    double varianceY = variance_calculator(Y,n);
    double sdX = sqrt(varianceX);
    double sdY = sqrt(varianceY);
    r = ((N*sumXY)-sumX*sumY)/sqrt((N*sumX2-sumX*sumX)*(N*sumY2-sumY*sumY));
    //calculate a b
    double temp1=0,temp2=0;
    for(int i=0;i<n;i++)
    {
        temp1+=(X[i]-meanX)*(Y[i]-meanY);
        temp2+=(X[i]-meanX)*(X[i]-meanX);
    }
    b = temp1/temp2;
    a = meanY - b*meanX;

    printf("\n\n\n");
    for(int i=0;i<n;i++)
    {
        printf("\n\t\t\t\t\t\t\t-> XY%d = (%.2lf , %.2lf)",i+1,X[i],Y[i]);
    }
    printf("\n");

    printf("\n\t\t\t\t\t\t\t-> SAMPLE SIZE     = %d",n);
    printf("\n\t\t\t\t\t\t\t-> SUM OF X        = %.2lf",sumX);
    printf("\n\t\t\t\t\t\t\t-> SUM OF Y        = %.2lf",sumY);
    printf("\n\t\t\t\t\t\t\t-> SUM OF XY       = %.2lf",sumXY);
    printf("\n\t\t\t\t\t\t\t-> SUM OF SQUARE X = %.2lf",sumX2);
    printf("\n\t\t\t\t\t\t\t-> SUM OF SQUARE Y = %.2lf",sumY2);
    printf("\n");

    printf("\n\t\t\t\t\t\t\t-> MEAN OF X                = %.2lf",meanX);
    printf("\n\t\t\t\t\t\t\t-> MEAN OF Y                = %.2lf",meanY);
    printf("\n\t\t\t\t\t\t\t-> VARIANCE OF X            = %.2lf",varianceX);
    printf("\n\t\t\t\t\t\t\t-> VARIANCE OF Y            = %.2lf",varianceY);
    printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION OF X  = %.2lf",sdX);
    printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION OF Y  = %.2lf",sdY);
    printf("\n");

    printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF CORRELATION(r) = %.2lf",r);
    printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF DETERMINATION  = %.0lf",r*r*100); cout<<"%";
    printf("\n\t\t\t\t\t\t\t-> SIGNIFICANCE TEST VALUE       = %.2lf",r*(sqrt((n-2)/(1-r*r))));
    //printf("\n\t\t\t\t\t\t\t-> STANDARD ERROR SLOPE VALUE    = %.2lf",sb1_calculator(X,Y,n));
    printf("\n\t\t\t\t\t\t\t-> STANDARD ERROR SLOPE VALUE    = %.2lf",(sqrt(1-r*r)*sdY)/(sqrt(n-2)*sdX));
    printf("\n");

    printf("\n\t\t\t\t\t\t\t-> Equation of y on x:\n\t\t\t\t\t\t\t    Y = %.2lf + (%.2lf)X",a,b);

}
