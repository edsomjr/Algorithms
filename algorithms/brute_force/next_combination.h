/**
 * Rotina que gera as C(n, m) combinações.
 *
 * Baseada no artigo The Coolest Way To Generate Combinations, de Frank Ruskey e Aaron Williams.
 * Uma combinação será representada por uma string s de zeros e uns, onde s[i] = 1 indica que o
 * elemento i pertence à combinação. Cada combinação é gerada em O(1): a estratégia de chamar
 * prev_permutation() a partir da string inicial s = "11111...100000" tem complexidade O(n) por
 * combinação.
 *
 * Autor: Edson Alves
 * Data: 11/05/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <string>

// Na primeira chamada, a string combination deve ser nula (size == 0)
bool next_combination(int n, int m, std::string& combination, int& x, int& y)
{
    // Caso base: primeira combinação
    if (combination.empty())
    {
        combination = std::string(m, '1');
        combination.resize(n + 1, '0');

        x = -1;
        y = -1;

        return true;
    }

    // Caso base: inicialização de x e y
    if (y == -1)
    {
        combination[m] = '1';
        combination[0] = '0';
        x = 1;
        y = 0;

        return true;
    }
 
    // Caso base: não há mais combinações
    if (x == n - 1)
        return false;

    combination[x] = '0';
    combination[y] = '1';
    combination[0] = combination[x + 1];
    combination[x + 1] = '1';

    x = x * (1 - (combination[1] - '0') + (combination[1] - '0')*(combination[0] - '0')) + 1;
    y = (y + 1)*(combination[0] - '0');

    return true;
}

#endif
