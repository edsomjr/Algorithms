/**
 * Crivo de Eratóstenes para os primos menores que MAX.
 *
 * Autor: Edson Alves
 * Data: 26/10/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef ERATOSTHENES_H
#define ERATOSTHENES_H

using ll = long long;
using std::bitset;

const int MAX { 10000001 };

bitset<MAX> sieve;
int ps[MAX], pc = 0;

void precomp()
{
    ps[pc++] = 2;
    ps[pc++] = 3;

    // j caminha apenas em números que não são múltiplos nem de 3 e nem de 2
    for (ll j = 5, inc = 2; j < MAX; j += inc, inc = 6 - inc)
    {
        if (not sieve[j])
        {
            ps[pc++] = j;

            for (ll k = j * j; k < MAX; k += 2*j)
                sieve[k] = true;
        }
    }
}

#endif
