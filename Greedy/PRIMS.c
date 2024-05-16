#include<stdio.h>
#define INF 1000000

void PRIM(int Cost[][10],int n)
{
    int Edge[10][10],Near[10];    
    int mincost = INF,k,l,j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mincost>Cost[i][j])
            {
                mincost = Cost[i][j];
                Edge[0][0] = i;
                Edge[1][0] = j;
            }
        }
    }
    k = Edge[0][0];
    l = Edge[1][0];
    for(int i=0;i<n;i++)
    {
        if(Cost[i][k] < Cost[i][l])
        {
            Near[i] = k;
        }
        else
        {
            Near[i] = l;
        }
    }
    Near[k] = Near[l] = 0;

    for(int i=1;i<n-1;i++)
    {
        int min = INF;
        // find j
        for(int m=0;m<n;m++)
        {
            
            if(Near[m] != 0 && min > Cost[m][Near[m]])
            {
                min = Cost[m][Near[m]];
                j = m;
            }
        }

        Edge[0][i] = j;
        Edge[1][i] = Near[j];
        mincost += Cost[j][Near[j]];
        Near[j] = 0;

        for(int m=0;m<n;m++)
        {
            if(Near[m] != 0 && Cost[m][Near[m]] > Cost[m][j])
            {
                Near[m] = j;
            }
        }
    }

    if (mincost >= INF)
    {
        printf("NO SPANNING TREE");
        exit(1);
    }

    for(int i=0;i<n-1;i++)
        printf("%d --- %d\n", Edge[0][i],Edge[1][i]);
}

int main()
{
    int Cost[10][10] = {
        {INF,8,1,INF,INF,INF},
        {8,INF,5,2,INF,INF},
        {1,5,INF,INF,7,INF},
        {INF,2,INF,INF,2,3},
        {INF,INF,7,2,INF,15},
        {INF,INF,INF,3,15,INF}
    };
    int n = 6;

    PRIM(Cost,n);

    return 0;
}