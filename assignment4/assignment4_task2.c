#include <stdio.h>
#include <stdlib.h>

int max_overlap_subarray(int A[], int l, int m, int r)
{
    int sum = 0;
    int i = 0;
    int left_sum = -99999;

    for (i = m; i >= l; i--)
    {
        sum = sum + A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
        }
    }

    sum = 0;
    i = 0;
    int right_sum = -99999;

    for (i = m + 1; i <= r; i++)
    {
        sum = sum + A[i];
        if (sum > right_sum)
        {
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

int max_subarray(int A[], int l, int r)
{
    if (l == r)
        return A[l];

    int m = l + (r - l) / 2;

    int left_subarray = max_subarray(A, l, m);
    int right_subarray = max_subarray(A, m + 1, r);
    int overlap_array = max_overlap_subarray(A, l, m, r);

    if (left_subarray >= right_subarray && left_subarray > overlap_array)
    {
        return left_subarray;
    }
    else if (right_subarray >= left_subarray && right_subarray > overlap_array)
    {
        return right_subarray;
    }
    return overlap_array;
}

int main()
{
    int A[] = {-1, 2, -3, 4, 3, -5, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);

    int max_sum = max_subarray(A, 0, n - 1);
    printf("The maximum subarray sum is: %d\n", max_sum);

    return 0;
}