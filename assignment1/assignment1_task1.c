#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[] = {15, 5, 1, 4, 2, 8, 7};
    int n = 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
            }
        }
        for (int k = 0; k < n; k++)
        {
            printf("%d ", A[k]);
        }
        printf("\n");
    }
}