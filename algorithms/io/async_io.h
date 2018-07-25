/**
 * Métodos de entrada/saída em console.
 *
 * Autor: Edson Alves
 * Data: 09/02/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class IO
{
public:
    IO()
    {
        ios::sync_with_stdio(false);
    }

    vector<T> read() const
    {
        vector<T> ns;
        T n;

        while (cin >> n)
            ns.push_back(n);

        return ns;
    }

    void write(const vector<T>& ns) const
    {
        for (const T& n : ns)
            cout << n << endl;
    }
};

#endif
