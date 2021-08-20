#include"header.h"
#include<graphics.h>

void Hyper_geo_dis()
{
    int n,N,k,x,x1,y1;
    double h,mean,variance;
    char tempStr[500];

    initGraph("Hyper Geometric Distribution input window",0,0,-3,-3);
    moveto(0,0);
    newLine();
    newLine();
    setcolor(11);
    //get the values for x,k,n,N
    outtext("   Enter the value for X: ");
    getGrString(tempStr);
    x=atoi(tempStr);
    newLine();
    newLine();
    outtext("   Enter the value for N: ");
    getGrString(tempStr);
    N = atoi(tempStr);
    newLine();
    newLine();
    outtext("   Enter the value for n: ");
    getGrString(tempStr);
    n = atoi(tempStr);
    newLine();
    newLine();
    outtext("   Enter the value for k: ");
    getGrString(tempStr);
    k = atoi(tempStr);
    closegraph();

    //calculation of probability (denoted by h)
    double kCx=combination_nCr(k,x);
    double N_kCn_X=combination_nCr(N-k,n-x);
    double NCn=combination_nCr(N,n);
    h = (kCx*N_kCn_X)/NCn;
    //mean calculation
    mean=n*k/N;
    //variance calculation
    variance = n*k*(N-k)*(N-n)/N*N*(N-1);
    //displaying results
    initGraph("Result of hyper geometric distribution",0,0,-3,-3);
    moveto(0,0);
    setcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    newLine();

    sprintf(tempStr,"The result of HyperGeometric distribution for");
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"X = %d, N = %d, n = %d and k = %d",x,N,n,k);
    outtext(tempStr);
    newLine();
    newLine();
    newLine();

    setcolor(LIGHTMAGENTA);
    sprintf(tempStr,"-> h(%d;%d,%d,%d) = %g",x,N,n,k,h);
    outtext(tempStr);
    newLine();
    newLine();

    sprintf(tempStr,"-> Mean = %g",mean);
    outtext(tempStr);
    newLine();
    newLine();

    sprintf(tempStr,"-> Variance = %g",variance);
    outtext(tempStr);

    //get the button position
    y1=gety()+100;



    //make 3 buttons with rectangle
    setcolor(DARKGRAY);
    rectangle(50,y1,265,y1+30);
    rectangle(50,y1+50,265,y1+80);
    rectangle(50,y1+100,265,y1+130);
    //button text
    setcolor(LIGHTRED);
    settextstyle(10,HORIZ_DIR,2);
    outtextxy(60,y1+5,"ANOTHER OPERATION");
    outtextxy(125,y1+55,"BACK");
    outtextxy(125,y1+105,"EXIT");

    //get cursor position and take action if button is pressed
    POINT position;
    int xx,yy;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        xx = position.x;
        yy = position.y;

        if(xx>=50&&xx<=265 && yy>=y1&&yy<=y1+40)
        {
            closegraph();
            Hyper_geo_dis();
            break;
        }
        else if(xx>=50&&xx<=265 && yy>=y1+50&&yy<=y1+90)
        {
            closegraph();
            probabilityMenu();
            break;
        }
        else if(xx>=50&&xx<=265 && yy>=y1+100&&yy<=y1+140)
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
