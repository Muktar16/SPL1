double qt_calculator(double *Data,int dataNum,int k)
{

    if(dataNum%2!=0)
    {
        int index = (k*(dataNum+1))/4;
        int i = (dataNum+1)%4;

        if(i==0)  return Data[index-1];
        else return (Data[index-1]+Data[index])/2;
    }
    else
    {
        int index = (k*dataNum)/4;
        int i=dataNum%4;

        if(i==0) return (Data[index-1]+Data[index])/2;
        else return Data[index];
    }

}
