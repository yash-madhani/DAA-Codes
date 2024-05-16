#include<stdio.h>

int main()
{
    int n = 5,dmax = 0,fts = 0,CP = 0;
    int P[5] = {20,15,10,5,1};
    int D[5] = {2,2,1,3,3};
    int J[5] = {1,2,3,4,5};
    int X[5];
    int Time[5];

    for(int i=0;i<n;i++)
    {
        Time[i] = -1;
        X[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        if(dmax < D[i])
            dmax = D[i];
    }

    for(int i=0;i<n;i++)
    {
        int k = D[i];
        while(k >= 1)
        {
            if(Time[k-1] == -1)
            {
                Time[k-1] = J[i];
                X[J[i] - 1] = 1;
                fts += 1;
                break;
            }
            k -= 1;
        }

        if(fts == dmax)
            break;
    }

    for(int i=0;i<dmax;i++)
    {
        
        printf("J%d -->", Time[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf(" %d",X[i]);
        CP += P[i]*X[i];
    }

    printf("\nProfit = %d", CP);

    

    return 0;
}