#include <stdio.h>
#include <stdlib.h>
#define N 5

void print(int *arr, int n) // (a)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int *reverse(int *arr, int n) // (b)
{
    int *rev;
    rev = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        *(rev + i) = *(arr + n - 1 - i);
    }
    return rev;
}
int *prepend(int *arr, int v) // (c)
{
    int *pre;
    pre = malloc((N + 1) * sizeof(int));

    *(pre) = v;

    for (int i = 0; i < N; i++)
    {
        *(pre + i + 1) = *(arr + i);
    }
    return pre;
}

int main()
{
    int *arr;
    arr = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }

    printf("The original: ");
    print(arr, N);

    int *reversed = reverse(arr, N);

    free(arr);

    printf("The reversed: ");
    print(reversed, N);

    int *prepended = prepend(reversed, 5);

    free(reversed);

    printf("The prepended: ");
    print(prepended, N + 1);
}