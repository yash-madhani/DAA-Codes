#include<stdio.h>
#define INF 100000
struct edge {
    int u;
    int v;
};

void bellmanford(int s,int n, struct edge e1[], int Cost[][6])    // 5
{
    int D[n];
    D[s] = 0;
    for(int i=1;i<n;i++)
        D[i] = INF;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<7;j++)                 // 10
        {
            if(D[e1[j].v] > D[e1[j].u] + Cost[e1[j].u][e1[j].v])
            {
                D[e1[j].v] = D[e1[j].u] + Cost[e1[j].u][e1[j].v];
            }
        }
    }


    printf("Source\tDestination\n");
    for(int i=0;i<n;i++)
    {
      printf("%d\t%d\n",i,D[i]);
    }
}

void main()
{
//  struct edge e1[10]={{0,1},{0,3},{1,2},{1,3},{1,4},{2,1},{3,2},{3,4},{4,2},{4,0}};
  struct edge e1[7]={{0,1},{1,2},{1,3},{2,4},{3,5},{4,3},{5,4}};
  int s=0;
//   int COST[5][5]={
//                  {0,6,0,7,0},
//                  {0,0,5,8,-4},
//                  {0,-2,0,0,0},
//                  {0,0,-3,0,9},
//                  {2,0,7,0,0}

//   };
//   int n=5;

  int COST[6][6]={
                 {0,5,0,0,0,0},
                 {0,0,1,2,0,0},
                 {0,0,0,0,1,0},
                 {0,0,0,0,0,2},
                 {0,0,0,1,0,0},
                 {0,0,0,0,3,0}

  };
  int n=6;

  bellmanford(s,n,e1,COST);

}