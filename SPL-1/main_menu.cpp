#include<graphics.h>
#include"header.h"


void main_menu()
{
    initGraph("Msin Menu Window");
    settextstyle(10,HORIZ_DIR,5);

    setcolor(3);
    outtextxy(300,5,"Welcome to Statistical Analyzer");
    setcolor(5);
    outtextxy(580,80,"MAIN MENU");
    outtextxy(560,110,"-----------");


    settextstyle(10,HORIZ_DIR,3);
    setcolor(8);
    rectangle(220,170,600,220);//ungrouped data
    rectangle(220,270,600,320);//GROUPED DATA
    rectangle(220,370,600,450);//UNGROUPED TO GROUPED DATA CONVERTER
    rectangle(220,500,600,550);//FORMULA SHEETS
    rectangle(780,170,1160,220);//REGRESSION & CO-RELATION
    rectangle(780,270,1160,320);//PROBABILITY DISTRIBUTION
    rectangle(780,380,1160,430);//VARIOUS GRAPHS
    rectangle(780,500,1160,550);//EXIT

    setcolor(6);
    outtextxy(300,185,"UNGROUPED DATA");
    outtextxy(315,285,"GROUPED DATA");
    outtextxy(255,385,"UNGROUPED TO GROUPED");
    outtextxy(295,415,"DATA CONVERTER");
    outtextxy(300,515,"FORMULA SHEETS");
    outtextxy(810,185,"REGRESSION & CO-RELATION");
    outtextxy(800,285,"PROBABILITY DISTRIBUTION");
    outtextxy(880,395,"VARIOUS GRAPHS");
    setcolor(RED);
    outtextxy(930,515,"EXIT");


    delay(500);
    POINT position;
    int x,y;

    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x = position.x;
        y = position.y;

        if(x>=220&&x<=600 && y>=170&&y<=230)
        {
            closegraph();
            delay(500);
            unGroupMenu();
            break;
        }
        else if(x>=220&&x<=600 && y>=270&&y<=330)
        {
            closegraph();
            delay(500);
            groupMenu();
        }
        else if(x>=220&&x<=600 && y>=370&&y<=460)
        {
            closegraph();
            delay(500);
            unGroupToGroupMenu();
        }
        else if(x>=220&&x<=600 && y>=500&&y<=560)
        {
            closegraph();
            delay(500);
            formulaSheetsMenu();
        }
        else if(x>=780&&x<=1160 && y>=170&&y<=230)
        {
            closegraph();
            delay(500);
            CoRelationAndRegressionMenu();
        }
        else if(x>=780&&x<=1160 && y>=270&&y<=330)
        {
            closegraph();
            delay(500);
            probabilityMenu();
        }
        else if(x>=780&&x<=1160 && y>=380&&y<=440)
        {
            closegraph();
            delay(500);
            graphMenu();
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
        getch();
        closegraph();
    }



//    char choice;//If int type and user input character unconsciously it will trouble
//    //Main menu
//    printf("\n\n\n\n\n\n\n\n");
//    cout<<"\n\t\t\t\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t\t\t     ===============\n\n"
//        <<"\t\t\t\t\t\t\t\t1. UNGROUPED DATA\n"
//        <<"\t\t\t\t\t\t\t\t2. GROUPED DATA\n"
//        <<"\t\t\t\t\t\t\t\t3. UNGROUPED TO GROUPED DATA CONVERTER\n"
//        <<"\t\t\t\t\t\t\t\t4. REGRESSION & CO-RELATION\n"
//        <<"\t\t\t\t\t\t\t\t5. PROBABILITY DISTRIBUTION\n"
//        <<"\t\t\t\t\t\t\t\t6. FORMULA SHEETS\n"
//        <<"\t\t\t\t\t\t\t\t7. EXIT\n\n\n"
//        <<"\t\t\t\t\t\t\t\tEnter your Choice: ";
//    scanf("%s",&choice);
//
//    switch(choice)
//    {
//        case '1': {unGroupMenu(); break;}
//        case '2': {groupMenu(); break;}
//        case '3': {unGroupToGroupMenu(); break;}
//        case '4': {CoRelationAndRegressionMenu(); break;}
//        case '5': {probabilityMenu(); break;}
//        case '6': {formulaSheetsMenu(); break;}
//        case '7': exit(0);
//        default:
//        {
//            system("cls||clear");
//            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
//            cout<<"\n\t\t\t\t\t\t\tWRONG INPUT!!! YOU HAVE TO SELECT A NUMBER BETWEEN 1-7. \n";
//            cout<<"\n\n\t\t\t\t\t\t\tPress Any key to try again...............";
//            _getch();
//            system("cls||clear");
//            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
//            return;
//        }
//    }
}
