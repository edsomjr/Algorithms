/**
 * Classe que contém algoritmos para o problema LIS (longest increasing
 * subsequence).
 *
 * Autor: Edson Alves
 * Data: 01/10/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef LIS_H
#define LIS_H

#include <vector>
#include <iostream>
#include <algorithm>

#define LIS_MAX_N 1000010

int lis[LIS_MAX_N], index[LIS_MAX_N], parent[LIS_MAX_N];

using std::vector;
using std::max;
using std::lower_bound;

class LIS
{
public:
 
    /* O algoritmo DP tem por estado LIS(i), que contém o tamanho da maior
     * subsequencia crescente que termina no índice i do array base.
     * Cada etapa tenha estender as sequências anteriores, escolhendo a
     * maior delas possível.
     *
     * Complexidade: O(n^2)
     */
    static int dp(const vector<int>& v)
    {
        size_t N = v.size();
        int max_len = 0;

        for (size_t i = 0; i < N; ++i)
        {
            lis[i] = 1;

            for (size_t j = 0; j < i; ++j)
            {
                if (v[i] >= v[j])
                    lis[i] = max(lis[j] + 1, lis[i]);
            }

            max_len = max(lis[i], max_len);
        }
 
        return max_len;
    }

    /* A solução gulosa com D&C mantém um vetor ordenado (lis) que contém
     * o menor elemento que encerra uma subsequência de comprimento i, e
     * procurar pelo maior elemento menor do que A[i] para tentar ampliar
     * ou melhorar a sequência lis.
     *
     * Complexidade: O(n log k), k - comprimento de lis
     */
    static int greedy(const vector<int>& A)
    {
        lis[0] = A[0];
        index[0] = 0;
        parent[0] = 0;
        int k = 1;

        for (size_t i = 1; i < A.size(); ++i)
        {
            parent[i] = i;

            auto it = lower_bound(lis, lis + k, A[i]);

            if (it == lis + k)
            {
                parent[i] = index[k - 1];
                lis[k] = A[i];
                index[k++] = i;
            } else
            {
                int pos = it - lis;

                if (lis[pos] > A[i])
                {
                    lis[pos] = A[i];
                    index[pos] = i;

                    if (pos > 0)
                        parent[i] = index[pos - 1];
                }
            }
        }

        return k;
    }
};

#endif
