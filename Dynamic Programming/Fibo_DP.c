#include<stdio.h>

int main()
{
    int n = 7;
    int LT[n];

    for(int i=0;i<n;i++)
    {
        if (i <= 1)
        {
            LT[i] = i;
        }
        else
        {
            LT[i] = LT[i-1] + LT[i-2];
        }
    }

    printf("%d", LT[n-1]);

    return 0;
}