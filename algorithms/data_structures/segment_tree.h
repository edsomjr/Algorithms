/**
 * Classe que representa uma árvore de segmentos.
 *
 * Suporta range queries e point updates, com implementação recursiva.
 *
 * Autor: Edson Alves
 * Data: 06/05/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

using std::vector;


template<typename T>
class SegmentTree
{
    int n;
    vector<T> tree;

public:
    SegmentTree(int N)
        : n(N), tree(4*n, 0)      // 4N is a upper bound to the number of nodes
    {
    }

    T sum(int i, int j)
    {
        return sum(1, 0, n - 1, i, j);
    }

    void add(int a, T value)
    {
        add(1, 0, n - 1, a, value);
    }

    int size() const
    {
        return tree.size();
    }

private:

    int left(int p)
    {
        return 2 * p;
    }

    int right(int p)
    {
        return 2 * p + 1;
    }

    T sum(int p, int L, int R, int i, int j)
    {
        if (i > R or j < L)         // [i, j] don't intersect [L, R]
            return 0;

        if (i <= L and R <= j)      // [i, j] contain [L, R]
            return tree[p];

        T a = sum(left(p), L, (L + R)/2, i, j);
        T b = sum(right(p), (L + R)/2 + 1, R, i, j);

        return a + b;
    }

    void add(int p, int L, int R, int a, T value)
    {
        if (a > R or a < L)         // Base case: a is not int [L, R]
            return;
        
        tree[p] += value;

        if (L == R)                 // Base case: we reached a leaf
            return;

        add(left(p), L, (L+R)/2, a, value);
        add(right(p), (L+R)/2 + 1, R, a, value);
    } 
};

#endif
