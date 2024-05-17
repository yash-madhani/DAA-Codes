#include<stdio.h>
#define INF 100000

int minvalue(int a,int b)
{
    return a<b ? a : b;
}

void floyd_warshall(int n,int Cost[][4],int P[][4])
{
    int A[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j] = Cost[i][j];
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(A[i][k] + A[k][j] < A[i][j])
                    P[i][j] = k+1; //IMP that its k+1
                A[i][j] = minvalue(A[i][j],A[i][k]+A[k][j]);
                
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",P[i][j]);
        }
        printf("\n");
    }
}

void main()
{
  int n=4;
  int COST[4][4]={
                  {0,3,INF,7},
                  {8,0,2,INF},
                  {5,INF,0,1},
                  {2,INF,INF,0}
  };
  int P[4][4]={
                {0,1,0,1},
                {2,0,2,0},
                {3,0,0,3},
                {4,0,0,0}
  };

  floyd_warshall(n,COST,P);

}