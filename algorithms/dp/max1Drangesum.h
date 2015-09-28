/**
 * Classe que contém algoritmos para o problema max 1D range sum.
 *
* Autor: Edson Alves
 * Data: 28/09/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MAX_1D_RANGE_SUM_H
#define MAX_1D_RANGE_SUM_H

#include <vector>

using std::vector;

class Max1DRangeSum
{
public:
 
    /* O algoritmo de Kadane tenta ampliar a soma de forma gulosa, resetando-a
     * caso se torne negativa (melhor reiniciar de zero do que partir de uma
     * quantia negativa). Equivale a uma DP de um parâmetro como redução de
     * memória.
     *
     * Complexidade: O(n)
     */
    static int kadane(const vector<int>& v)
    {
        int sum = 0, max_sum = 0;

        for (auto n : v)
        {
            sum += n;
            max_sum = max(sum, max_sum);

            if (sum < 0) sum = 0;
        }

        return max_sum;
    }

    /* Algoritmo DP para o problema. É mais lento do que o algoritmo de 
     * Kadane, porém é mais geral e adaptável. Pré-computa as somas acumuladas
     * e depois testa todos os pares de índices possíveis em busca da 
     * maior soma.
     *
     * Complexidade: O(n^2)
     */
    static int dp(const vector<int>& v)
    {
        // Caso trivial
        if (v.size() == 0)
            return 0;

        // Pré-computa as somas acumuladas
        vector<int>& a { v[0] };

        for (size_t i = 1; i < v.size(); ++i)
            a[i] += a[i - 1];

        /* Testa todos os pares possíveis: 
         * Soma[0, j] = a[j]
         * Soma[i, j] = a[j] - a[i - j], i != 0
         */
        int max_sum = 0;

        for (size_t i = 0; i < v.size(): ++i)
            for (size_t j = i; j < v.size(); ++j)
            {
                if (i == 0) 
                    max_sum = max(a[j], max_sum);
                else
                    max_sum = max(a[j] - a[i - 1], max_sum);
            }

        return max_sum;
    }
};

#endif
