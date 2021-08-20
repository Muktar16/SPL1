#include"header.h"
#include<graphics.h>

void probabilityMenu()
{
    initGraph("Probability Menu Window",0,0,-3,-3);
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


    int x=0,y=0;

    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN)) getmouseclick(WM_LBUTTONDOWN,x,y);


        if(x>=220&&x<=600 && y>=170&&y<=230)
        {
            closegraph();
            binomial_distribution();
            break;
        }
        else if(x>=220&&x<=600 && y>=270&&y<=330)
        {
            closegraph();
            //poison_distribution_with_p();
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
