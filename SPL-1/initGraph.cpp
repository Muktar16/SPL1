#include<graphics.h>
void initGraph(char *str)
{
    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    int gd = DETECT;
    initwindow(heightOfScreen,widthOfScreen,str,-3,-3);
}
