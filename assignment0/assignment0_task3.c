#include <stdio.h>

int main() {
    int n = 6;
    int a[] = {11, 3, -3, 2, -5, 9};

    int largest = -9999;

    for(int i = 0; i < n; i++) {
        if(a[i] > largest) {
            largest = a[i];
        }
    }

    int sec_largest = -9999;

    for(int i = 0; i < n; i++) {
        if(a[i] > sec_largest && a[i] != largest) {
            sec_largest = a[i];
        }
    }

    printf("%d\n", sec_largest);

}