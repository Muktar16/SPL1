#include"header.h"
#include<graphics.h>
void formulaSheetsMenu()
{
    while(1)
    {

        initGraph("Options",0,0,-3,-3);
        setcolor(LIGHTCYAN);
        settextstyle(BOLD_FONT,HORIZ_DIR,5);

        outtextxy(450,20,"FORMULA SHEETS MENU");

        setcolor(6);
        //buttons for options
        rectangle(500,100,800,140);//UNGROUPED DATA
        rectangle(500,170,800,210);//GROUPED DATA
        rectangle(500,240,800,280);//REGRESSION & CO-RELATION
        rectangle(500,310,800,350);//PROBABILITY DISTRIBUTION
        rectangle(500,380,800,420);//ACK TO MAIN MENU
        rectangle(500,450,800,490);//EXIT


        setcolor(LIGHTBLUE);
        //button texts
        settextstyle(BOLD_FONT,HORIZ_DIR,2);
        outtextxy(505,110,"      UNGROUPED DATA");
        outtextxy(505,180,"      GROUPED DATA");
        outtextxy(505,250,"REGRESSION & CO-RELATION");
        outtextxy(505,320,"PROBABILITY DISTRIBUTION");
        outtextxy(505,390,"    BACK TO MAIN MENU");
        setcolor(RED);
        outtextxy(505,460,"          EXIT");


        POINT position;
        position.x=0;
        position.y=0;
        int x,y;

        while(1)
        {
            if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
            x = position.x;
            y = position.y;

            if(x>=500&&x<=800 && y>=100&&y<=150)
            {
                closegraph();
                initGraph("Grouped Data Formula",870,850,300,0);
                readimagefile("ungroupedData.jpg",0,0,870,830);
                settextstyle(8,HORIZ_DIR,2);
                setbkcolor(WHITE);
                setcolor(LIGHTRED);
                outtextxy(250,780,"Press Any Key to get Back........");
                getch();
                closegraph();
                break;
            }
            else if(x>=500&&x<=800 && y>=170&&y<=220)
            {
                closegraph();
                initGraph("Grouped Data Formula",870,850,300,0);
                readimagefile("groupedData.jpg",0,0,870,830);
                settextstyle(8,HORIZ_DIR,2);
                setbkcolor(WHITE);
                setcolor(LIGHTRED);
                outtextxy(250,780,"Press Any Key to get Back........");
                getch();
                break;
            }
            else if(x>=500&&x<=800 && y>=240&&y<=290)
            {
                closegraph();
                initGraph("Grouped Data Formula",870,850,300,0);
                readimagefile("correlation.jpg",0,0,870,830);
                settextstyle(8,HORIZ_DIR,2);
                setbkcolor(WHITE);
                setcolor(LIGHTRED);
                outtextxy(250,780,"Press Any Key to get Back........");
                getch();
                closegraph();
                break;
            }
            else if(x>=500&&x<=800 && y>=310&&y<=360)
            {
                closegraph();

                initGraph("Grouped Data Formula",0,0,-3,-3);
                int x = getmaxx();
                int y = getmaxy();
                readimagefile("probability.jpg",0,0,x,y);
                settextstyle(8,HORIZ_DIR,2);
                setbkcolor(WHITE);
                setcolor(LIGHTRED);
                outtextxy(450,800,"Press Any Key to get Back........");
                getch();
                closegraph();
                break;
            }
            else if(x>=500&&x<=800 && y>=380&&y<=430)
            {
                closegraph();
                return;
                break;
            }
            else if(x>=500&&x<=800 && y>=450&&y<=500)
            {
                cleardevice();
                settextstyle(BOLD_FONT,HORIZ_DIR,5);
                setcolor(LIGHTGREEN);
                outtextxy(getmaxx()/2-150,getmaxy()/2,"THANK YOU");
                delay(2000);
                closegraph();
                exit(0);
                break;

            }
            else
            {
                continue;
            }
        }
    }

}
