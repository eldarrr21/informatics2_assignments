#include <stdio.h>
#include <stdlib.h>

int binary_search(int A[], int n, int v)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (A[m] == v)
        {
            return m;
        }
        if (A[m] > v)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13}, n = 7, v = 7;
    printf("%d\n", binary_search(A, n, v));
}
