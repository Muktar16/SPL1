#include"header.h"
#include<graphics.h>

void CoRelationAndRegressionMenu()
{
    char tempStr[2000];
    int n,i,j;
    double X[100],Y[100],XY[100];

    initGraph("Input data window for Co-relation and Regression",0,0,-3,-3);
    setcolor(11);

    moveto(0,0);
    newLine();
    outtext("Enter values of class X separated with comma: ");
    newLine();
    newLine();
    getGrString(tempStr);//getting X values as a string separated with comma


    //convert string X to double X
    char *token = strtok(tempStr, ",");  // Returns first token
    X[0]=stod(token);

    i=1;
    while (token != NULL)
    {
        token = strtok(NULL, ",");
        if(token !=NULL)
        {
            X[i]=stod(token);
            i=i+1;
        }
    }
    n=i;//sample size
    int y = gety();

    while(1)
    {

        setcolor(11);
        newLine();
        newLine();
        newLine();
        outtext("Enter values of class Y separated with comma: ");
        newLine();

        getGrString(tempStr);//getting data values as a string separated with comma


        //convert string data to double data
        char *token = strtok(tempStr, ",");  // Returns first token
        Y[0]=stod(token);

        i=1;
        while (token != NULL)
        {
            token = strtok(NULL, ",");
            if(token !=NULL)
            {
                Y[i]=stod(token);
                i=i+1;
            }
        }
        if(i==n) break;
        else
        {
            newLine();
            newLine();
            setcolor(LIGHTRED);
            outtext("!!!Please Enter valid values. Amount of values for both classes should be equal.");
            newLine();
            sprintf(tempStr,"You should Enter %d values of Y.",n);
            outtext(tempStr);
            newLine();
            newLine();
            outtext("Press any key to try again..........");
            getch();
            cleardevice();
        }
    }


    //calculation of XY
    for(i=0;i<n;i++) XY[i]=X[i]*Y[i];

    //print results
    closegraph();
    while(1)
    {
        RegPrintResults(X,Y,XY,n);
    }

}

