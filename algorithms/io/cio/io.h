/**
 * Métodos de entrada/saída em console utilizando I/O da linguagem C.
 *
 * Autor: Edson Alves
 * Data: 10/02/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef IO_H
#define IO_H

#include <cstdio>
#include <vector>

using std::vector;

class IO
{
public:
    vector<int> readInts() const
    {
        vector<int> v;
        int n;

        while (scanf("%d", &n) != EOF)
        {
            v.push_back(n);
        }

        return v;
    }

    void writeInts(const vector<int>& v) const
    {
        for (int i : v)
        {
            printf("%d\n", i);
        }
    }

    int countInts() const
    {
        vector<int> v = readInts();
        return v.size();
    }

    void echoInts() const
    {
        vector<int> v = readInts();
        writeInts(v);
    }
};

#endif
