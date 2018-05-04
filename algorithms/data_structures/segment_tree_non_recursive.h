/**
 * Classe que representa uma árvore de segmentos.
 *
 * Esta versão suporta range queries e point updates e não usa recursão. Baseada no exemplo
 * dado no livro Competitive Programmers Handbook's, pg. 89.
 *
 * Autor: Edson Alves
 * Data: 04/05/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <util/bitwise_operations.h>

using std::vector;


template<typename T>
class SegmentTree
{
    int n;
    vector<T> tree;

public:
    SegmentTree(int N)
        : n(least_power_of_2_greater_or_equals(N)), tree(2*n, 0)
    {
    }

    void add(int i, int v)                          // Adds v to position i
    {
        int a = i + n;

        tree[a] += v;                               // Update the leaf

        while (a >>= 1)
            tree[a] = tree[2*a] + tree[2*a + 1];    // Update its parents
    }

    T sum(int i, int j)
    {
        int a = i + n, b = j + n;       // The leaves are in second half of tree array
        T s = 0;

        while (a <= b)
        {
            if (a & 1)                  // a is a right child and must be added to the total
                s += tree[a++];

            if (not (b & 1))            // b is a left child and must be added to the total
                s += tree[b--];

            // If a is a left child of b is a right child the parent node covers them 

            // Move up one level 
            a /= 2;
            b /= 2;
        }

        return s;
    }

    int size() const
    {
        return n;
    }
};

#endif
