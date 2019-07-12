#include "LL.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
typedef struct {
    node_t * head;
    node_t * tail;
} LL_t;
*/

void LLappendNode(LL_t *intlist, node_t *newNode);

// Creates and returns a new, empty list
LL_t *LLcreate()
{
    LL_t *ret = malloc(sizeof(LL_t));
    if (ret != NULL)
    {
        ret->head = NULL;
        ret->tail = NULL;
    }
    return ret;
}

// Adds a new element to the tail end of a list
void LLappend(LL_t *intlist, int value)
{
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode != NULL)
    {
        newNode->data = value;
        LLappendNode(intlist, newNode);
    }
}

// Adds a new node_t to the tail end of a list
// Pre:  newNode != NULL
void LLappendNode(LL_t *intlist, node_t *newNode)
{
    if (newNode != NULL)
    {
        newNode->next = NULL;
        if (intlist->tail == NULL)
        {
            // empty list
            assert(intlist->head == NULL);
            intlist->head = newNode;
            intlist->tail = newNode;
        }
        else
        {
            // non empty list
            intlist->tail->next = newNode; // seg fault
            intlist->tail = newNode;
        }
    }
}

// Outputs the list elements in order from head to tail
void LLprint(LL_t *intlist)
{
    // for ( init ; entry ; increment ) {
    for (node_t *current = intlist->head; current != NULL; current = current->next)
    {
        printf(" %d", current->data);
    }
    putchar('\n');

    /*
    node_t * current = intlist->head;
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    putchar('\n');
    */
}

// Return 1 iff target in intlist; 0 otherwise
int LLsearch(LL_t *intlist, int target)
{
    // for ( init ; entry ; increment ) {
    /*
    for ( node_t * current = intlist->head; current != NULL ; current = current->next ) {
        printf(" %d", current->data);
    }
    putchar('\n');
    */

    /*
    node_t * current = intlist->head;
    while (current != NULL) {
        if (current->data == target) {
            return 1;
        }
        current = current->next;
    }
    return 0;
    */

    if (intlist->head == NULL)
    {
        assert(intlist->tail == NULL);
        return 0;
    }
    if (intlist->head->data == target)
    {
        return 1;
    }
    LL_t rest;
    rest.head = intlist->head->next;
    rest.tail = (rest.head == NULL) ? NULL : intlist->tail;
    return LLsearch(&rest, target);
}

// joins different L1, L2 such that L1 <- L1 + L2, frees L2
void LLcatenate(LL_t *L1, LL_t *L2)
{
    if (L2->head == NULL)
    {
        assert(L2->tail == NULL);
    }
    else if (L1->head == NULL)
    {
        assert(L1->tail == NULL);
        //L1->head = L2->head;
        //L1->tail = L2->tail;
        *L1 = *L2;
    }
    else
    {
        L1->tail->next = L2->head;
        L1->tail = L2->tail;
    }
    free(L2);
}

void LLquickSort(LL_t *intlist)
{
    // base case:  0 or 1 node
    if (intlist->head == intlist->tail)
    {
        return;
    }

    // remove the head from intlist (pivot)
    int pivot = intlist->head->data;
    node_t *pivot_node = intlist->head;
    intlist->head = intlist->head->next;

    // partition
    LL_t *first = LLcreate();
    LL_t *second = LLcreate();
    node_t *curr = intlist->head;
    node_t *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = NULL;
        if (curr->data <= pivot)
        {
            LLappendNode(first, curr);
        }
        else
        {
            LLappendNode(second, curr);
        }
        curr = next;
    }
    intlist->head = NULL;
    intlist->tail = NULL;

    //LLprint(first);
    //LLprint(second);

    LLquickSort(first);
    LLquickSort(second);

    // join
    LLcatenate(intlist, first);
    LLappendNode(intlist, pivot_node);
    LLcatenate(intlist, second);
}

// Pre/Post:  intlist is sorted; newNode contains data already
void LLinsertNode(LL_t *intlist, node_t *newNode)
{
    // list empty
    if (intlist->head == NULL)
    {
        assert(intlist->tail == NULL);
        intlist->head = newNode;
        intlist->tail = newNode;
        newNode->next = NULL;
    }
    else if (intlist->head->data >= newNode->data)
    {
        // new head
        newNode->next = intlist->head;
        intlist->head = newNode;
    }
    else
    {
        // typical case
        node_t *prev = intlist->head;
        node_t *curr = intlist->head->next;
        while (curr != NULL && curr->data < newNode->data)
        { // insertion pt found while is False
            curr = curr->next;
            prev = prev->next;
        }
        newNode->next = curr;
        prev->next = newNode;
        if (curr == NULL)
        {
            // new tail
            intlist->tail = newNode;
        }
    }
}

// Pre: intlist not sorted
// Post:  values in intlist are in sorted order
void LLinsertionSort(LL_t *intlist)
{
    // create a new [empty] list
    LL_t *newlist = LLcreate();

    // scan through all items and insert 'em
    node_t *curr = intlist->head;
    while (curr != NULL)
    {
        node_t *next = curr->next;
        LLinsertNode(newlist, curr);
        curr = next;
    }

    // recycle old list
    // swap
    LL_t tmp;
    tmp = *intlist;
    *intlist = *newlist;
    *newlist = tmp;
    free(newlist);
    //LLdestroy(newlist);
}

void spliceinto(LL_t *L, int x, int i)
{
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
    L->head = previous;
}

unsigned int numberOfEvens(LL_t *L)
{
    int result = 0;

    for (node_t *current = L->head; current != NULL; current = current->next)
    {
        // if data % 2 == 0, then it's a even number
        if (current->data % 2 == 0)
        {
            result++;
        }
    }

    return result;
}

void merge(LL_t *L1, LL_t *L2)
{
    LLcatenate(L1, L2);
    LLquickSort(L1);
}

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