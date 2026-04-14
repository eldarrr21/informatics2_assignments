#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, j, k;

    if (argc != 5)
    {
        printf("Error: Provide exactly 4 integer values.\n");
        printf("Example: ./matrix 1 2 3 4\n");
        return 1;
    }

    int n = 2;
    int original[2][2];
    int squared[2][2] = {0};

    sscanf(argv[1], "%d", &original[0][0]);
    sscanf(argv[2], "%d", &original[0][1]);
    sscanf(argv[3], "%d", &original[1][0]);
    sscanf(argv[4], "%d", &original[1][1]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            squared[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                squared[i][j] = squared[i][j] + original[i][k] * original[k][j];
            }
        }
    }

    printf("  Original      Squared\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", original[i][j]);
        }

        printf("  |  ");

        for (int j = 0; j < n; j++)
        {
            printf("%4d ", squared[i][j]);
        }

        printf("\n");
    }

    return 0;
}