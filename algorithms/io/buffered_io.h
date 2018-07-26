/**
 * Métodos de entrada/saída em console utilizando I/O da linguagem C.
 *
 * Autor: Edson Alves
 * Data: 10/02/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>

const int BUFFER_SIZE { 4096 };

using namespace std;

vector<int> read()
{
    vector<int> ns;
    char buffer[BUFFER_SIZE];
    int n = 0, digits = 0, bytes = 0, signal = 1;

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, stdin)))
    {
        for (int i = 0; i < bytes; i++)
        {
            char c = buffer[i];

            if (isdigit(c))
            {
                n *= 10;
                n += (c - '0');
                digits++;
            } else if (c == '-')
            {
                signal = -1;
            } else if (digits)
            {
                ns.push_back(n*signal);
                n = 0;
                signal = 1;
                digits = 0;
            }
        }
    }

    if (digits)
        ns.push_back(n*signal);

    return ns;
}

void write(const vector<int>& ns)
{
    char buffer[BUFFER_SIZE];
    int bytes = 0;

    for (int n : ns)
    {
        if (BUFFER_SIZE - bytes < 15)
        {
            fwrite(buffer, bytes, sizeof(char), stdout);
            bytes = 0;
        }

        bytes += sprintf(buffer + bytes, "%d\n", n);
    }

    if (bytes)
        fwrite(buffer, bytes, sizeof(char), stdout);
}

#endif
