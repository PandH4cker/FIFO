#include "../includes/elt.h"
#include "../includes/fifo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv)
{
    T_FIFO f = newFIFO();
    if (isEmpty(f))
        printf("FIFO is empty\n");
    
    if (argc < 1)
    {
        fprintf(stderr, "You must pass integers\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i)
        f = enqueue(f, atoi(argv[i]));

    printf("Taille_r: %d\n", getSize_r(f));
    printf("Taille_i: %d\n", getSize(f));

    while (f != NULL)
        f = dequeue(f);

    free(f);
    return EXIT_SUCCESS;
}