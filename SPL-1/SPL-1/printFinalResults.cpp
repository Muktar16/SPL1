
#include"header.h"
using namespace std;

void printFinalResults(double* LB,double *UB,int* F,int n)
{
    int N=0;
    for(int i=0;i<n;i++)
    {
        N+=F[i];
    }
    printf("\n\t\t\t\t\t\t\t-> NUMBER OF CLASSES  = %d",n);
    printf("\n\t\t\t\t\t\t\t-> TOTAL FREQUENCY    = %d",N);
    printf("\n\t\t\t\t\t\t\t-> 1st QUARTILE       = %.2lf",group_median_calculator(LB,UB,F,n,1));
    printf("\n\t\t\t\t\t\t\t-> 3rd QUARTILE       = %.2lf",group_median_calculator(LB,UB,F,n,3));
    printf("\n");

    double mean = group_mean_calculator(LB,UB,F,n);
    printf("\n\t\t\t\t\t\t\t-> MEAN (AVERAGE)     = %.2lf",mean);
    printf("\n\t\t\t\t\t\t\t-> GEOMETRIC MEAN     = %.2lf",group_gmean_calculator(LB,UB,F,n));
    printf("\n\t\t\t\t\t\t\t-> HARMONIC MEAN      = %.2lf",group_hmean_calculator(LB,UB,F,n));
    double median = group_median_calculator(LB,UB,F,n,2);
    printf("\n\t\t\t\t\t\t\t-> MEDIAN             = %.2lf",median);
    printf("\n\t\t\t\t\t\t\t-> MODE               = %.2lf",group_mode_calculator(LB,UB,F,n));
    printf("\n");

    double variance = group_variance_calculator(LB,UB,F,n);
    printf("\n\t\t\t\t\t\t\t-> VARIANCE           = %.2lf",variance);
    printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION = %.2lf",sqrt(variance));
    printf("\n");
    if(variance==0)
    {
        printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF VARIANCE             = 0");
        printf("\n\t\t\t\t\t\t\t-> PEARSON'S COEFFICIENT OF SKEWNESS   = NaN");
    }
    else
    {
        double CV = (sqrt(variance)/mean)*100;
        double PCS = (3*(mean-median))/sqrt(variance);
        printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF VARIANCE             = %.2lf",CV); cout<<"%";
        printf("\n\t\t\t\t\t\t\t-> PEARSON'S COEFFICIENT OF SKEWNESS   = %.2lf",PCS);
    }

}
