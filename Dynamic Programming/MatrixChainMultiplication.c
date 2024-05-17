#include <stdio.h>

void main()
{
    int n = 6, j, min, q;
    int Cost[6][6] = {0};
    int Path[6][6] = {0};

    int D[6] = {1, 5, 4, 3, 2, 1};

    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            j = d + i;
            min = 99999;
            for (int k = i; k <= j - i; k++)
            {
                q = Cost[i][k] + Cost[k + 1][j] + D[i - 1] * D[j] * D[k];
                if (q < min)
                {
                    min = q;
                    Path[i][j] = k;
                }
            }
            Cost[i][j] = min; // IMP don't forget this.
        }
    }

    printf("Min cost is %d\n", Cost[1][n - 1]);
    printf("Minimum no. of multiplications is: %d", Path[1][n - 1]);
}
