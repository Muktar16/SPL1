#include<graphics.h>
void initGraph(char *str,int h,int w,int left,int top)
{
    int heightOfScreen,widthOfScreen;
    if(h==0 and w==0)
    {
        heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
        widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    }
    else
    {
        heightOfScreen = h;
        widthOfScreen = w;
    }

    int gd = DETECT;
    initwindow(heightOfScreen,widthOfScreen,str,left,top);
}
