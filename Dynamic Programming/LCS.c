#include<stdio.h>
#include<string.h>

int maxvalue(int a,int b)
{
    return a>b?a:b;
}

int lcs(char x[], char y[])
{

    int m = strlen(x);
    int n = strlen(y);
    int LCS[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
                LCS[i][j] = 0;
            else if(x[i-1] == y[j-1])
                LCS[i][j] = 1 + LCS[i-1][j-1];
            else
                LCS[i][j] = maxvalue(LCS[i-1][j],LCS[i][j-1]);
        }
    }

    return LCS[m][n];
}

int main()
{

    char x[] = "SAVANNAH";
    char y[] = "HAVANA";

    int ans = lcs(x,y);

    printf("%d", ans);

    return 0;
}