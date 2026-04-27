#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int queue[SIZE];
int top = -1;

void enqueue(int x)
{
    if (top < SIZE - 1)
    {

        top++;
        queue[top] = x;
    }
    else
        printf("Queueoverflow");
}

int isEmpty()
{
    return top < 0;
}

int dequeue()
{
    if (!isEmpty())
    {
        int n = queue[0];

        for (int i = 0; i < top; i++)
        {
            queue[i] = queue[i + 1];
        }

        top--;
        return n;
    }
    else
    {
        printf("Queue is already empty!");
        return -99999;
    }
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(4);
    enqueue(8);
    enqueue(7);
    printf("isempty: %d\n", isEmpty());
    print();

    dequeue();
    printf("\nisempty: %d\n", isEmpty());
    print();

    dequeue();
    printf("\nisempty: %d\n", isEmpty());
    print();

    dequeue();
    printf("\n");

    dequeue();

    return 0;
}