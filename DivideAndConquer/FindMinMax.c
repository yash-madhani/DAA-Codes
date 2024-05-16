#include<stdio.h>
#include<conio.h>
#include<math.h>

struct MinMax {
    int min;
    int max;
} ;

struct MinMax FindMinMax(int A[], int low, int high)
{
    struct MinMax st,lst,rst;
    if (low == high) // one element
    {
        st.max = A[low];
        st.min = A[low];
        return st;
    }
    else if (low == high - 1) // two elements
    {
        if(A[low] < A[high])
        {
            st.min = A[low];
            st.max = A[high];
        }
        else
        {
            st.max = A[low];
            st.min = A[high];
        }
        return st;
    }
    else // more than two elements
    {
        int mid = (low + high)/2;
        lst = FindMinMax(A,low,mid);
        rst = FindMinMax(A,mid+1,high);

        if (lst.min < rst.min)
        {
            st.min = lst.min;
        }
        else
        {
            st.min = rst.min;
        }

        if (lst.max > rst.max)
        {
            st.max = lst.max;          
        }
        else
        {
            st.max = rst.max;
        }
        return st;
    }
}

void main()
{
    int A[8] = {10,5,20,9,7,17,6,3};
    int low = 0;
    int high = 7;

    struct MinMax st = FindMinMax(A,low,high);
    
    printf("%d \n", st.max);
    printf("%d", st.min);
}