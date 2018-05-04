/**
 * Classe que representa uma árvore de segmentos.
 *
 * Esta versão suporta apenas queries estáticas. Os elementos devem ser
 * preenchidos antes da instanciação da classe.
 *
 * Autor: Edson Alves
 * Data: 21/09/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <cstring>

using namespace std;

typedef long long ll;

#define SEGMENT_TREE_MAX 100005

ll st[4*SEGMENT_TREE_MAX];
ll elements[SEGMENT_TREE_MAX];

class SegmentTree
{
public:
    SegmentTree(int N)
        : m_N(N)
    {
        memset(st, 0, 4*(N + 1) * sizeof(ll));
        build(1, 0, N - 1);
    }

    ll RMQ(int i, int j)
    {
        return RMQ(1, 0, m_N - 1, i, j);
    }

private:
    ll m_N;

    int left(int p)
    {
        return 2 * p;
    }

    int right(int p)
    {
        return 2 * p + 1;
    }

    void build(int p, int L, int R)
    {
        if (L == R)
        {
            st[p] = L;
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        int a = st[left(p)], b = st[right(p)];
        st[p] = elements[a] <= elements[b] ? a : b;
    }

    int RMQ(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L)
        {
            return -1;
        }

        if (L >= i and R <= j)
        {
            return st[p];
        }

        int a = RMQ(left(p), L, (L + R)/2, i, j);
        int b = RMQ(right(p), (L + R)/2 + 1, R, i, j);

        if (a == -1)
        {
            return b;
        }

        if (b == -1)
        {
            return a;
        }

        return elements[a] <= elements[b] ? a : b;
    }
};

#endif
