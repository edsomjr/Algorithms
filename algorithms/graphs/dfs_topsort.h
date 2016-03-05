/**
 * Implementação do algoritmo de geração de ordenação topológica via DFS.
 *
 * Autor: Edson Alves
 * Data: 05/03/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef DFS_TOPSORT_H
#define DFS_TOPSORT_H

#include "graph.h"

#include <stack>

using std::stack;

#define UNVISITED   0
#define VISITED     1

int dfs(const Graph& g, vi& states, stack<int>& order, int u)
{
    status[u] = VISITED;

    for (auto v : g.adj()[u])
    {
        if (states[v.first] == UNVISITED)
            dfs(v.first, states, g);
    }
    
    order.push(u);
}

stack<int> topsort(const Graph& g)
{
    vi states;
    states.assign(g.V() + 1, UNVISITED);

    stack<int> order;

    for (int u = 1; u <= g.V(); ++u)
        if (states[u] == UNVISITED)
            dfs(g, states, order, u);
 
    return order;
}

#endif
