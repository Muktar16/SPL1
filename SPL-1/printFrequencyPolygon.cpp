
#include<stdio.h>
#include"header.h"
#include<graphics.h>
using namespace std;


void printFrequencyPolygon(double *LB,double* UB,int *F,int n)
{
    initGraph("Frequency Polygon",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,5);

    setcolor(10);
    outtextxy(400,5,"Freguency Polygon");
    setcolor(7);

    int y,maxF=0;
    double MidPoint[n];
    for(int i=0;i<n;i++)
    {
        if(maxF<F[i]) maxF = F[i];
        MidPoint[i]=(LB[i]+UB[i])/2;
    }

    int xx1=GetSystemMetrics(SM_CXSCREEN)-450;
    int yy1=GetSystemMetrics(SM_CYSCREEN)-200;

//    line(150, 650, 950, 650);//x axis
//    line(150, 650, 150, 50);//yaxis
    line(150, yy1, xx1, yy1);//x axis
    line(150, yy1, 150, 50);//yaxis



    double xunit=(xx1-200)/MidPoint[n-1];
    double yunit=(yy1-100)/maxF;

    //(x,y)points to draw the graph
    double points[n][2];
    for(int i=0;i<n;i++)
    {
        points[i][0]=150+(MidPoint[i]*xunit);
        points[i][1]=yy1-F[i]*yunit;
    }

    char str[10];
    for(int i=0;i<n;i++)
    {
        //indicating the points with dot(tiny circle)in x axis //(midpoints)
        snprintf(str,10,"%.2f",MidPoint[i]);
        settextstyle(8,VERT_DIR,1);
        setcolor(LIGHTGREEN);
        outtextxy(points[i][0]-10,735,str);
        circle(points[i][0],yy1,3);

        //indicating the points with dot(tiny circle)in y axis //(Frequency)
        snprintf(str,10,"%d",F[i]);
        settextstyle(8,HORIZ_DIR,1);
        outtextxy(105,points[i][1]-10,str);
        circle(150,points[i][1],3);

        //setting the points and lines of the graph
        //setcolor(6);
        setcolor(LIGHTGREEN);
        circle(points[i][0],points[i][1],3);
        if(i<n-1) line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
    }
    setcolor(GREEN);
    outtextxy(120,660,"0");//(0,0) point of coordinate system

    //making a exit button
    rectangle(1000,300,1200,350);
    setcolor(RED);
    settextstyle(10,HORIZ_DIR,3);
    outtextxy(1030,315,"Exit Graph");

    POINT position;
    int x1,y1;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x1 = position.x;
        y1 = position.y;

        if(x1>=1000&&x1<=1200 && y1>=300&&y1<=360)
        {
            closegraph();
            break;
        }
        else continue;
    }




//     initGraph("Frequency Polygon",0,0,-3,-3);
//    settextstyle(10,HORIZ_DIR,5);
//
//    setcolor(10);
//    outtextxy(400,20,"Freguency Polygon");
//    setcolor(7);
//
//    int y,maxF=0;
//    double MidPoint[n];
//    for(int i=0;i<n;i++)
//    {
//        if(maxF<F[i]) maxF = F[i];
//        MidPoint[i]=(LB[i]+UB[i])/2;
//    }
//
//    int xx1=GetSystemMetrics(SM_CXSCREEN)-450;
//    int yy1=GetSystemMetrics(SM_CYSCREEN)-200;
//
//    line(150, yy1, xx1, yy1);//x axis
//    line(150, yy1, 150, 50);//yaxis
//
//
//    double xunit=(xx1-150)/MidPoint[n-1];
//    double yunit=yy1-50/maxF;
//
//    //(x,y)points to draw the graph
//    double points[n][2];
//    for(int i=0;i<n;i++)
//    {
//        points[i][0]=150+(MidPoint[i]*xunit);
//        points[i][1]=yy1-(F[i]*yunit);
//    }
//
//    char str[10];
//    for(int i=0;i<n;i++)
//    {
//        //indicating the points with dot(tiny circle)in x axis //(midpoints)
////        snprintf(str,10,"%.2f",MidPoint[i]);
////        settextstyle(8,VERT_DIR,1);
////        outtextxy(points[i][0]-10,735,str);
////        circle(points[i][0],650,5);
//
//        //indicating the points with dot(tiny circle)in y axis //(Frequency)
////        snprintf(str,10,"%d",F[i]);
////        settextstyle(8,HORIZ_DIR,1);
////        outtextxy(105,points[i][1]-10,str);
////        circle(150,points[i][1],5);
//
//        //setting the points and lines of the graph
//        //setcolor(6);
//        circle(points[i][0],points[i][1],5);
//        if(i<n-1) line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
//    }
//    setcolor(GREEN);
//    outtextxy(120,660,"0");//(0,0) point of coordinate system
//
//    //making a exit button
//    rectangle(1000,300,1200,350);
//    setcolor(RED);
//    settextstyle(10,HORIZ_DIR,3);
//    outtextxy(1030,315,"Exit Graph");
//
//    POINT position;
//    int x1,y1;
//    while(1)
//    {
//        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
//        x1 = position.x;
//        y1 = position.y;
//
//        if(x1>=1000&&x1<=1200 && y1>=300&&y1<=360)
//        {
//            closegraph();
//            break;
//        }
//        else continue;
//    }



//    int y,maxF=0;
//    system("cls||clear");
//    double MidPoint[n];
//    for(int i=0;i<n;i++)
//    {
//        if(maxF<F[i]) maxF = F[i];
//        MidPoint[i]=(LB[i]+UB[i])/2;
//    }
//
//    printf("\n\n");
//    printf("\n\t\t\t\t\t\t\t============================");
//    printf("\n\t\t\t\t\t\t\t      FREQUENCY POLYGON");
//    printf("\n\t\t\t\t\t\t\t============================");
//
//    printf("\n\n\n\n\n");
//    for(y=maxF;y>=0;y--)
//    {
//        printf("\t\t\t\t\t\t\t%4d |      ",y);
//        for(int i=0;i<n;i++)
//        {
//            if(F[i]==y) printf("*       ");
//            else printf("        ");
//        }
//        printf("\n");
//        if(maxF<=30) printf("\t\t\t\t\t\t\t     |\n");
//    }
//    printf("\t\t\t\t\t\t\t    ");
//    for(int i=0;i<n;i++)
//    {
//        printf("------------");
//    }
//    printf("\n\t\t\t\t\t\t\t\t    ");
//    for(int i=0;i<n;i++)
//    {
//        printf("%4.2lf   ",MidPoint[i]);
//    }
}
