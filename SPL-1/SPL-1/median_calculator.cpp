
double median_calculator(double *Data,int dataNum)
{
    int n=dataNum-1;
    if(dataNum%2==0)
    {
        return (Data[n/2]+Data[(n/2)+1])/2.0;
    }
    else
    {
        return Data[(n+1)/2];
    }
}

