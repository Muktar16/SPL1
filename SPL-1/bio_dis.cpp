#include"header.h"

void bio_dis()
{
    system("cls||clear");
    double p;
    int sign,x,n;
    cout<<"\n\n\n\n\t\t\t\t\t\t\tEnter the value for X: ";
    scanf("%d",&x);

    cout<<"\n\n\n\n\t\t\t\t\t\t\t1. X = "<<x<<"\n"
    <<"\t\t\t\t\t\t\t2. X > "<<x<<"\n"
    <<"\t\t\t\t\t\t\t3. X < "<<x<<"\n"
    <<"\t\t\t\t\t\t\t4. X >= "<<x<<"\n"
    <<"\t\t\t\t\t\t\t5. X <= "<<x<<"\n\n"
    <<"\t\t\t\t\t\t\tEnter a sign for X: ";
    scanf("%d",&sign);

    cout<<"\n\t\t\t\t\t\t\tEnter the value for n: ";
    scanf("%d",&n);
    cout<<"\n\n\t\t\t\t\t\t\tEnter the value for P: ";
    scanf("%lf",&p);

    double mean=n*p;
    double b;
    double variance=n*p*(1-p);


    switch(sign)
    {
        case 1:
            {
                b=(factorial(n)*pow(p,x)*pow(1-p,n-x))/(factorial(x)*factorial(n-x));
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
                cout<<"b("<<x<<";"<<n<<","<<p<<") = "<<b;
                cout<<"\n\n\t\t\t\t\t\t\t\tMean = "<<mean;
                cout<<"\n\t\t\t\t\t\t\t\tVariance = "<<variance;
                cout<<"\n\t\t\t\t\t\t\t\tStandard Deviation = "<<sqrt(variance);
            }
        case 2:
            {
                cout<<"\n\n\n\n";
                for(int i=x+1;i<=n;i++)
                {
                    b=(factorial(n)*pow(p,i)*pow(1-p,n-i))/(factorial(i)*factorial(n-i));
                    cout<<"\n\t\t\t\t\t\t\t\t b("<<i<<";"<<n<<","<<p<<") = "<<b<<"\n";
                }
                cout<<"\n\n\t\t\t\t\t\t\t\tMean = "<<mean;
                cout<<"\n\t\t\t\t\t\t\t\tVariance = "<<variance;
                cout<<"\n\t\t\t\t\t\t\t\tStandard Deviation = "<<sqrt(variance);
            }
        case 3:
            {

            }
        case 4:
            {

            }

    }

     _getch();

}
