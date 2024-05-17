#include<stdio.h>
#define INF 100000

int minvalue(int a,int b)
{
    if (a<b)
        return a;
    else
        return b;
}

int main()
{
    int n = 6,w = 0,minIndex = INF;
    int Cost[6][6] = {
        {INF,4,2,INF,INF,INF},
        {4,INF,1,5,INF,INF},
        {2,1,INF,8,10,INF},
        {INF,5,8,INF,2,6},
        {INF,INF,10,2,INF,5},
        {INF,INF,INF,6,5,INF}
    };

    int Dist[n];
    int S[n];

    for(int i=0;i<n;i++)
    {
        S[i] = 0;
        Dist[i] = Cost[w][i];
    }
    S[w] = 1;
    Dist[w] = 0;

    for(int i=1;i<n;i++)
    {
        int mincost = INF;
        for(int j=0;j<n;j++)
        {
            if(mincost > Dist[j] && S[j] == 0)
            {
                mincost = Dist[j];
                minIndex = j;
            }
        }
        S[minIndex] = 1;

        for(int j=0;j<n;j++)
        {
            if(S[j] == 0)
            {
                Dist[j] = minvalue(Dist[j],Dist[minIndex] + Cost[j][minIndex]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ", Dist[i]);
    }

    return 0;
}