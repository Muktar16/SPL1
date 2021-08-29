#include<graphics.h>
#include<stdio.h>
#include"header.h"


void printOgive(double *LB,double* UB,int *F,int n)
{
    //initialize a window
    initGraph("Ogive Curve",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,5);//set font style, direction and size
    setcolor(10);

    outtextxy(400,5,"    Ogive");//heading

    setcolor(7);
    int cF[n];
    cF[-1]=0;
    double MidPoint[n];
    //calculating class midvalue and finding maximum frequency
    for(int i=0;i<n;i++)
    {
        cF[i]=F[i]+cF[i-1];
        MidPoint[i]=(LB[i]+UB[i])/2;
    }

    int xx1=GetSystemMetrics(SM_CXSCREEN)-450;//highet value of x axis
    int yy1=GetSystemMetrics(SM_CYSCREEN)-200;//highest value of y axis
    line(150, yy1, xx1, yy1);//x axis
    line(150, yy1, 150, 50);//y axis

    //per unit value on x axis and y axis
    double xunit=(xx1-200)/MidPoint[n-1];
    double yunit=(yy1-100)/cF[n-1];

    //(x,y)points to draw the graph
    double points[n][2];
    for(int i=0;i<n;i++)
    {
        points[i][0]=150+(MidPoint[i]*xunit);
        points[i][1]=yy1-(cF[i]*yunit);
    }

    //drawing the graph using the points
    char str[10];
    for(int i=0;i<n;i++)
    {
        //indicating the points with numbers
        settextstyle(8,VERT_DIR,1);
        snprintf(str,10,"%.2f",MidPoint[i]);
        outtextxy(points[i][0]-10,80+yy1,str);
        settextstyle(8,HORIZ_DIR,1);
        snprintf(str,10,"%d",cF[i]);
        outtextxy(105,points[i][1]-10,str);

        setcolor(LIGHTGREEN);
        circle(points[i][0],yy1,3);//indicating the points with dot(tiny circle)in x axis //(midpoints)
        circle(150,points[i][1],3);//indicating the points with dot(tiny circle)in y axis //(Frequency)

        //setting the points and lines of the graph
        circle(points[i][0],points[i][1],3);
        setcolor(LIGHTGRAY);
        if(i<n-1) line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
    }
    setcolor(7);
    outtextxy(120,yy1+10,"0");//(0,0) point of coordinate system

    //making a back button
    rectangle(xx1+50,300,xx1+250,350);
    setcolor(RED);
    settextstyle(10,HORIZ_DIR,3);
    outtextxy(xx1+100,315,"  BACK");


    POINT position;
    int x1,y1;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x1 = position.x;
        y1 = position.y;

        if(x1>=xx1+50&&x1<=xx1+250 && y1>=300&&y1<=360)
        {
            closegraph();
            break;
        }
        else continue;
    }
}

