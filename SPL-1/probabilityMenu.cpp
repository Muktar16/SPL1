#include"header.h"
#include<graphics.h>

void probabilityMenu()
{
    initGraph("Main Menu Window",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,5);

    setcolor(5);
    outtextxy(350,40,"PROBABILITY DISTRIBUTION MENU");
    outtextxy(330,70,"-------------------------------");

    //make buttons with rectangle for various options
    setcolor(6);
    rectangle(220,170,600,220);//BINOMIAL DISTRIBUTION
    rectangle(220,270,600,320);//POISSION DISTRIBUTION(P given)
    rectangle(220,380,600,430);//POISSION DISTRIBUTION(u given)
    rectangle(220,500,600,550);//GEOMETRIC DISTRIBUTION
    rectangle(780,170,1160,220);//NEGATIVE BINOMIAL DISTRIBUTION
    rectangle(780,270,1160,320);//Hyper-GEOMETRIC DISTRIBUTION
    rectangle(780,380,1160,430);//BACK TO MAIN MENU
    rectangle(780,500,1160,550);//EXIT

    setcolor(8);
    settextstyle(10,HORIZ_DIR,2);
    outtextxy(290,185,"BINOMIAL DISTRIBUTION");
    outtextxy(235,285,"POISSION DISTRIBUTION(P given)");
    outtextxy(235,395,"POISSION DISTRIBUTION(u given)");
    outtextxy(280,515,"GEOMETRIC DISTRIBUTION");
    outtextxy(790,185,"NEGATIVE BINOMIAL DISTRIBUTION");
    outtextxy(800,285,"Hyper-GEOMETRIC DISTRIBUTION");
    outtextxy(870,395,"BACK TO MAIN MENU");
    setcolor(RED);
    outtextxy(940,515,"EXIT");


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

        if(x>=220&&x<=600 && y>=170&&y<=230)
        {
            closegraph();
            bio_dis();
            break;
        }
        else if(x>=220&&x<=600 && y>=270&&y<=330)
        {
            closegraph();
            //pois_dis_p_given();
            break;
        }
        else if(x>=220&&x<=600 && y>=380&&y<=440)
        {
            closegraph();
            //pois_disU();
            break;
        }
        else if(x>=220&&x<=600 && y>=500&&y<=560)
        {
            closegraph();
            //geo_dis();
            break;
        }
        else if(x>=780&&x<=1160 && y>=170&&y<=230)
        {
            closegraph();
            neg_bio_dis();
            break;
        }
        else if(x>=780&&x<=1160 && y>=270&&y<=330)
        {
            closegraph();
            Hyper_geo_dis();
            break;
        }
        else if(x>=780&&x<=1160 && y>=380&&y<=440)
        {
            closegraph();
            main_menu();
            break;
        }
        else if(x>=780&&x<=1160 && y>=500&&y<=560)
        {
            closegraph();
            int height=250,width=400;
            initwindow(width,height,"Exiting",500,200);
            settextstyle(8,HORIZ_DIR,3);
            outtextxy(140,100,"THANK YOU");
            delay(5000);

        }
        else
        {
            continue;
        }

    }

}
