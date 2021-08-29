#include<graphics.h>
#include"header.h"

void printNegBinoResults(int r,float p,int X,int sign)
{
    //initialize a window for printing results
    initGraph("The result of Negative Binomial Distribution",0,0,-3,-3);
    setcolor(LIGHTMAGENTA);
    settextstyle(8,HORIZ_DIR,2);
    char tempStr[1000];
    float q=1-p;
    float mean=(r*q)/p;
    float prob=0;
    float variance=(r*q)/(p*p);
    float sk=((1+q)*(1+q))/(r*q);//skewness
    float kurt = (1+4*q+q*q)/(r*q);//kurtosis


    if(sign==1)
    {
        prob=calculate_neg_bino_prob(r,X,p);//calculate probability
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of negative Binomial Distribution ");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X=%d, r=%d, and p=%g",X,r,p);
        outtext(tempStr);
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X = %d ) = %0.4f",X,prob);
        outtext(tempStr);
    }
    else if(sign==2)
    {
        for(int i=r;i<X;i++)  prob+=calculate_neg_bino_prob(r,i,p);//calculate probability
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of negative Binomial Distribution ");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X<%d, r=%d, and p=%g",X,r,p);
        outtext(tempStr);
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X < %d ) = %g",X,prob);
        outtext(tempStr);
    }
    else if(sign==3)
    {
        double prob=0;
        for(int i=r;i<=X;i++) prob+=calculate_neg_bino_prob(r,i,p);//calculate P(X<=x)
        prob=1.0-prob;//as P(X>x) = 1-P(X=<x)
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of negative Binomial Distribution");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X>%d, r=%d, and p=%g",X,r,p);
        outtext(tempStr);
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X > %d ) = %g",X,prob);
        outtext(tempStr);

    }
    else if(sign==4)
    {
        double prob=0;
        for(int i=r;i<=X;i++)   prob += calculate_neg_bino_prob(r,i,p);//calculate probability
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of negative Binomial Distribution");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X<=%d, r=%d, and p=%g",X,r,p);
        outtext(tempStr);
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X <= %d ) = %g",X,prob);
        outtext(tempStr);
    }
    else
    {
        double prob=0;
        for(int i=r;i<X;i++)   prob += calculate_neg_bino_prob(r,i,p);//calculate probability
        prob=1.0-prob;//as P(X>=x) = 1-P(X<x)
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of negative Binomial Distribution");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X>=%d, r=%d, and p=%g",X,r,p);
        outtext(tempStr);
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                        => P( X >= %d ) = %g",X,prob);
        outtext(tempStr);
    }


    //print mean,variance and standard deviation
    newLine();
    newLine();
    sprintf(tempStr,"                                       => Mean = %g",mean);
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"                                       => Variance = %g",variance);
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"                                       => Standard Deviation = %g",sqrt(variance));
    outtext(tempStr);
    newLine();

    //print skewness
    sprintf(tempStr,"                                       => Skewness (Beta 1) = %g (always positively skewed)",sk);
    outtext(tempStr);
    newLine();
    //print kurtosis(Beta 2)
    sprintf(tempStr,"                                       => Kurtosis (Beta 2) = %g (always leptokurtic)",kurt);
    outtext(tempStr);
    newLine();

    //print coefficient of skewness and kurtosis
    sprintf(tempStr,"                                       => coefficient of skewness = %g",sqrt(sk));
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"                                       => coefficient of kurtosis = %g",kurt-3);
    outtext(tempStr);
    newLine();


    //make 3 buttons with rectangle
    int y1=gety()+100;
    setcolor(DARKGRAY);
    rectangle(550,y1,765,y1+30);
    rectangle(550,y1+50,765,y1+80);
    rectangle(550,y1+100,765,y1+130);
    //button text
    setcolor(LIGHTRED);
    outtextxy(555,y1+5,"ANOTHER OPERATION");
    outtextxy(555,y1+55,"      BACK");
    outtextxy(555,y1+105,"      EXIT");

    //get cursor position and take action if button is pressed
    POINT position;
    int xx,yy;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        xx = position.x;
        yy = position.y;

        if(xx>=550&&xx<=765 && yy>=y1&&yy<=y1+40)
        {
            closegraph();
            neg_bio_dis();
            break;
        }
        else if(xx>=550&&xx<=765 && yy>=y1+50&&yy<=y1+90)
        {
            closegraph();
            probabilityMenu();
            break;
        }
        else if(xx>=550&&xx<=765 && yy>=y1+100&&yy<=y1+140)
        {
            cleardevice();
            settextstyle(BOLD_FONT,HORIZ_DIR,5);
            setcolor(LIGHTGREEN);
            outtextxy(getmaxx()/2-150,getmaxy()/2,"THANK YOU");
            delay(2000);
            exit(0);
        }
        else continue;
    }

}
