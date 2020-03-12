double sum_square(double *Data,int dataNum)
{
    double sumSQR=0;
    for(int i=0;i<dataNum;i++)
    {
        sumSQR+=(Data[i]*Data[i]);
    }
    return sumSQR;
}



