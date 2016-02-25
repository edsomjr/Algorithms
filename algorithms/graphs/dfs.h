/**
 * Implementação do DFS em lista de adjacências.
 *
 * Autor: Edson Alves
 * Data: 12/02/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef DFS_H
#define DFS_H

#include "graph.h"

#define UNVISITED   0
#define VISITED     1

typedef vector<int> vi;

void dfs_rec(int u, vi& states, const Graph& g)
{
    states[u] = VISITED;
    printf(" %d", u);

    for (auto v : g.adj()[u])
    {
        if (states[v.first] == UNVISITED)
            dfs_rec(v.first, states, g);
    }
}

vi dfs(int u, const Graph& g)
{
    vi states;
    states.assign(g.V() + 1, UNVISITED);

    dfs_rec(u, states, g);

    return states;
}

#endif
