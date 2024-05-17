#include<stdio.h>
int start[]={5,1,3,0,5,8};
int end[]={9,2,4,6,7,9};
int n=6;

void sort()
{
    int temps,tempe;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(end[j]>end[j+1])
            {
                tempe = end[j];
                end[j] = end[j+1];
                end[j+1] = tempe;

                temps = start[j];
                start[j] = start[j+1];
                start[j+1] = temps;
            }
        }
    }
}

void activityselection()
{
    int selection = 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(start[i]> selection)
        {
            printf("%d ---> %d\n",start[i],end[i]);
            selection = end[i];
            count++;
        }
    }

    printf("No. of activities selected = %d", count);
}

void main()
{
    sort();
    activityselection();
}