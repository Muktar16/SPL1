#include"header.h"
#include<graphics.h>

void printBinoResults(int n,float p,int X,int sign)
{
    //initialize a window for printing results
    initGraph("The result of Binomial Distribution",0,0,-3,-3);
    setcolor(LIGHTMAGENTA);
    settextstyle(8,HORIZ_DIR,2);
    char tempStr[1000];

    //calculations
    float prob=0;
    float q=1-p;
    float mean=n*p;
    float variance=n*p*q;
    float fmode=(n+1)*p;
    int mode=int(fmode);
    float sk = (1-2*p)/(n*p*q);//skewness
    float kurt = 3 + (1-6*p*q)/(n*p*q);//kurtosis


    if(sign==1)
    {
        prob=calculate_b(n,X,p);//calculate probability
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Binomial Distribution ");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X=%d, n=%d, and p=%g",X,n,p);
        outtext(tempStr);
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X = %d ) = %g",X,prob);
        outtext(tempStr);
    }
    else if(sign==2)
    {
        for(int i=0;i<X;i++)  prob+=calculate_b(n,i,p);
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Binomial Distribution ");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X<%d, n=%d, and p=%g",X,n,p);
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
        for(int i=X+1;i<=n;i++) prob+=calculate_b(n,i,p);
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Binomial Distribution");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X>%d, n=%d, and p=%g",X,n,p);
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
        for(int i=0;i<=X;i++)   prob += calculate_b(n,i,p);
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Binomial Distribution");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X<=%d, n=%d, and p=%g",X,n,p);
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
        for(int i=X;i<=n;i++)   prob += calculate_b(n,i,p);
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Binomial Distribution");
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"                                       for X>=%d, n=%d, and p=%g",X,n,p);
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
    //print mean
    sprintf(tempStr,"                                       => Mean = %g",mean);
    outtext(tempStr);
    newLine();
    //print variance
    sprintf(tempStr,"                                       => Variance = %g",variance);
    outtext(tempStr);
    newLine();
    //print standard deviation
    sprintf(tempStr,"                                       => Standard Deviation = %g",sqrt(variance));
    outtext(tempStr);
    newLine();
    //print mode
    if(fmode>mode)
    {
        sprintf(tempStr,"                                       => Mode = %d (Unimodal)",mode);
        outtext(tempStr);
        newLine();
    }
    else
    {
        sprintf(tempStr,"                                       => Mode = %d and %d (Bimodal)",mode-1,mode);
        outtext(tempStr);
        newLine();
    }

    //print skewness
    if(sk==0)
    {
        sprintf(tempStr,"                                       => Skewness (Beta-1) = %g (Symmetric distribution)",sk);
        outtext(tempStr);
        newLine();
    }
    else if(sk>0)
    {
        sprintf(tempStr,"                                       => Skewness (Beta-1) = %g (Positively skewed)",sk);
        outtext(tempStr);
        newLine();
    }
    else
    {
        sprintf(tempStr,"                                       => Skewness (Beta-1) = %g (Negatively skewed)",sk);
        outtext(tempStr);
        newLine();
    }

    //print kurtosis(Beta 2)
    if(kurt==3)
    {
        sprintf(tempStr,"                                       => Kurtosis (Beta-2) = %g (Mesokurtic)",kurt);
        outtext(tempStr);
        newLine();
    }
    else if(kurt>3)
    {
        sprintf(tempStr,"                                       => Kurtosis (Beta-2) = %g (Leptokurtic)",kurt);
        outtext(tempStr);
        newLine();
    }
    else
    {
        sprintf(tempStr,"                                       => Kurtosis (Beta-2) = %g (Platykurtic)",kurt);
        outtext(tempStr);
        newLine();
    }
    //print coefficient of skewness and kurtosis
    sprintf(tempStr,"                                       => coefficient of skewness (gamma-1) = %g",sqrt(sk));
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"                                       => coefficient of kurtosis (gamma-2) = %g",kurt-3);
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
            binomial_distribution();
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
