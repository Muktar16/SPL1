#include"header.h"

void bio_dis()
{
    system("cls||clear");
    double p;
    int sign,x,n;
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\tEnter the value for X: ";
    scanf("%d",&x);

    while(1){
        cout<<"\n\n\n\n\t\t\t\t\t\t\t1. X = "<<x<<"\n"
        <<"\t\t\t\t\t\t\t2. X > "<<x<<"\n"
        <<"\t\t\t\t\t\t\t3. X < "<<x<<"\n"
        <<"\t\t\t\t\t\t\t4. X >= "<<x<<"\n"
        <<"\t\t\t\t\t\t\t5. X <= "<<x<<"\n\n"
        <<"\t\t\t\t\t\t\tSelect a sign for X: ";
        scanf("%d",&sign);
        if(sign>=1 && sign<=5) break;
        else{
            cout<<"Wrong Input!! Press Any key to try again.";
            _getch();
            system("cls||clear");
        }
    }


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
                system("cls||clear");
                b=(factorial(n)*pow(p,x)*pow(1-p,n-x))/(factorial(x)*factorial(n-x));
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x="<<x<<", n="<<n<<", and p="<<p<<endl;
                cout<<"\n\n\t\t\t\t\t\t\t";
                cout<<"=> b("<<x<<";"<<n<<","<<p<<") = "<<b;
                cout<<"\n\n\t\t\t\t\t\t\t=> Mean = "<<mean;
                cout<<"\n\t\t\t\t\t\t\t=> Variance = "<<variance;
                cout<<"\n\t\t\t\t\t\t\t=> Standard Deviation = "<<sqrt(variance);
                break;
            }
        case 2:
            {
                system("cls||clear");
                double Prob=0;
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x>"<<x<<", n="<<n<<", and p="<<p<<endl;
                for(int i=x+1;i<=n;i++)
                {
                    b=(factorial(n)*pow(p,i)*pow(1-p,n-i))/(factorial(i)*factorial(n-i));
                    Prob+=b;
                    cout<<"\n\t\t\t\t\t\t\t=> b("<<i<<";"<<n<<","<<p<<") = "<<b;
                }
                cout<<"\n\n\t\t\t\t\t\t\t=> P(x > "<<x<<" ) = "<<Prob;
                cout<<"\n\n\t\t\t\t\t\t\t=> Mean = "<<mean;
                cout<<"\n\t\t\t\t\t\t\t=> Variance = "<<variance;
                cout<<"\n\t\t\t\t\t\t\t=> Standard Deviation = "<<sqrt(variance);
                break;
            }
        case 3:
            {
                system("cls||clear");
                double Prob=0;
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x>"<<x<<", n="<<n<<", and p="<<p<<endl;
                for(int i=0;i<x;i++)
                {
                    b=(factorial(n)*pow(p,i)*pow(1-p,n-i))/(factorial(i)*factorial(n-i));
                    Prob+=b;
                    cout<<"\n\t\t\t\t\t\t\t=> b("<<i<<";"<<n<<","<<p<<") = "<<b;
                }
                cout<<"\n\n\t\t\t\t\t\t\t=> P(x > "<<x<<" ) = "<<Prob;
                cout<<"\n\n\t\t\t\t\t\t\t=> Mean = "<<mean;
                cout<<"\n\t\t\t\t\t\t\t=> Variance = "<<variance;
                cout<<"\n\t\t\t\t\t\t\t=> Standard Deviation = "<<sqrt(variance);
                break;
            }
        case 4:
            {

            }

    }

    cout<<"\n\n\n\t\t\t\t\t\tPress Any key to continue..........";
     _getch();

}
