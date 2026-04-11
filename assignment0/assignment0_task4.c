#include <stdio.h>

int main()
{
    int A[4][4] = {
        {2, 4, 1, 3},
        {5, 7, 8, 2},
        {9, 6, 4, 1},
        {3, 8, 5, 6}};
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                sum += A[i][j];
        }
    }
    printf("%d\n", sum);
}