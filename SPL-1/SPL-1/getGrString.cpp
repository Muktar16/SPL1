#include<graphics.h>
#include"header.h"
#define ON 1
#define OFF 0

void getGrString(char *inputString)
{
    int stringIndex=0;
    int xVal[255];
    char inputChar, outString[2];
    int oldColor;
    outString[1]=0;

    xVal[0]=getx();
    do
    {
        doCursor(ON);
        inputChar=getch();
        doCursor(OFF);
        if (inputChar==0) getch();
        else
        {
            if (inputChar==8) {
                //save old character color
                oldColor=getcolor();
                //back up in the string
                --stringIndex;
                //no backing up past beginning of string!
                if (stringIndex<0) stringIndex=0;
                //move to (old horz position, current vert position)
                moveto(xVal[stringIndex],gety());
                //erasing consists of rewriting the old character in the background color
                setcolor(getbkcolor());
                outString[0]=inputString[stringIndex];
                outtext(outString);
                //correct the current screen position since it will have advanced after writing outString
                moveto(xVal[stringIndex],gety());
                //restore the text color we had
                setcolor(oldColor);
            }
            // put a character into the string and draw it on screen
            else {
                //stuff the input into the string
                inputString[stringIndex]=inputChar;
                //draw the character on screen, as a string (since that's what outttext() needs)
                outString[0]=inputChar;
                outtext(outString);
                //proceed to next char in the string
                ++stringIndex;
                //save horz position for possible backspacing
                xVal[stringIndex]=getx();
            }
         }
        //end getting characters on ENTER or LF
    } while(inputChar!=13 && inputChar!=10);
    //null-terminate input string before returning
    inputString[stringIndex]=0;
}
