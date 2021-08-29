#include"header.h"

void unGroupToGroupConverter(double* Data,double* LB,double* UB,int *F,int G,int N)
{
    Sort(Data,N);

    if(G==1)
    {
        LB[0] = (int)Data[0]-((int)Data[0]%5);
        UB[0] = (int)Data[N-1]+((int)Data[N-1]%5)+1;
    }

    else
    {
        int h = (Data[N-1]-Data[0])/G;
        if(h>5)
        {
            h=(h+(5-(h%5)))-1;
        }
        LB[0] = (int)Data[0]-((int)Data[0]%5);
        UB[0] = LB[0]+h;

        for(int i=1;i<G;i++)
        {
            LB[i]=UB[i-1]+1;
            UB[i]=LB[i]+h;
        }
    }

    for(int i=0;i<G;i++)
    {
        F[i]=0;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<G;j++)
        {
            if(Data[i]>=LB[j]-0.5 && Data[i]<=UB[j]+0.5)
            {
                F[j]++;
                break;
            }
        }
    }

}
