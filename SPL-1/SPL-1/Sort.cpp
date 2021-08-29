

void Sort(double *Data,int dataNum)
{
    for(int i=0;i<dataNum;i++)
    {
        for(int j=0;j<dataNum-i-1;j++)
        {
            if(Data[j]>Data[j+1])
            {
                double temp = Data[j];
                Data[j]=Data[j+1];
                Data[j+1]=temp;
            }
        }
    }
}

