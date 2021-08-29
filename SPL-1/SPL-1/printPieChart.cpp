#include<graphics.h>
#include"header.h"



void printPieChart(int *F,int n)
{
    initGraph("Pie Chart Window",0,0,-3,-3);
	//Printing message for user

	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	setcolor(LIGHTCYAN);
	outtextxy(600,5,"Pie Chart");//heading

	int TotalF=0;
	for(int i=0;i<n;i++)
    {
        TotalF += F[i];
    }


	//initilizing max x and y
	int  mx = getmaxx()/2;
	int  my = getmaxy()/2;

	//double MidPoint[n];
	double portions[n];
	int start_angle=0,end_angle;
	int colorCode=15;

	for(int i=0;i<n;i++)
    {
        //MidPoint[i]=UB[i]+LB[i]/2;
        portions[i]=0.5+((double)F[i]/(double)TotalF)*360.0;
        end_angle=start_angle +(int)portions[i];

        setfillstyle(WIDE_DOT_FILL,colorCode--);
        pieslice(mx, my, start_angle, end_angle, my-50);
        start_angle=end_angle;
        if(colorCode==1) colorCode=15;
    }

    settextstyle(1,HORIZ_DIR,2);
    outtextxy(mx+my+50,my-5,"Start Point");

	//making a back button
    rectangle(50,200,250,250);
    setcolor(RED);
    settextstyle(10,HORIZ_DIR,3);
    outtextxy(100,215,"  BACK");


    POINT position;
    int x1,y1;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x1 = position.x;
        y1 = position.y;

        if(x1>=50&&x1<=250 && y1>=200&&y1<=260)
        {
            closegraph();
            return;
        }
        else continue;
    }
}
