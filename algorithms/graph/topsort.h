/**
 * Implementação do algoritmo de geração de ordenação topológica via DFS.
 *
 * Autor: Edson Alves
 * Data: 31/10/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef DFS_TOPSORT_H
#define DFS_TOPSORT_H

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

typedef enum { UNVISITED, VISITED, PROCESSED } State;

bool dfs(const vector<int> adj[], vector<int>& rorder, int u, vector<State>& states)
{
    states[u] = VISITED;

    for (const auto& v : adj[u])
    {
        // Ciclo detectado: não há uma ordenação topológica
        if (states[v] == VISITED)
            return false;

        if (states[v] == UNVISITED)
            // Ciclo detectado: não há uma ordenação topológica
            if (not dfs(adj, rorder, v, states))
                return false;
    }
    
    rorder.push_back(u);
    states[u] = PROCESSED;

    return true;
}

vector<int> topsort(const vector<int> adj[], int N)
{
    vector<State> states(N + 1, UNVISITED);
    vector<int> rorder;

    for (int u = 1; u <= N; ++u)
        if (states[u] == UNVISITED)
            if (not dfs(adj, rorder, u, states))
                return vector<int>();
 
    // A ordenação é encontrada em ordem reversa
    reverse(rorder.begin(), rorder.end());

    return rorder;
}

#endif
