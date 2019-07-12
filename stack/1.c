// ADT queue
// N is the maximum length of the array
#include <stdio.h>
#include <stdlib.h>
#define N 100;

typedef struct
{
    // head
    int front;
    // tail
    int end;
    // size
    int size;
    // N
    int max;
    // pointer to the array
    int *data;
} queue_t;

queue_t *create()
{
    queue_t *arr = malloc(sizeof(queue_t));
    if (arr != NULL)
    {
        arr->max = N;
        arr->size = 0;
        arr->front = 0;
        arr->end = arr->max - 1;
        arr->data = malloc(arr->max * sizeof(int));
        if (arr->data != NULL)
        {
            return arr;
        }
    }

    return NULL;
}

// prints the entire queue Q from front to back
void print(queue_t *Q)
{
    for (int i = Q->front; i <= Q->end; i++)
    {
        printf("%d\n", Q->data[i]);
    }
}

// enqueues the element x into queue Q
// if unsuccessful, return -1, else return 1
int enqueue(queue_t *Q, int x)
{
    if (Q->size < Q->max)
    {
        // add element to the end
        Q->end = (Q->end + 1) % (Q->max);
        Q->data[Q->end] = x;
        Q->size = Q->size + 1;
        return 1;
    }

    return -1;
}

// returns 1 (true) or 0 (false) depending on emptiness of the queue Q
int isEmpty(queue_t *Q)
{
    if (Q->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// dequeues the next integer from front of the queue
//  if unsuccessful, return null
int *dequeue(queue_t *Q)
{
    if (isEmpty(Q) == 0)
    {
        Q->front = (Q->front + 1) % Q->max;
        Q->size = Q->size - 1;
        return Q->data;
    }

    return NULL;
}

// returns the number of items currently in the queue
unsigned int size(queue_t *Q)
{
    return Q->size;
}

int main()
{
    queue_t *arr = create();

    enqueue(arr, 10);
    enqueue(arr, 20);
    enqueue(arr, 30);
    enqueue(arr, 40);
    enqueue(arr, 50);

    dequeue(arr);

    print(arr);

    int result = isEmpty(arr);
    printf("Empty: %d\n", result);
    printf("Size: %d\n", size(arr));

    return 0;
}
