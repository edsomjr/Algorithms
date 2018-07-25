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

using namespace std;

template<class T>
class IO
{
public:
    static vector<T> read()
    {
        vector<T> ns;
        T n;

        while (cin >> n)
            ns.push_back(n);

        return ns;
    }

    static void write(const vector<T>& ns)
    {
        for (const T& n : ns)
            cout << n << '\n';
    }
};

#endif
