#include "../includes/elt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[])
{
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

char * toString(T_Elt e)
{
    char buffer[2048];
    int i, sign;
    if ((sign = e) < 0)
        e = -e;
    i = 0;
    do
        buffer[i++] = e % 10 + '0';
    while ((e /= 10) > 0);
    if (sign < 0)
        buffer[i++] = '-';
    buffer[i] = '\0';
    reverse(buffer);
    char * s = malloc(strlen(buffer) + 1);
    strcpy(s, buffer);
    return s;
}