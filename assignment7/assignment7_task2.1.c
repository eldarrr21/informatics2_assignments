#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int x)
{
    if (top < SIZE - 1)
    {

        top++;
        stack[top] = x;
    }
    else
        printf("Stackoverflow");
}

int isEmpty()
{
    return top < 0;
}

int pop()
{
    if (!isEmpty())
    {
        int n = stack[top];
        top--;
        return n;
    }
    else
    {
        printf("Stack is already empty!");
        return -99999;
    }
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    push(4);
    push(8);
    push(7);
    printf("isempty: %d\n", isEmpty());
    print();

    pop();
    printf("\nisempty: %d\n", isEmpty());
    print();

    pop();
    printf("\nisempty: %d\n", isEmpty());
    print();

    pop();
    printf("\n");

    pop();

    return 0;
}