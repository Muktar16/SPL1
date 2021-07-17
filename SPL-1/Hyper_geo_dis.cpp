
#include"header.h"

void Hyper_geo_dis()
{
    system("cls||clear");
    int n,N,k;
    double x;
    double h,mean,variance;
    char tempStr[500];

    //get the values for x,k,n,N
    cout<<"\nEnter the value for X: ";
    cin>>x;
    cout<<"\n\nEnter the value for N: ";
    cin>>N;
    cout<<"\n\nEnter the value for n: ";
    cin>>n;
    cout<<"\n\n\Enter the value for k: ";
    cin>>k;

    //calculation of probability(h)
    double kCx=combination_nCr(k,x);
    double N_kCn_X=combination_nCr(N-k,n-x);
    double NCn=combination_nCr(N,n);
    cout<<"\n"<<(kCx*N_kCn_X)/NCn;

}
