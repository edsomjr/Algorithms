/**
 * Classe Fenwick (BIT) Tree
 *
 * Esta versão mais simples suporta Point Updates com Range Queries.
 *
 * Autor: Edson Alves
 * Data: 04/09/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <cstring>

using namespace std;

typedef long long ll;

#define FENWICK_TREE_MAX 1000005

ll tree[FENWICK_TREE_MAX];

inline ll least_significative_bit(ll n) { return n & (-n); }

class FenwickTree
{
public:
    FenwickTree(ll N)
        : m_N(N)
    {
        memset(tree, 0, (N + 1) * sizeof(ll));
    }

    ll RSQ(ll a, ll b)
    {
        return a == 1 ? RSQ(b) : RSQ(b) - RSQ(a - 1);
    }

    void update(ll k, ll v)
    {
        while (k <= m_N)
        {
            tree[k] += v;
            k += least_significative_bit(k);
        }
    }

private:
    ll RSQ(ll b)
    {
        ll sum = 0;

        while (b)
        {
            sum += tree[b];
            b -= least_significative_bit(b);
        }

        return sum;
    }

private:
    ll m_N;
};

#endif
