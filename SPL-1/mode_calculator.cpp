double mode_calculator(double *Data,int dataNum)
{
    if(dataNum==1) return 0.0;

   double maxValue = 0, maxCount = 0;

   for (int i=0;i<dataNum;i++)
   {
      int count=0;
      for (int j=0;j<dataNum;j++)
      {
         if(Data[j]==Data[i])
         count++;
      }
      if(count>maxCount)
      {
         maxCount = count;
         maxValue = Data[i];
      }
   }
   if(maxCount==1) return 0.0;
   return maxValue;
}
