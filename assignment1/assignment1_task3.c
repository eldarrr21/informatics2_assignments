#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double hilbert_curve(int i, double l)
{

    if (i == 0)
    {
        return 0.0;
    }
    return 2.0 * hilbert_curve(i - 1, l) + (3.0 * l) / pow(2.0, i);
}

int main()
{
    int order = 15;
    double l = 5.0;

    double total_length = hilbert_curve(order, l);

    printf("The length of order %d is %.2f\n", order, total_length);

    return 0;
}