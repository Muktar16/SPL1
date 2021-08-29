#include<graphics.h>
#include"header.h"

void printHistogram(double *LB,double *UB,int *F,int n)
{
    //initialize a window
    initGraph("Histogram/Bar diagram window",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,5);
    setcolor(10);
    outtextxy(400,5,"Histogram(Bar Diagram)");//heading


    //calculating class mid-value and finding maximum frequency
    int maxF=0;
    double MidPoint[n];
    for(int i=0;i<n;i++)
    {
        if(maxF<F[i]) maxF = F[i];
        MidPoint[i]=(LB[i]+UB[i])/2;
    }

    int yy1=getmaxy()-200;//highest value of y axis
    int xx1=getmaxx();

    //per unit value on y axis
    double yunit=(yy1-100)/maxF;

    int rect_width;//width of a bar
    if(n<=10) rect_width=80;
    else if(n>10 && n<=20) rect_width=55;
    else if(n>20) rect_width = 35;

    //finding all y value for each frequency
    double points[n];
    for(int i=0;i<n;i++)
    {
        points[i]=yy1-(F[i]*yunit);
    }

    //drawing the Histogram
    char str[10];
    int tmp=getmaxx()/2 - (50+(n/2)*rect_width);
    int colorcode=2;
    for(int i=0;i<n;i++)
    {
        setcolor(GREEN);
        rectangle(tmp,points[i],tmp+rect_width,yy1);
        setfillstyle(SOLID_FILL,colorcode++);
        floodfill(tmp+1,points[i]+1,GREEN);
        //print Frequencies on top of each bar
        settextstyle(8,HORIZ_DIR,1);

        snprintf(str,10,"%d",F[i]);
        outtextxy(tmp+rect_width/2,points[i]-25,str);
        //print midpoints on root of the bar
        settextstyle(8,VERT_DIR,1);
        snprintf(str,10,"%.2f",MidPoint[i]);
        outtextxy(tmp+rect_width/2,yy1+75,str);

        tmp+=rect_width;
        if(colorcode==15) colorcode=2;

    }


    //making a back button
    rectangle(xx1-150,50,xx1-50,100);
    setcolor(RED);
    settextstyle(10,HORIZ_DIR,3);
    outtextxy(xx1-130,65,"BACK");

    POINT position;
    int x1,y1;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x1 = position.x;
        y1 = position.y;

        if(x1>=xx1-150&&x1<=xx1-50 && y1>=50&&y1<=110)
        {
            closegraph();
            break;
        }
        else continue;
    }

}
