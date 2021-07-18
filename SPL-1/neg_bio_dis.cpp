#include<graphics.h>
#include"header.h"

void neg_bio_dis()
{
    int X,r;
    float p;
    char tempStr[100];
    initGraph("Input for negative binomial distribution",0,0,-3,-3);
    moveto(0,0);
    newLine();
    newLine();
    setcolor(WHITE_PEN);
    //getting the value for X
    outtext("Enter the value for X: ");
    getGrString(tempStr);
    X = atoi(tempStr);
    newLine();
    newLine();
    newLine();
    //making buttons for sign of X
    outtext("            Select a sign for X");
    int y=gety()+30;

    setcolor(LIGHTBLUE);
    rectangle(10,y,215,y+30);//button 1
    rectangle(10,y+50,215,y+80);//button 2
    rectangle(10,y+100,215,y+130);//button 3
    rectangle(10,y+150,215,y+180);//button 4
    rectangle(10,y+200,215,y+230);//button 5
    //button texts
    setcolor(GREEN);
    sprintf(tempStr,"X = %d",X);//button 1 text
    outtextxy(100,y+7,tempStr);
    sprintf(tempStr,"X < %d",X);//butt0n 2 text
    outtextxy(100,y+57,tempStr);
    sprintf(tempStr,"X > %d",X);//button 3 text
    outtextxy(100,y+107,tempStr);
    sprintf(tempStr,"X <= %d",X);//button 4 text
    outtextxy(100,y+157,tempStr);
    sprintf(tempStr,"X >= %d",X);//button 5 text
    outtextxy(100,y+207,tempStr);

    //get cursor position and take action if button is pressed
    POINT position;
    int xx,yy;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        xx = position.x;
        yy = position.y;

        if(xx>=10&&xx<=205 && yy>=y&&yy<=y+40)
        {
//            closegraph();
//            Hyper_geo_dis();
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+50&&yy<=y+90)
        {
            //closegraph();
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+100&&yy<=y+140)
        {
//            closegraph();
//            exit(0);
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+150&&yy<=y+190)
        {
            //closegraph();
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+200&&yy<=y+240)
        {
            closegraph();
            exit(0);
            break;
        }
        else continue;
    }

}
