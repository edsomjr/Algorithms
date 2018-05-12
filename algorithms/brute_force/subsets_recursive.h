/**
 * Rotina que processa todos os 2^n subconjuntos de um conjunto de N elementos.
 *
 * Baseada no exemplo dado no livro Competitive Programmers Handbook's, pg. 47.
 *
 * Autor: Edson Alves
 * Data: 04/05/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef SUBSETS_H
#define SUBSETS_H

#include <vector>

using std::vector;

template<typename T>
void search(int index, int N, vector<int>& subset, vector<T>& results, T (*process)(const vector<int>&))
{
    if (index == N)
        results.push_back(process(subset));
    else
    {
        search(index + 1, N, subset, results, process);
        subset.push_back(index); 
        search(index + 1, N, subset, results, process);
        subset.pop_back(); 
    }
}

template<typename T>
vector<T> process_all_subsets(int N, T (*process)(const vector<int>&))
{
    vector<int> subset;
    vector<T> results;

    search(0, N, subset, results, process);

    return results;
} 

#endif
