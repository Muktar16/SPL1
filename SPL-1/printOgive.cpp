#include "header.h"
#include<graphics.h>

void printOgive(double *LB,double* UB,int *F,int n)
{
    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);

    initwindow(heightOfScreen,widthOfScreen,"Frequency Polygon",-3,-3);
    settextstyle(10,HORIZ_DIR,5);

    setcolor(10);
    outtextxy(450,20,"Ogive");
    setcolor(7);

    line(150, 650, 150, 50);//yaxis
    settextstyle(10,VERT_DIR,2);
    setcolor(4);
    outtextxy(20,500,"Cumulative Frequendy");

    line(150, 650, 950, 650);//x axis
    settextstyle(10,HORIZ_DIR,5);
    outtextxy(120,660,"0");

    int cF[n];//cumulative frequency
    double MidPoint[n];//class midvalue
    cF[0]=F[0];
    MidPoint[0]=(LB[0]+UB[0])/2;


    for(int i=1;i<n;i++)
    {
        cF[i]=F[i]+cF[i-1];
        MidPoint[i]=(LB[i]+UB[i])/2;
    }

    double xunit=750/MidPoint[n-1];
    double yunit=550/cF[n-1];

    //(x,y)points to draw the graph
    double points[n][2];
    for(int i=0;i<n;i++)
    {
        points[i][0]=150+(MidPoint[i]*xunit);
        points[i][1]=650-cF[i]*yunit;
    }


    char str[10];
    for(int i=0;i<n;i++)
    {
        //indicating the points with dot(tiny circle)in x axis //(midpoints)
        snprintf(str,10,"%.2f",MidPoint[i]);
        settextstyle(8,VERT_DIR,1);
        //setcolor(3);
        outtextxy(points[i][0]-10,735,str);
        circle(points[i][0],650,5);

        //indicating the points with dot(tiny circle)in y axis //(Frequency)
        snprintf(str,10,"%d",cF[i]);
        settextstyle(8,HORIZ_DIR,1);
        outtextxy(105,points[i][1]-10,str);
        circle(150,points[i][1],5);

        //setting the points and lines of the graph
        //setcolor(6);
        circle(points[i][0],points[i][1],5);
        if(i<n-1) line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
    }


}
