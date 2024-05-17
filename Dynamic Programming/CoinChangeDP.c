#include<stdio.h>
#define INF 100000

int minvalue(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int n = 4;
    int coin[4] = {1,2,25,40};
    int Amt = 50;
    int CCP[n][Amt+1]; // imp that it should be Amt+1

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=Amt;j++)
        {
            if(j == 0)
            {
                CCP[i][j] = 0;
            }
            else if(i == 0)
            {
                CCP[i][j] = (j % coin[i] == 0) ? j / coin[i] : INF;
            }
            else
            {
                if(coin[i] <= j && CCP[i][j-coin[i]] != INF)
                {
                    CCP[i][j] = minvalue(CCP[i-1][j],CCP[i][j-coin[i]] + 1);
                }
                else
                {
                    CCP[i][j] = CCP[i-1][j];
                }
            }
        }
    }

    printf("%d", CCP[n-1][Amt]);

    return 0;
}