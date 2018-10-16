/**
 * Classe que representa uma árvore de segmentos com range maximum query (RMQ).
 *
 * Autor: Edson Alves
 * Data: 16/10/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

using namespace std;
using std::vector;

template<typename T>
class SegmentTree
{
    int n;
    vector<T> tree, lazy;

public:
    SegmentTree(int N)
        : n(N), tree(4*n, 0), lazy(4*n, 0)      // 4N is an upper bound to the number of nodes
    {
    }

    T RMQ(int i, int j)
    {
        return RMQ(1, 0, n - 1, i, j);
    }

    void update(int i, int j, T v)              // Sets all elements in [i, j] to v
    {
        update(1, 0, n - 1, i, j, v);
    }

private:
    int left(int p)
    {
        return 2*p;
    }

    int right(int p)
    {
        return 2*p + 1;
    }

    T RMQ(int p, int L, int R, int a, int b)
    {
        // Lazy propagation
        if (lazy[p])
        {
            tree[p] = lazy[p];

            if (L < R)                      // If its not a leaf and not zero, propagates
            {
                lazy[left(p)] = lazy[p];
                lazy[right(p)] = lazy[p];
            }

            lazy[p] = 0;
        }

        if (a > R or b < L)             // Base case: [a, b] intersection [L, R] is empty
            return 0;

        if (a <= L and R <= b)          // Base case: [a, b] contain [L, R]
            return tree[p];

        T x = RMQ(left(p), L, (L + R)/2, a, b);
        T y = RMQ(right(p), (L + R)/2 + 1, R, a, b);

        return max(x, y);
    }

    void update(int p, int L, int R, int a, int b, T value)
    {
        // Lazy propagation
        if (lazy[p])
        {
            tree[p] = lazy[p];

            if (L < R)                      // If its not a leaf and not zero, propagates
            {
                lazy[left(p)] = lazy[p];
                lazy[right(p)] = lazy[p];
            }

            lazy[p] = 0;
        }

        if (a > R or b < L)                     // Base case: [a, b] intersection [L, R] is empty
            return;

        if (a <= L and R <= b)                  // Base case: [a, b] contain [L, R]
        {
            tree[p] = value;

            if (L < R)                          // If its not a leaf and not zero, propagates
            {
                lazy[left(p)] = value;
                lazy[right(p)] = value;
            }

            return;
        }
 
        update(left(p), L, (L + R)/2, a, b, value);
        update(right(p), (L + R)/2 + 1, R, a, b, value);

        tree[p] = max(tree[left(p)], tree[right(p)]);
    } 
};

#endif
