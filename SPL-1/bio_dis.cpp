#include"header.h"
#include<graphics.h>

void bio_dis()
{
    int X,n;
    float p;
    char tempStr[1000];
    initGraph("Input for binomial distribution",0,0,-3,-3);
    moveto(0,0);
    newLine();
    newLine();
    setcolor(GREEN);

    //get the value of n
    outtext("         Enter the value for n: ");
    getGrString(tempStr);
    n=atoi(tempStr);
    newLine();
    newLine();
    //get the value of p
    outtext("         Enter the value for P: ");
    getGrString(tempStr);
    p=stof(tempStr);
    newLine();
    newLine();


    //getting the value for X
    outtext("         Enter the value for X: ");
    getGrString(tempStr);
    X = atoi(tempStr);
    newLine();
    newLine();
    newLine();
    //making buttons for sign of X
    outtext("            Select a sign for X");
    int y=gety()+30;

    setcolor(LIGHTBLUE);
    rectangle(10,y,215,y+30);//button 1
    rectangle(10,y+50,215,y+80);//button 2
    rectangle(10,y+100,215,y+130);//button 3
    rectangle(10,y+150,215,y+180);//button 4
    rectangle(10,y+200,215,y+230);//button 5
    //button texts
    setcolor(GREEN);
    sprintf(tempStr,"X = %d",X);//button 1 text
    outtextxy(100,y+7,tempStr);
    sprintf(tempStr,"X < %d",X);//button 2 text
    outtextxy(100,y+57,tempStr);
    sprintf(tempStr,"X > %d",X);//button 3 text
    outtextxy(100,y+107,tempStr);
    sprintf(tempStr,"X <= %d",X);//button 4 text
    outtextxy(100,y+157,tempStr);
    sprintf(tempStr,"X >= %d",X);//button 5 text
    outtextxy(100,y+207,tempStr);
    newLine();
    newLine();



    float mean=n*p;
    float b;
    float variance=n*p*(1-p);

    //get cursor position and take action if button is pressed
    POINT position;
    int xx,yy;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        xx = position.x;
        yy = position.y;

        if(xx>=10&&xx<=205 && yy>=y&&yy<=y+40)
        {
            cleardevice();
            setcolor(WHITE_PEN);
            b=calculate_b(n,X,p);
            newLine();
            newLine();
            sprintf(tempStr,"The result of Binomial Distribution for x=%d, n=%d, and p=%.2f",X,n,p);
            outtext(tempStr);
            newLine();
            newLine();
            newLine();
            sprintf(tempStr,"=> b(%d; %d, %.2f) = %.2f",X,n,p,b);
            outtext(tempStr);
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+50&&yy<=y+90)
        {
            //closegraph();
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+100&&yy<=y+140)
        {
//            closegraph();
//            exit(0);
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+150&&yy<=y+190)
        {
            //closegraph();
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+200&&yy<=y+240)
        {
            closegraph();
            exit(0);
            break;
        }
        else continue;
    }


    getch();


//    system("cls||clear");
//    double p;
//    int sign,x,n;
//    cout<<"\n\n\n\n\n\t\t\t\t\t\t\tEnter the value for X: ";
//    scanf("%d",&x);
//
//    while(1){
//        cout<<"\n\n\n\n\t\t\t\t\t\t\t1. X = "<<x<<"\n"
//        <<"\t\t\t\t\t\t\t2. X > "<<x<<"\n"
//        <<"\t\t\t\t\t\t\t3. X < "<<x<<"\n"
//        <<"\t\t\t\t\t\t\t4. X >= "<<x<<"\n"
//        <<"\t\t\t\t\t\t\t5. X <= "<<x<<"\n\n"
//        <<"\t\t\t\t\t\t\tSelect a sign for X: ";
//        scanf("%d",&sign);
//        if(sign>=1 && sign<=5) break;
//        else{
//            cout<<"Wrong Input!! Press Any key to try again.";
//            _getch();
//            system("cls||clear");
//        }
//    }
//
//
//    cout<<"\n\t\t\t\t\t\t\tEnter the value for n: ";
//    scanf("%d",&n);
//    cout<<"\n\n\t\t\t\t\t\t\tEnter the value for P: ";
//    scanf("%lf",&p);
//
//    double mean=n*p;
//    double b;
//    double variance=n*p*(1-p);
//
//
//    switch(sign)
//    {
//        case 1:
//            {
//                system("cls||clear");
//                b=calculate_b(n,x,p);
//                //b=(factorial(n)*pow(p,x)*pow(1-p,n-x))/(factorial(x)*factorial(n-x));
//                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x="<<x<<", n="<<n<<", and p="<<p<<endl;
//                cout<<"\n\n\t\t\t\t\t\t\t";
//                cout<<"=> b("<<x<<";"<<n<<","<<p<<") = "<<b;
//                break;
//            }
//        case 2:
//            {
//                system("cls||clear");
//                double Prob=0;
//                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x>"<<x<<", n="<<n<<", and p="<<p<<endl;
//                for(int i=x+1;i<=n;i++)
//                {
//                    b=calculate_b(n,i,p);
//                    Prob+=b;
//                    cout<<"\n\t\t\t\t\t\t\t=> b("<<i<<";"<<n<<","<<p<<") = "<<b;
//                }
//                cout<<"\n\n\t\t\t\t\t\t\t=> P(x > "<<x<<") = "<<Prob;
//                break;
//            }
//        case 3:
//            {
//                system("cls||clear");
//                double Prob=0;
//                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x<"<<x<<", n="<<n<<", and p="<<p<<endl;
//                for(int i=0;i<x;i++)
//                {
//                    b=calculate_b(n,i,p);
//                    //b=(factorial(n)*pow(p,i)*pow(1-p,n-i))/(factorial(i)*factorial(n-i));
//                    Prob+=b;
//                    cout<<"\n\t\t\t\t\t\t\t=> b("<<i<<";"<<n<<","<<p<<") = "<<b;
//                }
//                cout<<"\n\n\t\t\t\t\t\t\t=> P(x < "<<x<<") = "<<Prob;
//                break;
//            }
//        case 4:
//            {
//                system("cls||clear");
//                double Prob=0;
//                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x>="<<x<<", n="<<n<<", and p="<<p<<endl;
//                for(int i=x;i<=n;i++)
//                {
//                    b=calculate_b(n,i,p);
//                    //b=(factorial(n)*pow(p,i)*pow(1-p,n-i))/(factorial(i)*factorial(n-i));
//                    Prob+=b;
//                    cout<<"\n\t\t\t\t\t\t\t=> b("<<i<<";"<<n<<","<<p<<") = "<<b;
//                }
//                cout<<"\n\n\t\t\t\t\t\t\t=> P(x >= "<<x<<") = "<<Prob;
//                break;
//            }
//
//            case 5:
//            {
//                system("cls||clear");
//                double Prob=0;
//                cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThe result of Binomial Distribution for x<="<<x<<", n="<<n<<", and p="<<p<<endl;
//                for(int i=0;i<=x;i++)
//                {
//                    b=calculate_b(n,i,p);
//                    //b=(factorial(n)*pow(p,i)*pow(1-p,n-i))/(factorial(i)*factorial(n-i));
//                    Prob+=b;
//                    cout<<"\n\t\t\t\t\t\t\t=> b("<<i<<";"<<n<<","<<p<<") = "<<b;
//                }
//                cout<<"\n\n\t\t\t\t\t\t\t=> P(x <= "<<x<<") = "<<Prob;
//
//                break;
//            }
//
//    }
//    cout<<"\n\n\t\t\t\t\t\t\t=> Mean = "<<mean;
//    cout<<"\n\t\t\t\t\t\t\t=> Variance = "<<variance;
//    cout<<"\n\t\t\t\t\t\t\t=> Standard Deviation = "<<sqrt(variance);
//
//    cout<<"\n\n\n\t\t\t\t\t\tPress Any key to continue..........";
//     _getch();

}
