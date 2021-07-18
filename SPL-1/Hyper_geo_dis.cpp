#include"header.h"
#include<graphics.h>

void Hyper_geo_dis()
{
    system("cls||clear");
    int n,N,k,x,x1,y1;
    double h,mean,variance;
    char tempStr[500];

    //get the values for x,k,n,N
    cout<<"\nEnter the value for X: ";
    cin>>x;
    cout<<"\n\nEnter the value for N: ";
    cin>>N;
    cout<<"\n\nEnter the value for n: ";
    cin>>n;
    cout<<"\n\nEnter the value for k: ";
    cin>>k;

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
    sprintf(tempStr,"-> h(%d;%d,%d,%d) = %.4f",x,N,n,k,h);
    outtext(tempStr);
    newLine();
    newLine();

    sprintf(tempStr,"-> Mean = %.4f",mean);
    outtext(tempStr);
    newLine();
    newLine();

    sprintf(tempStr,"-> Variance = %.4f",variance);
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
            break;
        }
        else if(xx>=50&&xx<=265 && yy>=y1+100&&yy<=y1+140)
        {
            closegraph();
            exit(0);
            break;
        }
        else continue;
    }
}
