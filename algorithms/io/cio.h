/**
 * Métodos de entrada/saída em console utilizando I/O da linguagem C.
 *
 * Autor: Edson Alves
 * Data: 10/02/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef CIO_H
#define CIO_H

#include <stdio.h>

#define MAX 1000010

int cio_buffer[MAX];

int read()
{
    int x, n = 0;

    while (scanf("%d", &x) != EOF)
        cio_buffer[n++] = x;

    return n;
}

void write(int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d\n", cio_buffer[i]);
};

#endif
