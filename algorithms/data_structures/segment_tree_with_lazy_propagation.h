/**
 * Classe que representa uma árvore de segmentos.
 *
 * Esta versão suporta range updates com lazy propagation. 
 *
 * Autor: Edson Alves
 * Data: 30/09/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

using namespace std;
using std::vector;

#include <iostream>
#include <queue>
#include <tuple>

template<typename T>
class SegmentTree
{
    int n;
    vector<T> tree, lazy;

public:
    SegmentTree(int N)
        : n(N), tree(4*n, 0), lazy(4*n, 0)      // 4N is a upper bound to the number of nodes
    {
    }

    T sum(int i, int j)
    {
        return sum(1, 0, n - 1, i, j);
    }

    void add(int i, int j, T v)
    {
        add(1, 0, n - 1, i, j, v);
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

    T sum(int p, int L, int R, int a, int b)
    {
        // Lazy propagation
        if (lazy[p])
        {
            tree[p] += (R - L + 1) * lazy[p];

            if (L < R)                      // If its not a leaf and not zero, propagates
            {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }

            lazy[p] = 0;
        }

        if (a > R or b < L)             // Base case: [a, b] intersection [L, R] is empty
            return 0;

        if (a <= L and R <= b)          // Base case: [a, b] contain [L, R]
            return tree[p];

        T x = sum(left(p), L, (L + R)/2, a, b);
        T y = sum(right(p), (L + R)/2 + 1, R, a, b);

        return x + y;
    }

    void add(int p, int L, int R, int a, int b, T value)
    {
        // Lazy propagation
        if (lazy[p])
        {
            tree[p] += (R - L + 1) * lazy[p];

            if (L < R)                              // If its not a leaf and not zero, propagates
            {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }

            lazy[p] = 0;
        }

        if (a > R or b < L)                     // Base case: [a, b] intersection [L, R] is empty
            return;

        if (a <= L and R <= b)                  // Base case: [a, b] contain [L, R]
        {
            tree[p] += (R - L + 1) * value;

            if (L < R)                          // If its not a leaf and not zero, propagates
            {
                lazy[left(p)] += value;
                lazy[right(p)] += value;
            }

            return;
        }
 
        add(left(p), L, (L + R)/2, a, b, value);
        add(right(p), (L + R)/2 + 1, R, a, b, value);

        tree[p] = tree[left(p)] + tree[right(p)];
    } 

public:
    void print() const
    {
        queue<tuple<int, int, int, int, int>> q;

        q.emplace(1, 0, n - 1, tree[1], lazy[1]);

        while (not q.empty())
        {
            int p, a, b, v, L;

            tie(p, a, b, v, L) = q.front();
            q.pop();

            cout << "[" << a << ", " << b << "] = " << v << ", lazy = " << L << '\n';

            if (a < b)
            {
                q.emplace(2*p, a, (a + b)/2, tree[2*p], lazy[2*p]);
                q.emplace(2*p + 1, (a + b)/2 + 1, b, tree[2*p + 1], lazy[2*p + 1]);
            }
        }
    }
};

#endif
