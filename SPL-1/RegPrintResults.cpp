#include"header.h"
#include<graphics.h>

void RegPrintResults(double *X,double *Y,double *XY,int n)
{
    double r,a,b;
    double N = (double)n;
    char buffer[500];
    int i,x1,y1;

    double sumX = sum(X,n);
    double sumY = sum(Y,n);
    double sumX2 = sum_square(X,n);
    double sumY2 = sum_square(Y,n);
    double sumXY = sum(XY,n);
    double meanX = mean_calculator(X,n);
    double meanY = mean_calculator(Y,n);
    double varianceX = variance_calculator(X,n);
    double varianceY = variance_calculator(Y,n);
    double sdX = sqrt(varianceX);
    double sdY = sqrt(varianceY);
    r = ((N*sumXY)-sumX*sumY)/sqrt((N*sumX2-sumX*sumX)*(N*sumY2-sumY*sumY));
    //calculate a b
    double temp1=0,temp2=0;
    for(int i=0;i<n;i++)
    {
        temp1+=(X[i]-meanX)*(Y[i]-meanY);
        temp2+=(X[i]-meanX)*(X[i]-meanX);
    }
    b = temp1/temp2;
    a = meanY - b*meanX;

    initGraph("Results of Co-realtion and Regration",0,0,-3,-3);
    setcolor(LIGHTBLUE);
    settextstyle(8,HORIZ_DIR,1);
    moveto(0,10);

    //print Class X
    outtext("-> CLASS X  =  ");
    int xx=getx();
    int maxx = getmaxx();
    for(i=0;i<n; i++)
    {
        if(X[i]==(int)X[i]) sprintf(buffer,"%d  ",(int)X[i]);
        else sprintf(buffer,"%.2f  ",X[i]);
        outtext(buffer);

        if(getx()>=maxx-100)
        {
            newLine();
            moveto(xx,gety());
        }
    }
    newLine();
    //print class Y
    outtext("-> CLASS Y  =  ");
    for(i=0;i<n; i++)
    {
        if(Y[i]==(int)Y[i]) sprintf(buffer,"%d  ",(int)Y[i]);
        else sprintf(buffer,"%.2f  ",Y[i]);
        outtext(buffer);

        if(getx()>=maxx-100)
        {
            newLine();
            moveto(xx,gety());
        }
    }

    newLine();
    newLine();
    setcolor(YELLOW);
    //print sample size sumX,sumY, sumXY,sum of X squared , sum of Y squared
    sprintf(buffer,"-> SAMPLE SIZE     = %d",n);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> SUM OF X        = %.2lf",sumX);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> SUM OF Y        = %.2lf",sumY);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> SUM OF XY       = %.2lf",sumXY);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> SUM OF SQUARE X = %.2lf",sumX2);
    x1=getx()+600;//store current position to make buttons
    y1=gety();
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> SUM OF SQUARE Y = %.2lf",sumY2);
    outtext(buffer);
    newLine();
    newLine();

    setcolor(LIGHTGREEN);
    //print mean,variance and standard deviation of both X and Y
    sprintf(buffer,"-> MEAN OF X                = %.2lf",meanX);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> MEAN OF Y                = %.2lf",meanY);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> VARIANCE OF X            = %.2lf",varianceX);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> VARIANCE OF Y            = %.2lf",varianceY);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> STANDARD DEVIATION OF X  = %.2lf",sdX);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> STANDARD DEVIATION OF Y  = %.2lf",sdY);
    outtext(buffer);
    newLine();
    newLine();


    setcolor(LIGHTCYAN);
    //print others
    sprintf(buffer,"-> COEFFICIENT OF CORRELATION(r) = %.2lf",r);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> COEFFICIENT OF DETERMINATION  = %.2lf%%",r*r*100.0);
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> SIGNIFICANCE TEST VALUE       = %.2lf",r*(sqrt((n-2)/(1-r*r))));
    outtext(buffer);
    newLine();
    sprintf(buffer,"-> STANDARD ERROR SLOPE VALUE    = %.2lf",(sqrt(1-r*r)*sdY)/(sqrt(n-2)*sdX));
    outtext(buffer);
    newLine();
    newLine();

    setcolor(LIGHTMAGENTA);
    sprintf(buffer,"-> Equation of y on x:\n\t\t\t\t\t\t\t    Y = %.2lf + (%.2lf)X",a,b);
    outtext(buffer);
    newLine();


    setcolor(DARKGRAY);
    rectangle(x1,y1,x1+205,y1+30);
    rectangle(x1,y1+50,x1+205,y1+80);
    rectangle(x1,y1+100,x1+205,y1+130);
    rectangle(x1,y1+150,x1+205,y1+180);
    setcolor(LIGHTRED);
    outtextxy(x1+10,y1+5,"SCATTERED DIAGRAM");
    outtextxy(x1+10,y1+55,"ANOTHER OPERATION");
    outtextxy(x1+75,y1+105,"BACK");
    outtextxy(x1+75,y1+155,"EXIT");

    POINT position;
    int x,y;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x = position.x;
        y = position.y;

        if(x>=x1&&x<=x1+205 && y>=y1&&y<=y1+40)
        {
            closegraph();
            printScatterDiagram(X,Y,n,r);
            break;
        }
        else if(x>=x1&&x<=x1+205 && y>=y1+50&&y<=y1+90)
        {
            closegraph();
            CoRelationAndRegressionMenu();
            break;
        }
        else if(x>=x1&&x<=x1+205 && y>=y1+100&&y<=y1+140)
        {
            closegraph();
            main_menu();
            break;
        }
        else if(x>=x1&&x<=x1+205 && y>=y1+150&&y<=y1+190)
        {
            closegraph();
            exit(0);
            break;
        }
        else continue;
    }


//    printf("\n\n\n");
//    for(int i=0;i<n;i++)
//    {
//        printf("\n\t\t\t\t\t\t\t-> XY%d = (%.2lf , %.2lf)",i+1,X[i],Y[i]);
//    }
//    printf("\n");
//
//    printf("\n\t\t\t\t\t\t\t-> SAMPLE SIZE     = %d",n);
//    printf("\n\t\t\t\t\t\t\t-> SUM OF X        = %.2lf",sumX);
//    printf("\n\t\t\t\t\t\t\t-> SUM OF Y        = %.2lf",sumY);
//    printf("\n\t\t\t\t\t\t\t-> SUM OF XY       = %.2lf",sumXY);
//    printf("\n\t\t\t\t\t\t\t-> SUM OF SQUARE X = %.2lf",sumX2);
//    printf("\n\t\t\t\t\t\t\t-> SUM OF SQUARE Y = %.2lf",sumY2);
//    printf("\n");
//
//    printf("\n\t\t\t\t\t\t\t-> MEAN OF X                = %.2lf",meanX);
//    printf("\n\t\t\t\t\t\t\t-> MEAN OF Y                = %.2lf",meanY);
//    printf("\n\t\t\t\t\t\t\t-> VARIANCE OF X            = %.2lf",varianceX);
//    printf("\n\t\t\t\t\t\t\t-> VARIANCE OF Y            = %.2lf",varianceY);
//    printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION OF X  = %.2lf",sdX);
//    printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION OF Y  = %.2lf",sdY);
//    printf("\n");
//
//    printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF CORRELATION(r) = %.2lf",r);
//    printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF DETERMINATION  = %.0lf",r*r*100); cout<<"%";
//    printf("\n\t\t\t\t\t\t\t-> SIGNIFICANCE TEST VALUE       = %.2lf",r*(sqrt((n-2)/(1-r*r))));
//    //printf("\n\t\t\t\t\t\t\t-> STANDARD ERROR SLOPE VALUE    = %.2lf",sb1_calculator(X,Y,n));
//    printf("\n\t\t\t\t\t\t\t-> STANDARD ERROR SLOPE VALUE    = %.2lf",(sqrt(1-r*r)*sdY)/(sqrt(n-2)*sdX));
//    printf("\n");
//
//    printf("\n\t\t\t\t\t\t\t-> Equation of y on x:\n\t\t\t\t\t\t\t    Y = %.2lf + (%.2lf)X",a,b);

}
