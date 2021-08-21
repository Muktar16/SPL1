#include<graphics.h>
#include"header.h"

void poison_distribution(int type)
{
    int x,n,sign;
    float u,p;//mu/lembda/mean
    char tempStr[1000];
    initGraph("Input for binomial distribution",0,0,-3,-3);
    moveto(0,0);
    newLine();
    newLine();
    setcolor(LIGHTGREEN);

    if(type==2)
    {
        //get the value of u
        outtext("         Enter the value for u (mean) : ");
        getGrString(tempStr);
        u=stod(tempStr);
        newLine();
        newLine();
    }
    else
    {
        //get the value of n
        outtext("         Enter the value for n : ");
        getGrString(tempStr);
        n=atoi(tempStr);
        newLine();
        newLine();

        //get the value of p
        outtext("         Enter the value for p : ");
        getGrString(tempStr);
        p=stod(tempStr);
        newLine();
        newLine();

        u=(float)n*p;
    }

    //get the value of X
    outtext("         Enter the value for x : ");
    getGrString(tempStr);
    x = atoi(tempStr);
    newLine();
    newLine();
    newLine();

    //making buttons for sign of X
    outtext("            Select a sign for x");
    int y=gety()+30;

    setcolor(LIGHTBLUE);
    rectangle(10,y,215,y+30);//button 1
    rectangle(10,y+50,215,y+80);//button 2
    rectangle(10,y+100,215,y+130);//button 3
    rectangle(10,y+150,215,y+180);//button 4
    rectangle(10,y+200,215,y+230);//button 5

    //texts of each buttons
    setcolor(GREEN);
    sprintf(tempStr,"X = %d",x);//button 1 text
    outtextxy(100,y+7,tempStr);
    sprintf(tempStr,"X < %d",x);//button 2 text
    outtextxy(100,y+57,tempStr);
    sprintf(tempStr,"X > %d",x);//button 3 text
    outtextxy(100,y+107,tempStr);
    sprintf(tempStr,"X <= %d",x);//button 4 text
    outtextxy(100,y+157,tempStr);
    sprintf(tempStr,"X >= %d",x);//button 5 text
    outtextxy(100,y+207,tempStr);
    newLine();
    newLine();

    //get cursor position and take action if button is pressed
    POINT position;
    int xx,yy;

    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000) GetCursorPos(&position);
        xx=position.x;
        yy=position.y;

        if(xx>=10&&xx<=205 && yy>=y&&yy<=y+40)
        {
            closegraph();
            //sign 1 means x = X selected
            sign=1;
            //print binomial distribution results for x = X
            printPoissionResults(u,x,sign,type);
            break;
        }

        else if(xx>=10&&xx<=205 && yy>=y+50&&yy<=y+90)
        {
            closegraph();
            //sign 2 means x < X selected
            sign=2;
            //print binomial distribution results for x < X
            printPoissionResults(u,x,sign,type);

            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+100&&yy<=y+140)
        {
            closegraph();
            //sign 3 means x > X selected
            sign=3;
            //print binomial distribution results for x > X
            printPoissionResults(u,x,sign,type);
            break;
        }
        else if(xx>=10&&xx<=205 && yy>=y+150&&yy<=y+190)
        {
            closegraph();
            //sign 4 means x <= X selected
            sign=4;
            //print binomial distribution results for x <= X
            printPoissionResults(u,x,sign,type);
            break;

        }
        else if(xx>=10&&xx<=205 && yy>=y+200&&yy<=y+240)
        {
            closegraph();
            //sign 5 means x >= X selected
            sign=5;
            //print binomial distribution results for x >= X
            printPoissionResults(u,x,sign,type);
            break;
        }
        else continue;
    }

}
