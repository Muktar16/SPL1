#include<graphics.h>
#include"header.h"
#define ON 1
#define OFF 0

void getGrString(char *inputString)
{
    /* stringIndex is the current place in the string, so that we
    may build it as we go along getting input characters */
    int stringIndex=0;
    /* xVal will store the screen position for each char as we go
    along, so that we can erase and move the cursor
    successfully during backspacing */
    int xVal[255];
    /* inputChar: the character typed;  outString: the string
    version of that character */
    char inputChar, outString[2];
    /* oldColor saves the previous color value, to restore after
    erasing */
    int oldColor;
    /* outString is just one char + a null-terminator */
    outString[1]=0;
    /* screen starting position for input char string */
    xVal[0]=getx();
    do
    {
    /* turn on the cursor */
    doCursor(ON);
    /* get a single character, in no-echo mode */
    inputChar=getch();
    /* turn off the cursor before we write a new character */
    doCursor(OFF);
    /* avoid dealing with all special keys */
    if (inputChar==0) getch();
    else
    {
        if (inputChar==8) { /* backspace */
            /* save old character color */
            oldColor=getcolor();
            /* back up in the string */
            --stringIndex;
            /* no backing up past beginning of string! */
            if (stringIndex<0) stringIndex=0;
            /* move to (old horz position, current vert
               position) */
            moveto(xVal[stringIndex],gety());
            /* erasing consists of rewriting the old character
               in the background color */
            setcolor(getbkcolor());
            outString[0]=inputString[stringIndex];
            outtext(outString);
            /* correct the current screen position since it
               will have advanced after writing outString */
            moveto(xVal[stringIndex],gety());
            /* restore the text color we had */
            setcolor(oldColor);
        }
        else { /* put a character into the string and draw it
                  on screen */
            /* stuff the input into the string */
            inputString[stringIndex]=inputChar;
            /* draw the character on screen, as a string
               (since that's what outttext() needs) */
            outString[0]=inputChar;
            outtext(outString);
            /* proceed to next char in the string */
            ++stringIndex;
            /* save horz position for possible backspacing */
            xVal[stringIndex]=getx();
        }
     }
    /* end getting characters on ENTER or LF */
    } while(inputChar!=13 && inputChar!=10);
    /* null-terminate input string before returning */
    inputString[stringIndex]=0;
}
