/**
 * Métodos de entrada/saída em console.
 *
 * Autor: Edson Alves
 * Data: 11/02/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef IO_NAIVE_H
#define IO_NAIVE_H

#include <iostream>
#include <vector>

template<class T>
class IO
{
public:
    std::vector<T> read() const
    {
        std::vector<T> v;
        T n;

        while (std::cin >> n)
        {
            v.push_back(n);
        }

        return v;
    }

    void write(const std::vector<T>& v) const
    {
        for (T t : v)
        {
            std::cout << t << std::endl;
        }
    }

    int count() const
    {
        std::vector<T> v = read();
        return v.size();
    }

    void echo() const
    {
        std::vector<T> v = read();
        write(v);
    }
};

#endif
