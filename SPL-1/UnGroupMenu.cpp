#include"header.h"
#include<graphics.h>


void unGroupMenu()
{
    int dataNum;
    double Data[50],Data2[50];
    double Mean,Median,Variance;
    char dataString[2000];
    char tempStr[100];

    //opening a window to get input data values from user
    initGraph("Input data window",0,0,-3,-3);
    settextstyle(10,HORIZ_DIR,2);
    setcolor(11);

    moveto(0,0);
    outtext("Enter Data values separated with comma: ");
    newLine();
    newLine();
    getGrString(dataString);//getting data values as a string separated with comma


    //convert string data to double data
    char *token = strtok(dataString, ",");  // Returns first token
    Data[0]=Data2[0]=stod(token);

    int i=1;
    while (token != NULL)
    {
        token = strtok(NULL, ",");
        if(token !=NULL)
        {
            Data2[i]=Data[i]=stod(token);
            i=i+1;
        }
    }
    dataNum=i;

    //display all the results
    cleardevice();
    setcolor(LIGHTBLUE);
    settextstyle(8,HORIZ_DIR,1);

    //print all values
    moveto(0,10);
    outtext("-> SAMPLE SEQUENCE    = ");
    int xx=getx();
    int widthOfScreen = GetSystemMetrics(SM_CXSCREEN);
    for(i=0;i<dataNum; i++)
    {
        if(Data[i]==(int)Data[i]) sprintf(tempStr,"%d  ",(int)Data[i]);
        else sprintf(tempStr,"%.2f  ",Data[i]);
        outtext(tempStr);

        if(getx()>=widthOfScreen-50)
        {
            newLine();
            moveto(xx,gety());
        }
    }
    newLine();

    //print ascending sequence
    Sort(Data2,dataNum);
    newLine();
    outtext("-> GROWING SEQUENCE   = ");
    for(int i=0;i<dataNum;i++)
    {
        if(Data2[i]==(int)Data2[i]) sprintf(tempStr,"%d  ",(int)Data2[i]);
        else sprintf(tempStr,"%.2f  ",Data2[i]);
        outtext(tempStr);
        if(getx()>=widthOfScreen-50)
        {
            newLine();
            moveto(xx,gety());
        }
    }
    newLine();
    newLine();

    setcolor(YELLOW);
    sprintf(tempStr,"-> SAMPLE SIZE        = %d",dataNum);
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> SUM OF X           = %.2f",sum(Data,dataNum));
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> SUM OF SQUARE X    = %.2f",sum_square(Data,dataNum));
    outtext(tempStr);
    newLine();
    newLine();

    setcolor(LIGHTGREEN);
    double *Max_min;
    Max_min = max_min_calculator(Data,dataNum);
    Median = median_calculator(Data2,dataNum);
    int x1,y1;

    sprintf(tempStr,"-> MINIMUM VALUE      = %.2f",Max_min[1]);
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> 1st QUARTILE       = %.2f",qt_calculator(Data2,dataNum,1));
    outtext(tempStr);
    x1=getx()+200;//get the button position
    y1=gety();
    newLine();
    sprintf(tempStr,"-> MEDIAN             = %.2f",Median);
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> 3rd QUARTILE       = %.2f",qt_calculator(Data2,dataNum,3));
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> MAXIMUM VALUE      = %.2f",Max_min[0]);
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> RANGE              = %.2f",Max_min[0]-Max_min[1]);
    outtext(tempStr);
    newLine();
    newLine();


    setcolor(LIGHTCYAN);
    Mean = mean_calculator(Data,dataNum);
    sprintf(tempStr,"-> MEAN (AVERAGE)     = %.2f",Mean);
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> GEOMETRIC MEAN     = %.2f",gmean_calculator(Data,dataNum));
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> HARMONIC MEAN      = %.2f",hmean_calculator(Data,dataNum));
    outtext(tempStr);
    newLine();
    sprintf(tempStr,"-> MODE               = %.2f",mode_calculator(Data,dataNum));
    outtext(tempStr);
    newLine();

    Variance = variance_calculator(Data,dataNum);
    if(Variance==0)
    {
        outtext("-> VARIANCE OF X      = 0");
        newLine();
        outtext("-> STANDARD DEVIATION = 0");
        newLine();
        outtext("-> STANDARD ERROR     = 0");
        newLine();
        newLine();
        setcolor(LIGHTMAGENTA);
        outtext("-> COEFFICIENT OF VARIANCE = 0%");
        newLine();
        outtext("-> PEARSONS COEFFICIENT OF SKEWNESS = 0");
        newLine();
    }
    else
    {
        sprintf(tempStr,"-> VARIANCE OF X      = %.2f",Variance);
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"-> STANDARD DEVIATION = %.2f",sqrt(Variance));
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"-> STANDARD ERROR     = %.2f",sqrt(Variance)/sqrt(dataNum));
        outtext(tempStr);
        newLine();
        newLine();
        setcolor(LIGHTMAGENTA);
        sprintf(tempStr,"-> COEFFICIENT OF VARIANCE = %.2f%%",(sqrt(Variance)/Mean)*100);
        outtext(tempStr);
        newLine();
        sprintf(tempStr,"-> PEARSONS COEFFICIENT OF SKEWNESS = %.2f",(3*(Mean-Median))/sqrt(Variance));
        outtext(tempStr);
        newLine();

    }

    setcolor(DARKGRAY);
    rectangle(x1,y1,x1+205,y1+30);
    rectangle(x1,y1+50,x1+205,y1+80);
    rectangle(x1,y1+100,x1+205,y1+130);
    setcolor(LIGHTRED);
    outtextxy(x1+10,y1+5,"ANOTHER OPERATION");
    outtextxy(x1+10,y1+55,"BACK TO MAIN MENU");
    outtextxy(x1+75,y1+105,"EXIT");

    POINT position;
    int x,y;
    while(1)
    {
        if(GetKeyState(VK_LBUTTON)&0x8000)  GetCursorPos(&position);
        x = position.x;
        y = position.y;

        if(x>=x1&&x<=x1+205 && y>=y1&&y<=y1+40)
        {
            closegraph();
            unGroupMenu();
            break;
        }
        else if(x>=x1&&x<=x1+205 && y>=y1+50&&y<=y1+90)
        {
            closegraph();
            main_menu();
            break;
        }
        else if(x>=x1&&x<=x1+205 && y>=y1+100&&y<=y1+140)
        {
            closegraph();
            exit(0);
            break;
        }
        else continue;
    }
}

    //getch();
    //closegraph();
    //initGraph("Results for unGrouped Data");



//    system("cls||clear");
//    //if(p=0) cout<<"\n\t\t\t\t\tYou have entered more than "<<dataNum<<" data values. However first "<<dataNum<<" values are considerd here.";
//
//    //print all values
//
//    printf("\n\n\n\n\n\n\n");
//    printf("\n\t\t\t\t\t\t\t-> SAMPLE SEQUENCE    = ");   //print data sequence
//    for(int i=0;i<dataNum; i++)
//    {
//        if(dataNum>10 && (i+1)%10==0) printf("\n\t\t\t\t\t\t\t                        ");
//        printf("%.2f  ",Data[i]);
//    }
//    //printf("\n");
//    printf("\n\t\t\t\t\t\t\t-> GROWING SEQUENCE   = ");
//    Sort(Data2,dataNum);
//    for(int i=0;i<dataNum;i++)
//    {
//        if(dataNum>10 && (i+1)%10==0) printf("\n\t\t\t\t\t\t\t                        ");
//        printf("%.2f  ",Data2[i]);
//    }
//    printf("\n");
//
//    printf("\n\t\t\t\t\t\t\t-> SAMPLE SIZE        = %d",dataNum);
//    printf("\n\t\t\t\t\t\t\t-> SUM OF X           = %.2f",sum(Data,dataNum));
//    printf("\n\t\t\t\t\t\t\t-> SUM OF SQUARE X    = %.2f",sum_square(Data,dataNum));
//    printf("\n");
//
//    double *Max_min;
//    Max_min = max_min_calculator(Data,dataNum);
//    Median = median_calculator(Data2,dataNum);
//
//    printf("\n\t\t\t\t\t\t\t-> MINIMUM VALUE      = %.2f",Max_min[1]);
//    printf("\n\t\t\t\t\t\t\t-> 1st QUARTILE       = %.2f",qt_calculator(Data2,dataNum,1));
//    printf("\n\t\t\t\t\t\t\t-> MEDIAN             = %.2f",Median);
//    printf("\n\t\t\t\t\t\t\t-> 3rd QUARTILE       = %.2f",qt_calculator(Data2,dataNum,3));
//    printf("\n\t\t\t\t\t\t\t-> MAXIMUM VALUE      = %.2f",Max_min[0]);
//    printf("\n\t\t\t\t\t\t\t-> RANGE              = %.2f",Max_min[0]-Max_min[1]);
//    printf("\n");
//
//    Mean = mean_calculator(Data,dataNum);
//    printf("\n\t\t\t\t\t\t\t-> MEAN (AVERAGE)     = %.2f",Mean);
//    printf("\n\t\t\t\t\t\t\t-> GEOMETRIC MEAN     = %.2f",gmean_calculator(Data,dataNum));
//    printf("\n\t\t\t\t\t\t\t-> HARMONIC MEAN      = %.2f",hmean_calculator(Data,dataNum));
//    printf("\n\t\t\t\t\t\t\t-> MODE               = %.2f",mode_calculator(Data,dataNum));
//
//    Variance = variance_calculator(Data,dataNum);
//    if(Variance==0)
//    {
//        printf("\n\t\t\t\t\t\t\t-> VARIANCE OF X      = 0");
//        printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION = 0");
//        printf("\n\t\t\t\t\t\t\t-> STANDARD ERROR     = 0");
//        printf("\n");
//        printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF VARIANCE = 0");
//        printf("\n\t\t\t\t\t\t\t-> PEARSONS COEFFICIENT OF SKEWNESS = 0");
//    }
//    else
//    {
//        printf("\n\t\t\t\t\t\t\t-> VARIANCE OF X      = %.2f",Variance);
//        printf("\n\t\t\t\t\t\t\t-> STANDARD DEVIATION = %.2f",sqrt(Variance));
//        printf("\n\t\t\t\t\t\t\t-> STANDARD ERROR     = %.2f",sqrt(Variance)/sqrt(dataNum));
//        printf("\n");
//        printf("\n\t\t\t\t\t\t\t-> COEFFICIENT OF VARIANCE = %.2f",(sqrt(Variance)/Mean)*100); cout<<"%";
//        printf("\n\t\t\t\t\t\t\t-> PEARSONS COEFFICIENT OF SKEWNESS = %.2f",(3*(Mean-Median))/sqrt(Variance));
//
//    }
//
//    int choice;
//    printf("\n\n\n");
//
//    while(1)
//    {
//        printf("\n\t\t\t\t\t\t\t1.ANOTHER OPERATION\n\t\t\t\t\t\t\t2.BACK TO MAIN MENU\n\t\t\t\t\t\t\t3.EXIT\n\t\t\t\t\t\t\t");
//        scanf("%d",&choice);
//
//        switch(choice)
//        {
//            case 1:
//            {
//                system("cls||clear");
//                unGroupMenu();
//                return;
//            }
//            case 2:
//            {
//                system("cls||clear");
//                cout<<"\n\n\n\n\n\n\n\n\n";
//                main_menu();
//                break;
//            }
//            case 3: exit(0);
//            default:
//            {
//                system("cls||clear");
//                printf("\n\t\t\t\t\t\t\tWRONG INPUT!!! PRESS ANY KEY TO TRY AGAIN.");
//                _getch();
//                system("cls||clear");
//            }
//
//        }
//
//    }

