#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include"header.h"


void groupMenu()
{
    //initilizing a window to get input data
    initGraph("Getting input for grouped data",0,0,-3,-3);
    char tempString[100];
    moveto(0,0);
    newLine();
    setcolor(LIGHTGREEN);
    outtext("Enter Number of classes or Groups: ");
    getGrString(tempString);

    int n = atoi(tempString);
    double LB[n],UB[n];//LB=Lower Boundary, UB=Upper Boundary
    int F[n];//Frequency of each class
    int maxy = getmaxy();

    newLine();
    for(int i=0;i<n;i++)
    {
        char temp[20];
        if(gety()>=maxy-150)
        {
                cleardevice();
                moveto(0,0);
                newLine();
        }
        else
        {
                newLine();
                newLine();
        }

        sprintf(temp,"CLASS-%d:",i+1);
        outtext(temp);
        newLine();
        outtext("Enter Lower Boundery: ");
        getGrString(temp);
        LB[i]=atoi(temp);
        newLine();
        outtext("Enter Upper Boundery: ");
        getGrString(temp);
        UB[i]=atoi(temp);
        newLine();
        outtext("Frequency: ");
        getGrString(temp);
        F[i]=atoi(temp);

    }
    closegraph();


    while(1)
    {

        initGraph("Msin Menu Window",0,0,-3,-3);
        setcolor(LIGHTCYAN);
        settextstyle(BOLD_FONT,HORIZ_DIR,5);

        outtextxy(510,20,"CHOOSE AN OPTION");

        setcolor(8);
        rectangle(500,100,905,130);//Display frequency distribution table
        rectangle(500,160,905,190);//Display final results
        rectangle(500,220,905,280);//Display Frequency Distribution Table and Final Results
        rectangle(500,310,905,340);//Display Frequency Polygon
        rectangle(500,370,905,400);//Display ogive
        rectangle(500,430,905,460);//Display pie Chart
        rectangle(500,490,905,520);//Display Histogram
        rectangle(500,550,905,580);//Back to main menu
        rectangle(500,610,905,640);//Exit

        setcolor(LIGHTBLUE);
        settextstyle(BOLD_FONT,HORIZ_DIR,1);
        outtextxy(505,105,"Display Frequency Distribution Table");
        outtextxy(580,165,"Display final results");
        outtextxy(535,225,"Display Frequency Distribution");
        outtextxy(575,255,"table and Final Results");
        outtextxy(565,315,"Display Frequency Polygon");
        outtextxy(630,375,"Display Ogive");
        outtextxy(605,435,"Display pie Chart");
        outtextxy(605,495,"Display Histogram");
        outtextxy(605,555,"Back to Main Menu");
        setcolor(RED);
        outtextxy(685,615,"Exit");


        delay(500);
        POINT position;
        position.x=0;
        position.y=0;
        int x,y;

        while(1)
        {
            if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
            x = position.x;
            y = position.y;

            if(x>=500&&x<=905 && y>=100&&y<=140)
            {
                closegraph();
                system("cls||clear");
                printFDtable(LB,UB,F,n);
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=905 && y>=160&&y<=200)
            {
                closegraph();
                system("cls||clear");
                printf("\n\n\n\n\n\n\n\n\n");
                printFinalResults(LB,UB,F,n);
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=905 && y>=220&&y<=290)
            {
                closegraph();
                system("cls||clear");
                printFDtable(LB,UB,F,n);
                printf("\n\n\n");
                printFinalResults(LB,UB,F,n);
                cout<<"\n\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=905 && y>=310&&y<=350)
            {
                closegraph();
                system("cls||clear");
                printFrequencyPolygon(LB,UB,F,n);
                break;
            }
            else if(x>=500&&x<=905 && y>=370&&y<=410)
            {
                closegraph();
                system("cls||clear");
                printOgive(LB,UB,F,n);
                break;
            }
            else if(x>=500&&x<=905 && y>=430&&y<=470)
            {
                closegraph();
                system("cls||clear");
                printPieChart(F,n);
                break;

            }
            else if(x>=500&&x<=905 && y>=490&&y<=530)
            {
               closegraph();
               system("cls||clear");
               printHistogram(LB,UB,F,n);
               break;
            }
            else if(x>=500&&x<=905 && y>=550&&y<=590)
            {
               closegraph();
               system("cls||clear");
               main_menu();
               return;
            }

            else if(x>=500&&x<=905 && y>=610&&y<=650)
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
    return;
}
