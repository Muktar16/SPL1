#include"header.h"

void bio_dis()
{
    system("cls||clear");
    double x,p;
    int sign,n;
    cout<<"\n\n\n\n\t\t\t\t\t\t\tEnter the value for X: ";
    cin>>x;

    cout<<"\n\n\n\n\t\t\t\t\t\t\t1. X = "<<x<<"\n"
    <<"\t\t\t\t\t\t\t2. X > "<<x<<"\n"
    <<"\t\t\t\t\t\t\t3. X < "<<x<<"\n"
    <<"\t\t\t\t\t\t\t4. X >= "<<x<<"\n"
    <<"\t\t\t\t\t\t\t5. X <= "<<x<<"\n\n"
    <<"\t\t\t\t\t\t\tEnter a sign for X: ";
    cin>>sign;

    cout<<"\n\t\t\t\t\t\t\tEnter the value for n: ";
    cin>>n;
    cout<<"\n\n\t\t\t\t\t\t\tEnter the value for P: ";
    cin>>p;

    double mean=n*p;
    int b;
    double variance=n*p*(1-p);

    switch(sign)
    {
        case 1:
        {
            b=(factorial(n)*pow(p,x)*pow(1-p,n-x))/(factorial(x)*factorial(n-x));
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
            cout<<"b("<<x<<";"<<n<<","<<p<<") = "<<b;
            cout<<"Mean = "<<mean;
            cout<<"Variance = "<<variance;
        }
    }

}
