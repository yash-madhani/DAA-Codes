#include<stdio.h>

int main()
{
    int Denominations[4] = {1,2,25,40};
    int n=4,temp,amt=50;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(Denominations[j] < Denominations[j+1])
            {
                temp = Denominations[j+1];
                Denominations[j+1] = Denominations[j];
                Denominations[j] = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        while(Denominations[i] <= amt)
        {
            printf("%d ",Denominations[i]);
            amt -= Denominations[i];
        }
    }

    return 0;
}