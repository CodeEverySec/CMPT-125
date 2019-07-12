#include <stdlib.h>
#include <stdio.h>
#include "LL.h"

/*
1. Don't include main function when you submit
2. Don't do any changes in function header
*/

unsigned int removeNumber(LL_t *L, int target)
{
    node_t *current = L->head;

    // find the target in the head
    while (current != NULL && current->data == target)
    {
        L->head = current->next;
        current = L->head;
    }

    // while current is not reach to the end of the list
    while (current != NULL)
    {
        node_t *previous;
        // if taget not found
        // update previous and current
        while (current != NULL && current->data != target)
        {
            previous = current;
            current = current->next;
        }

        // reache end of the list
        // target not found
        if (current == NULL)
        {
            return 1;
        }

        // if current->data == target
        // previous, current, next
        // skip current
        // previous->next  points to current->next which is next
        previous->next = current->next;
        //Update current
        current = previous->next;

        return 0;
    }

    return 1;
}

unsigned int numberOfEvens(LL_t *L)
{
    // create a var for couting even numbers in the LinkList
    int result = 0;

    // iterate the list
    for (node_t *current = L->head; current != NULL; current = current->next)
    {
        // if data % 2 == 0, then it's a even number
        if (current->data % 2 == 0)
        {
            result++;
        }
    }

    // return the value
    return result;
}

void spliceinto(LL_t *L, int x, int i)
{
    // if the list head is not points to NULL
    if (L->head != NULL)
    {
        // calculate the linklist size first
        int size = 0;
        for (node_t *current = L->head; current != NULL; current = current->next)
        {
            size++;
        }

        // if we want to change the head
        if (i == 0)
        {
            node_t *new = malloc(sizeof(node_t));
            if (new != NULL)
            {
                new->data = x;
                node_t *temp = L->head;
                L->head = new;
                new->next = temp;
            }
        }
        // if the i > size
        // do nothing
        // since linklist at index i's data is not initialized yet
        else if (i < size)
        {
            // find the current node
            // i - 1
            node_t *current = L->head;
            for (int index = 0; index < i - 1; index++)
            {
                current = current->next;
            }

            // previous node
            // i
            node_t *previous = current->next;

            // create a new node
            node_t *new = malloc(sizeof(node_t));
            if (new != NULL)
            {
                new->data = x;

                // current points to the new node
                // new points to the previous node
                current->next = new;
                new->next = previous;
            }
        }
    }
}

void reverse(LL_t *L)
{
    // reverse the head and tail
    node_t *current = L->head;
    node_t *previous = NULL;
    node_t *next = NULL;

    while (current != NULL)
    {
        //store next node
        next = current->next;

        // change next of current
        current->next = previous;

        // move
        previous = current;
        current = next;
    }
    // set the head to the tail
    L->head = previous;
}

void merge(LL_t *L1, LL_t *L2)
{
    // merge two sorted array together, free L2
    LLcatenate(L1, L2);
    // sort the L1
    LLquickSort(L1);
}