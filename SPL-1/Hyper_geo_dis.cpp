#include"header.h"
#include<graphics.h>

void Hyper_geo_dis()
{
    float n,N,k,x;
    int x1,y1;
    float h,mean,variance;
    char tempStr[500];

    initGraph("Hyper Geometric Distribution input window",0,0,-3,-3);
    moveto(0,0);
    newLine();
    newLine();
    setcolor(11);
    //get the values for x,k,n,N
    outtext("   Enter the value for X: ");
    getGrString(tempStr);
    x=stod(tempStr);
    newLine();
    newLine();
    outtext("   Enter the value for N: ");
    getGrString(tempStr);
    N = stod(tempStr);
    newLine();
    newLine();
    outtext("   Enter the value for n: ");
    getGrString(tempStr);
    n = stod(tempStr);
    newLine();
    newLine();
    outtext("   Enter the value for k: ");
    getGrString(tempStr);
    k = stod(tempStr);
    closegraph();

    //calculation of probability (denoted by h)
    h = hyperGeoProbCalculator(N,k,n,x);
    float p = (float)k/(float)N;
    mean=n*k/N;
    variance = (n*k*(N-k)*(N-n))/(N*N*(N-1));


    //displaying results
    initGraph("Result of hyper geometric distribution",0,0,-3,-3);
    moveto(0,0);
    setcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    newLine();

    sprintf(tempStr,"                                   The result of HyperGeometric distribution for");
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"                                   X = %g, N = %g, n = %g and k = %g",x,N,n,k);
    outtext(tempStr);
    newLine();
    newLine();
    newLine();

    setcolor(LIGHTMAGENTA);
    sprintf(tempStr,"                                   -> h(%g;%g,%g,%g) = %g",x,N,n,k,h);
    outtext(tempStr);
    newLine();
    newLine();
    //print mean
    sprintf(tempStr,"                                   -> Mean = %g",mean);
    outtext(tempStr);
    newLine();
    //variance
    sprintf(tempStr,"                                   -> Variance = %g",variance);
    outtext(tempStr);
    newLine();
    //standard deviation
    sprintf(tempStr,"                                   -> Standard deviation = %g",sqrt(variance));
    outtext(tempStr);
    newLine();
    //print value of p
    if(p==0.5)
    {
        sprintf(tempStr,"                                   -> Value of p = %g (symmetrical)",p);
        outtext(tempStr);
        newLine();
    }
    else if(p<0.5)
    {
        sprintf(tempStr,"                                   -> Value of p = %g (positively skewed)",p);
        outtext(tempStr);
        newLine();
    }
    else
    {
        sprintf(tempStr,"                                   -> Value of p = %g (negatively skewed)",p);
        outtext(tempStr);
        newLine();
    }

    //get the button position
    y1=gety()+100;
    //make 3 buttons with rectangle
    setcolor(DARKGRAY);
    rectangle(550,y1,765,y1+30);
    rectangle(550,y1+50,765,y1+80);
    rectangle(550,y1+100,765,y1+130);
    //button text
    setcolor(LIGHTRED);
    settextstyle(10,HORIZ_DIR,2);
    outtextxy(560,y1+5,"ANOTHER OPERATION");
    outtextxy(560,y1+55,"       BACK");
    outtextxy(560,y1+105,"       EXIT");

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
            Hyper_geo_dis();
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
            closegraph();
            exit(0);
        }
        else continue;
    }
}
