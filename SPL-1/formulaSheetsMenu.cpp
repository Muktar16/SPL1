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
        rectangle(500,380,800,420);//ALL FORMULA SHEETS
        rectangle(500,450,800,490);//BACK TO MAIN MENU
        rectangle(500,520,800,560);//EXIT


        setcolor(LIGHTBLUE);
        //button texts
        settextstyle(BOLD_FONT,HORIZ_DIR,2);
        outtextxy(505,110,"      UNGROUPED DATA");
        outtextxy(505,180,"      GROUPED DATA");
        outtextxy(505,250,"REGRESSION & CO-RELATION");
        outtextxy(505,320,"PROBABILITY DISTRIBUTION");
        outtextxy(505,390,"   ALL FORMULA SHEETS");
        outtextxy(505,460,"    BACK TO MAIN MENU");
        setcolor(RED);
        outtextxy(505,530,"          EXIT");


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
                system("cls||clear");
                read_file("formula_sheet_1.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=800 && y>=170&&y<=220)
            {
                closegraph();
                system("cls||clear");
                read_file("formula_sheet_2.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=800 && y>=240&&y<=290)
            {
                closegraph();
                system("cls||clear");
                read_file("formula_sheet_3.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=800 && y>=310&&y<=360)
            {
                closegraph();
                system("cls||clear");
                read_file("formula_sheet_4.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=800 && y>=380&&y<=430)
            {
                closegraph();
                system("cls||clear");
                read_file("formula_sheet_5.txt");
                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
                _getch();
                break;
            }
            else if(x>=500&&x<=800 && y>=450&&y<=500)
            {
                closegraph();
                return;
                break;

            }
            else if(x>=500&&x<=800 && y>=520&&y<=570)
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



//    while(1)
//    {
//        system("cls||clear");
//        int choice;
//        printf("\n\n\n\n\n\n");
//        cout<<"\n\t\t\t\t\t\t\t\tFORMULA SHEETS MENU\n\t\t\t\t\t\t\t==============================\n\n"
//            <<"\t\t\t\t\t\t\t1. UNGROUPED DATA\n"
//            <<"\t\t\t\t\t\t\t2. GROUPED DATA\n"
//            <<"\t\t\t\t\t\t\t3. REGRESSION & CO-RELATION\n"
//            <<"\t\t\t\t\t\t\t4. PROBABILITY DISTRIBUTION\n"
//            <<"\t\t\t\t\t\t\t5. ALL FORMULA SHEETS\n"
//            <<"\t\t\t\t\t\t\t6. BACK TO MAIN MENU\n"
//            <<"\t\t\t\t\t\t\t7. EXIT\n\n\n"
//            <<"\t\t\t\t\t\t\tEnter your Choice: ";
//        cin>>choice;
//        getchar();
//
//        switch(choice)
//        {
//            case 1:
//            {
//
//                system("cls||clear");
//                read_file("formula_sheet_1.txt");
//                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
//                _getch();
//                break;
//            }
//            case 2:
//            {
//                system("cls||clear");
//                read_file("formula_sheet_2.txt");
//                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
//                _getch();
//                break;
//            }
//            case 3:
//            {
//                system("cls||clear");
//                read_file("formula_sheet_3.txt");
//                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
//                _getch();
//                break;
//            }
//            case 4:
//            {
//                system("cls||clear");
//                read_file("formula_sheet_4.txt");
//                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
//                _getch();
//                break;
//            }
//
//            case 5:
//            {
//                system("cls||clear");
//                read_file("formula_sheet_5.txt");
//                cout<<"\n\n\t\t\t\t\t\t\tPress Any Key To Continue..............";
//                _getch();
//                break;
//            }
//            case 6:
//            {
//                system("cls||clear");
//                cout<<"\n\n\n\n\n\n\n\n\n\n\n";
//                return;
//            }
//            case 7: exit(0);
//            default:
//            {
//                system("cls||clear");
//                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
//                cout<<"\n\t\t\t\t\t\t\tWRONG INPUT!!! YOU HAVE TO SELECT A NUMBER BETWEEN 1-7. \n";
//                cout<<"\n\n\t\t\t\t\t\t\tPress Any key to try again...............";
//                _getch();
//                system("cls||clear");
//            }
//        }
//    }
}
