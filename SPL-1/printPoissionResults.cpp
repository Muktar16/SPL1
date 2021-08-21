#include"header.h"
#include<graphics.h>

void printPoissionResults(int n,float p,float u,int x,int sign,int type)
{
    //initialize a window for printing results
    initGraph("The result of Poission Distribution",0,0,-3,-3);
    setcolor(LIGHTMAGENTA);
    settextstyle(8,HORIZ_DIR,2);
    char tempStr[1000];
    float mean=u;
    float variance=u;
    float prob=0;
    int mode=(int)u;
    float sk=1/u;
    float kurt=3+1/u;


    if(sign==1)
    {
        prob=calculate_pois_dist_prob(u,x);//calculate probability
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Poission Distribution");
        outtext(tempStr);
        newLine();
        if(type==2)
        {
            sprintf(tempStr,"                                       for x=%d and u=%g",x,u);
            outtext(tempStr);
        }
        else
        {
            sprintf(tempStr,"                                       for n=%d, x=%d and p=%g",n,x,p);
            outtext(tempStr);
        }
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X = %d ) = %.5f",x,prob);
        outtext(tempStr);
    }
    else if(sign==2)
    {
        for(int i=0;i<x;i++)  prob+=calculate_pois_dist_prob(u,i);
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Poission Distribution ");
        outtext(tempStr);
        newLine();
        if(type==2)
        {
            sprintf(tempStr,"                                       for x<%d and u=%g",x,u);
            outtext(tempStr);
        }
        else
        {
            sprintf(tempStr,"                                       for n=%d, x<%d and p=%g",n,x,p);
            outtext(tempStr);
        }
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X < %d ) = %.5f",x,prob);
        outtext(tempStr);
    }
    else if(sign==3)
    {
        double prob=0;
        for(int i=0;i<=x;i++) prob+=calculate_pois_dist_prob(u,i);
        prob=1.0-prob;//as P(X>x) = 1 - P(X<=x)
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Poission Distribution ");
        outtext(tempStr);
        newLine();
        if(type==2)
        {
            sprintf(tempStr,"                                       for x>%d and u=%g",x,u);
            outtext(tempStr);
        }
        else
        {
            sprintf(tempStr,"                                       for n=%d, x>%d and p=%g",n,x,p);
            outtext(tempStr);
        }
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X > %d ) = %.5f",x,prob);
        outtext(tempStr);

    }
    else if(sign==4)
    {
        double prob=0;
        for(int i=0;i<=x;i++)   prob += calculate_pois_dist_prob(u,i);
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Poission Distribution ");
        outtext(tempStr);
        newLine();
        if(type==2)
        {
            sprintf(tempStr,"                                       for x<=%d and u=%g",x,u);
            outtext(tempStr);
        }
        else
        {
            sprintf(tempStr,"                                       for n=%d, x<=%d and p=%g",n,x,p);
            outtext(tempStr);
        }
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                       => P( X <= %d ) = %.5f",x,prob);
        outtext(tempStr);
    }
    else
    {
        double prob=0;
        for(int i=0;i<x;i++)   prob += calculate_pois_dist_prob(u,i);
        prob=1.0-prob;//as P(X>=x) = 1 - P(X<x)
        cleardevice();
        newLine();
        newLine();
        sprintf(tempStr,"                                       The result of Poission Distribution ");
        outtext(tempStr);
        newLine();
        if(type==2)
        {
            sprintf(tempStr,"                                       for x>=%d and u=%g",x,u);
            outtext(tempStr);
        }
        else
        {
            sprintf(tempStr,"                                       for n=%d, x>=%d and p=%g",n,x,p);
            outtext(tempStr);
        }
        newLine();
        newLine();
        newLine();
        setcolor(LIGHTCYAN);
        sprintf(tempStr,"                                        => P( X >= %d ) = %.5f",x,prob);
        outtext(tempStr);
    }


    //print mean
    newLine();
    newLine();
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
    if(u>mode)
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
            poison_distribution(type);
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
