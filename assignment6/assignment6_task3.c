#include <stdio.h>
#include <stdlib.h>
#define N 10

struct node
{
    int key;
    struct node *next;
};

struct node *convertArraytoLinkedList(int *arr, int n) // (a)
{
    struct node *head;
    head = malloc(sizeof(struct node));
    head->key = *(arr);

    struct node *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = malloc(sizeof(struct node));
        current = current->next;
        current->key = arr[i];
        current->next = NULL;
    }
    return head;
}

void print(struct node *curr) // (b)
{
    while (curr != NULL)
    {
        printf("%d ", curr->key);
        curr = curr->next;
    }
}

struct node *reverseLinkedList(struct node *head) // (c)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    /* Generating an array of N random integers */
    int *arr;
    arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        *(arr + i) = rand();
    }

    struct node *head = convertArraytoLinkedList(arr, N);

    printf("\nThe original: ");
    print(head);

    struct node *newHead = reverseLinkedList(head);

    printf("\nThe reversed: ");
    print(newHead);

    return 1;
}