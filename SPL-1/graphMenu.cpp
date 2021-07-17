#include<graphics.h>
void graphMenu()
{

    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    initwindow(heightOfScreen,widthOfScreen,"Graph Menu",-3,-3);
    settextstyle(10,HORIZ_DIR,5);

    setcolor(YELLOW);
    rectangle(100,100,500,150);
    outtextxy(160,115,"Frequency Polygon");

}
