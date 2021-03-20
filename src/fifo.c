#include "../includes/fifo.h"

#include <stdio.h>
#include <stdlib.h>

T_FIFO newFIFO()
{
    return NULL;
}

int isEmpty(T_FIFO f)
{
    return f == NULL;
}

T_FIFO enqueue(T_FIFO f, T_Elt value)
{
    T_Node * newNode = malloc(sizeof(T_Node));
    if(!newNode)
    {
        perror("malloc()");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->next = f;

    f = newNode;

    return f;
}

T_FIFO dequeue(T_FIFO f)
{
    T_FIFO temp = f;

    if (isEmpty(f))
        return NULL;

    if (isEmpty(f->next))
    {
        printf("Dequeued: %s\n", toString(temp->value));
        f = temp->next;
        free(temp);
        return NULL;
    }

    T_FIFO secondLast = f;
    while (secondLast->next->next != NULL)
        secondLast = secondLast->next;
    
    printf("Dequeued: %s\n", toString(secondLast->next->value));
    free(secondLast->next);
    secondLast->next = NULL;

    return f;
}

int getSize_r(T_FIFO f)
{
    if (isEmpty(f))
        return 0;
    return 1 + getSize_r(f->next);
}

int getSize(T_FIFO f)
{
    T_FIFO temp = f;

    int count = 0;
    while(temp)
    {
        ++count;
        temp = temp->next;
    }
    return count;
}