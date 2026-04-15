#include <stdio.h>
#include <stdlib.h>

void printRec(int n)
{
    if (n == 0)
        return;

    printRec(n / 2);

    printf("%d", n % 2);
}

int main()
{
    printRec(20);

    printf("\n");

    return 0;
}