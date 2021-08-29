#include<graphics.h>

void doCursor(int on)
{
  int curX,oldColor;

  //using underbar as a cursor
  char uBarStr[2] = { '_',0 };
  //if cursor goes OFF, erase by drawing w/bkground color
  if (!on) {
      oldColor=getcolor();
      setcolor(getbkcolor());
  }
  //save horizontal position before drawing cursor
  curX=getx();
  outtext(uBarStr);
  moveto(curX,gety());
  //if we changed the color to erase cursor, change it back
  if (!on) setcolor(oldColor);
}
