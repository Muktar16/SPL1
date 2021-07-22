#include"header.h"
#include<graphics.h>

void printScatterDiagram(double* X,double *Y,int n,double r)
{
    //initialize a window
    initGraph("Scatter Diagram",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,5);//set font style, direction and size
    setcolor(10);

    outtextxy(400,5,"Scattered Diagram");//heading

    setcolor(7);
    double maxX=0;
    double maxY=0;
    //finding maximum X and maximum Y
    for(int i=0;i<n;i++)
    {
        if(maxX<X[i]) maxX = X[i];
        if(maxY<Y[i]) maxY = Y[i];
    }

    int xx1=GetSystemMetrics(SM_CXSCREEN)-450;//highest value of x axis
    int yy1=GetSystemMetrics(SM_CYSCREEN)-150;//highest value of y axis
    line(150, yy1, xx1, yy1);//x axis
    line(150, yy1, 150, 50);//y axis

    //per unit value on x axis and y axis
    double xunit=(xx1-200)/maxX;
    double yunit=(yy1-100)/maxY;

    //(x,y)points to draw the graph
    double points[n][2];
    for(int i=0;i<n;i++)
    {
        points[i][0]=150+(X[i]*xunit);
        points[i][1]=yy1-(Y[i]*yunit);
    }

    //drawing the graph using the points
    char str[10];
    for(int i=0;i<n;i++)
    {
        //indicating the points with numbers
        setcolor(LIGHTBLUE);
        settextstyle(8,VERT_DIR,1);
        snprintf(str,10,"%.2f",X[i]);
        outtextxy(points[i][0]-10,80+yy1,str);
        settextstyle(8,HORIZ_DIR,1);
        snprintf(str,10,"%.2f",Y[i]);
        outtextxy(50,points[i][1]-10,str);

        circle(points[i][0],yy1,3);//indicating the points with dot(tiny circle)in x axis
        circle(150,points[i][1],3);//indicating the points with dot(tiny circle)in y axis

        //setting the points and lines of the graph
        setcolor(YELLOW);
        circle(points[i][0],points[i][1],3);
    }
    setcolor(LIGHTBLUE);
    outtextxy(115,yy1+10,"0");//(0,0) point of coordinate system
    //print degree of correlation
    setcolor(LIGHTMAGENTA);
    outtextxy(xx1+80,50,"Degree of Co-relation:");

    if(r==-1)   outtextxy(xx1+80,100,"Perfect Negative");
    else if(r>-1 && r<=-0.75)   outtextxy(xx1+80,100,"High Degree Negative");
    else if(r>-0.75 && r<=-0.25)   outtextxy(xx1+80,100,"Moderately Negative");
    else if(r>-0.25 && r<0.0)   outtextxy(xx1+80,100,"Low Degree Negative");
    else if(r==0.0)   outtextxy(xx1+80,100,"No Co-relation");
    else if(r>0.0 && r<=0.25)   outtextxy(xx1+80,100,"Low Degree Negative");
    else if(r>0.25 && r<=0.75)   outtextxy(xx1+80,100,"Moderately Positive");
    else if(r>0.75 && r<1)   outtextxy(xx1+80,100,"High Degree positive");
    else if(r==1)   outtextxy(xx1+80,100,"Perfect Positive");

    //making a back button
    setcolor(LIGHTGREEN);
    rectangle(xx1+80,500,xx1+280,550);
    setcolor(RED);
    settextstyle(10,HORIZ_DIR,3);
    outtextxy(xx1+140,515," BACK");


    POINT position;
    int x1,y1;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x1 = position.x;
        y1 = position.y;

        if(x1>=xx1+80&&x1<=xx1+280 && y1>=500&&y1<=560)
        {
            closegraph();
            break;
        }
        else continue;
    }

}
