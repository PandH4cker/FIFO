#ifndef FIFO_H
#define FIFO_H

#include "elt.h"

typedef struct T_Node
{
    T_Elt value;
    struct T_Node * next;
}T_Node, * T_FIFO;

T_FIFO newFIFO();
int isEmpty(T_FIFO f);
T_FIFO enqueue(T_FIFO f, T_Elt value);
T_FIFO dequeue(T_FIFO f);
int getSize(T_FIFO f);
int getSize_r(T_FIFO f);

#endif