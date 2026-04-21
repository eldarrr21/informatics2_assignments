#include <stdio.h>
#include <stdlib.h>

int T(int n, int c1)
{
    if (n <= 1)
        return 1;

    int t = 2 * T(n - 1, c1) + c1;
    printf("%d\n", t);
    return t;
}

int main()
{
    printf("--Test Case 1: n=3, c1=5--\n");
    T(3, 5);

    printf("\n--Test Case 2: n=4, c1=10--\n");
    T(4, 10);

    printf("\n--Test Case 3: n=5, c1=2--\n");
    T(5, 2);

    return 0;
}