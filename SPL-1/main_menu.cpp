#include<graphics.h>
#include"header.h"


void main_menu()
{
    initGraph("Main Menu Window",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,5);

    setcolor(3);
    outtextxy(300,5,"Welcome to Statistical Analyzer");
    setcolor(5);
    outtextxy(580,80,"MAIN MENU");
    outtextxy(560,110,"-----------");


    settextstyle(10,HORIZ_DIR,3);
    setcolor(8);
    //making buttons for each option
    rectangle(220,170,600,220);//UNGROUPED DATA
    rectangle(220,270,600,320);//GROUPED DATA
    rectangle(220,370,600,450);//UNGROUPED TO GROUPED DATA CONVERTER
    rectangle(780,170,1160,220);//REGRESSION & CO-RELATION
    rectangle(780,270,1160,320);//PROBABILITY DISTRIBUTION
    rectangle(780,380,1160,430);//FORMULA SHEETS
    rectangle(780,500,1160,550);//EXIT

    setcolor(6);
    //text of buttons
    outtextxy(300,185,"UNGROUPED DATA");
    outtextxy(315,285,"GROUPED DATA");
    outtextxy(255,385,"UNGROUPED TO GROUPED");
    outtextxy(295,415,"DATA CONVERTER");
    outtextxy(810,185,"REGRESSION & CO-RELATION");
    outtextxy(800,285,"PROBABILITY DISTRIBUTION");
    outtextxy(880,395,"FORMULA SHEETS");
    setcolor(RED);
    outtextxy(930,515,"EXIT");


    int x=0,y=0;
    while(1)
    {

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
        }


        if(x>=220&&x<=600 && y>=170&&y<=230)
        {
            closegraph();
            unGroupMenu();
            break;
        }
        else if(x>=220&&x<=600 && y>=270&&y<=330)
        {
            closegraph();
            groupMenu();
            break;
        }
        else if(x>=220&&x<=600 && y>=370&&y<=460)
        {
            closegraph();
            unGroupToGroupMenu();
            break;
        }
        else if(x>=780&&x<=1160 && y>=170&&y<=230)
        {
            closegraph();
            CoRelationAndRegressionMenu();
            break;
        }
        else if(x>=780&&x<=1160 && y>=270&&y<=330)
        {
            closegraph();
            probabilityMenu();
            break;
        }
        else if(x>=780&&x<=1160 && y>=380&&y<=440)
        {
            closegraph();
            formulaSheetsMenu();
            break;
        }
        else if(x>=780&&x<=1160 && y>=500&&y<=560)
        {
            cleardevice();
            settextstyle(BOLD_FONT,HORIZ_DIR,5);
            setcolor(LIGHTGREEN);
            outtextxy(getmaxx()/2-150,getmaxy()/2,"THANK YOU");
            delay(2000);
            closegraph();
            exit(0);
        }
        else
        {
            continue;
        }
    }

}
