#include <stdio.h>

#define ARRAY_SIZE 10

void printArray(int A[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("]\n");
}

void hoarepartitioning(int A[], int low, int high, int *p1, int *p2)
{
    int temp;
    int l = low + 1;
    int k = low + 1;
    int g = high;

    while (k < g)
    {
        if (A[k] < A[low])
        {
            temp = A[l];
            A[l] = A[k];
            A[k] = temp;

            l++;
            k++;
        }
        else if (A[k] >= A[high])
        {
            g--;
            temp = A[k];
            A[k] = A[g];
            A[g] = temp;
        }
        else
            k++;
        printArray(A, ARRAY_SIZE);
    }
    temp = A[low];
    A[low] = A[l - 1];
    A[l - 1] = temp;

    temp = A[high];
    A[high] = A[k];
    A[k] = temp;

    *p1 = l - 1;
    *p2 = k;
}

void quicksort(int A[], int low, int high)
{
    int temp;

    if (high - low <= 0)
    {
        return;
    }
    if (A[low] > A[high])
    {
        temp = A[low];
        A[low] = A[high];
        A[high] = temp;
    }

    int p1, p2;
    hoarepartitioning(A, low, high, &p1, &p2);
    quicksort(A, low, p1 - 1);
    quicksort(A, p1 + 1, p2 - 1);
    quicksort(A, p2 + 1, high);
}

int main()
{
    int A[] = {10, 7, 3, 15, 6, 2, 5, 1, 17, 8};
    int n = 10;
    printArray(A, n);
    quicksort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}

// Linux, Mac: gcc task3_template.c -o task3; ./task3
// Windows: gcc task3_template.c -o task3; task3