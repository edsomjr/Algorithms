/**
 * Classe que contém algoritmos para o problema max 2D range sum.
 *
 * Os pontos P e Q representam o canto superior esquerdo e o ponto inferior
 * direito do retângulo, respectivamente.
 *
 * Autor: Edson Alves
 * Data: 28/09/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MAX_2D_RANGE_SUM_H
#define MAX_2D_RANGE_SUM_H

#include <iostream>
#include <vector>

using std::vector;
using std::max;

#define MAX_N 110

class Max2DRangeSum
{
public:
 
    /* Algoritmo de Busca Completa para o problema. Lento, mas correto.
     *
     * Complexidade: O(n^6)
     */
    static int cs(const int A[][MAX_N], int m, int n)
    {
        int max_sum = -(1 << 30);

        // Escolhe a região retangular
        for (int px = 0; px < m; ++px)
        for (int py = 0; py < n; ++py)
        for (int qx = px; qx < m; ++qx)
        for (int qy = py; qy < n; ++qy)
        {
            int sum = 0;

            // Computa a soma da região retangular
            for (int i = px; i <= qx; ++i)
            for (int j = py; j <= qy; ++j)
                sum += A[i][j];

            max_sum = max(sum, max_sum);
        }

        return max_sum;
    }

    /* Algoritmo DP para o problema.  Pré-computa as somas acumuladas
     * e depois testa todos os pares de índices possíveis em busca da 
     * maior soma. Evita a soma de um termo múltiplas vezes utilizando o
     * princípio a inclusão-exclusão.
     *
     * Obs.: o algoritmo irá modificar a matriz de entrada para guardar as
     * somas acumuladas.
     *
     * Complexidade: O(n^4)
     */
    static int dp(int A[][MAX_N], int m, int n)
    {
        // Pré-computa as somas acumuladas
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 and j > 0) A[i][j] -= A[i - 1][j - 1];
            }

        // Testa todos os pares possíveis: 
        int max_sum = -(1 << 30);

        for (int px = 0; px < m; ++px)
        for (int py = 0; py < n; ++py)
        for (int qx = px; qx < m; ++qx)
        for (int qy = py; qy < n; ++qy)
        {
            int sum = A[qx][qy];

            if (px > 0) sum -= A[px - 1][qy];
            if (py > 0) sum -= A[qx][py - 1];
            if (px > 0 and py > 0) sum += A[px - 1][py - 1]; 

            max_sum = max(sum, max_sum);
        }

        return max_sum;
    }
};

#endif
