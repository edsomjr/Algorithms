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

#define BUFFER_SIZE 4096

using std::vector;

class BufferedIO
{
public:
    vector<int> readInts() const
    {
        vector<int> v;
        char buffer[BUFFER_SIZE];
        int n = 0, readed = 0, bytes = 0, signal = 1;

        while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, stdin)))
        {
            for (int i = 0; i < bytes; i++)
            {
                char c = buffer[i];

                if (isdigit(c))
                {
                    n *= 10;
                    n += (c - '0');
                    readed++;
                } else if (c == '-')
                {
                    signal = -1;
                } else if (readed)
                {
                    v.push_back(n*signal);
                    n = 0;
                    signal = 1;
                    readed = 0;
                }
            }
        }

        if (readed)
        {
            v.push_back(n*signal);
        }

        return v;
    }

    void writeInts(const vector<int>& v) const
    {
        char buffer[BUFFER_SIZE];
        int bytes = 0;

        for (int i : v)
        {
            if (BUFFER_SIZE - bytes < 15)
            {
                fwrite(buffer, bytes, sizeof(char), stdout);
                bytes = 0;
            }

            bytes += sprintf(buffer + bytes, "%d\n", i);
        }

        if (bytes)
        {
            fwrite(buffer, bytes, sizeof(char), stdout);
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

    vector<long long> readLLs() const
    {
        vector<long long> v;
        char buffer[BUFFER_SIZE];
        int readed = 0, bytes = 0, signal = 1;
        long long n = 0;

        while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, stdin)))
        {
            for (int i = 0; i < bytes; i++)
            {
                char c = buffer[i];

                if (isdigit(c))
                {
                    n *= 10;
                    n += (c - '0');
                    readed++;
                } else if (c == '-')
                {
                    signal = -1;
                } else if (readed)
                {
                    v.push_back(n*signal);
                    n = 0;
                    signal = 1;
                    readed = 0;
                }
            }
        }

        if (readed)
        {
            v.push_back(n*signal);
        }

        return v;
    }

    void writeLLs(const vector<long long>& v) const
    {
        char buffer[BUFFER_SIZE];
        int bytes = 0;

        for (long long i : v)
        {
            if (BUFFER_SIZE - bytes < 25)
            {
                fwrite(buffer, bytes, sizeof(char), stdout);
                bytes = 0;
            }

            bytes += sprintf(buffer + bytes, "%lld\n", i);
        }

        if (bytes)
        {
            fwrite(buffer, bytes, sizeof(char), stdout);
        }
    }
};

#endif
