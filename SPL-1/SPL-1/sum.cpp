double sum(double *Data,int dataNum)
{
    double sum=0;
    for(int i=0;i<dataNum;i++)
    {
        sum+=Data[i];
    }
    return sum;
}
