#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
using namespace std;


void printFrequencyPolygon(double *LB,double* UB,int *F,int n)
{

    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);

    initwindow(heightOfScreen,widthOfScreen,"Frequency Polygon",-3,-3);
    settextstyle(10,HORIZ_DIR,5);

    setcolor(10);
    outtextxy(400,20,"Freguency Polygon");
    setcolor(7);

    int y,maxF=0;
    double MidPoint[n];
    for(int i=0;i<n;i++)
    {
        if(maxF<F[i]) maxF = F[i];
        MidPoint[i]=(LB[i]+UB[i])/2;
    }

    line(150, 650, 950, 650);//x axis
    line(150, 650, 150, 50);//yaxis
    outtextxy(120,660,"0");

    double xunit=750/MidPoint[n-1];
    double yunit=550/maxF;

    //(x,y)points to draw the graph
    double points[n][2];
    for(int i=0;i<n;i++)
    {
        points[i][0]=150+(MidPoint[i]*xunit);
        points[i][1]=650-F[i]*yunit;
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
        snprintf(str,10,"%d",F[i]);
        settextstyle(8,HORIZ_DIR,1);
        outtextxy(105,points[i][1]-10,str);
        circle(150,points[i][1],5);

        //setting the points and lines of the graph
        //setcolor(6);
        circle(points[i][0],points[i][1],5);
        if(i<n-1) line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
    }


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
