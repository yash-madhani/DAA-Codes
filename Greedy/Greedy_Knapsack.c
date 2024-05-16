#include<stdio.h>

int main()
{
    int i;
    float CP = 0;
    int n = 6;
    float M = 16;
    int ccofks = M;
    float P[6] = {3,5,8,6,1,2};
    float W[6] = {1,3,5,6,3,10};
    float X[6];
    for(int f=0;f<n;f++)
        X[f] = 0;

    for(i=0;i<n;i++)
    {
        if(ccofks < W[i])
            break;
        
        X[i] = 1;
        ccofks -= W[i];
        CP += P[i];
    }

    if (i <= n-1)
    {
        X[i] = ccofks/W[i];
        CP += P[i]*X[i];
    }

    printf("Cummulative Profit: %f \n", CP);
    printf("Selected array:\n");
    for(int j=0;j<n;j++)
    {
        
        printf("%f ", X[j]);
    }
    return 0;
}