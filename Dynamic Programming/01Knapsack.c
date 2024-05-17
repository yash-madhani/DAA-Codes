#include<stdio.h>

int maxvalue(int a, int b)
{
    return a>b?a:b;
}

int main()
{
    int n = 4;
    int P[4] = {1,2,5,6};
    int W[4] = {2,3,4,5};
    int M = 8;
    int Profit[4][8];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i == 0 || j == 0 )
                Profit[i][j] = 0;
            else if(j >= W[i])
            {
                Profit[i][j] = maxvalue(Profit[i-1][j],Profit[i-1][j-W[i]] + P[i]);
            }
            else
            {
                Profit[i][j] = Profit[i-1][j];
            }
        }
    }

    printf("%d", Profit[n-1][M]);

    return 0;
}