#include <stdio.h>

void printArray(int A[], int n)
{
  printf("[");
  for (int i = 0; i < n; i++)
  {
    printf("%d", A[i]);
    if (i < n - 1)
    {
      printf(", ");
    }
  }
  printf("]\n");
}

void heapify(int A[], int i, int n, int d)
{
  int temp;
  int m = i;
  int k, child;

  for (k = 1; k <= d; k++)
  {
    child = (d * i) + k;
    if (child < n && A[child] > A[m])
    {
      m = child;
    }
  }
  if (i != m)
  {
    temp = A[i];
    A[i] = A[m];
    A[m] = temp;
    heapify(A, m, n, d);
  }
}

void buildMaxHeap(int A[], int n, int d)
{
  for (int i = (n - 1) / d; i >= 0; i--)
  {
    heapify(A, i, n, d);
  }
}

void printHeap(int A[], int n, int d)
{
  int i, l, r, k;

  printf("graph g {\n");
  for (i = 0; i < n; i++)
  {
    for (k = 1; k <= d; k++)
    {
      if ((d * i) + k < n)
      {
        printf("  %d -- %d\n", A[i], A[(d * i) + k]);
      }
    }
  }
  printf("}");
}

void heapSort(int A[], int n, int d)
{
  int temp;
  int s = n;
  buildMaxHeap(A, n, d);

  for (int i = n - 1; i > 0; i--)
  {
    temp = A[i];
    A[i] = A[0];
    A[0] = temp;

    s = s - 1;
    heapify(A, 0, s, d);
  }
}

void main()
{
  int n = 10, d = 3;
  int A[10] = {4, 3, 2, 5, 6, 7, 8, 9, 12, 1};

  buildMaxHeap(A, n, d);
  printArray(A, n);
  printf("Heap:\n");
  printHeap(A, n, d);
  printf("\nSorted array:\n");
  heapSort(A, n, d);
  printArray(A, n);
}

// Linux, Mac: gcc task2_template.c -o task1; ./task1
// Windows: gcc task2_template.c -o task1; task1