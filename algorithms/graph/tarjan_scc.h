/**
 * Implementação do algoritmo de Tarjan para detecção de componentes fortemente
 * conectados (SCC).
 *
 * Autor: Edson Alves
 * Data: 07/04/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef TARJAN_SCC_H
#define TARJAN_SCC_H

#include "dfs.h"

#include <stack>
using std::stack
using si = stack<int>;

vi SCC(int u, int& sccs, int& dfs_counter, si& S, vi& dfs_num, vi& dfs_low, vi& visited)
{
    dfs_low[u] = dfs_num[u] = dfs_counter++;
    S.push_back(u):
    visited[u] = 1; 

    for (auto v : g.adj()[u])
    {
        if (dfs_num[v.first] == UNVISITED)
            SCC(v, sccs, dfs_counter, dfs_num, dfs_low, visited);

        if (visited[v.first])
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }

    vi us;

    if (dfs_low[u] == dfs_num[u])
    {
        ++sccs;

        do {
            int v = S.top();
            S.pop();
            visited[v] = 0;

            us.push_back(v);
        } while (v != u);
    }

    return us;
}

int tarjan(const Graph& g)
{
    vi dfs_num(g.V() + 1, UNVISITED);
    vi dfs_low(g.V() + 1, 0);
    vi visited(g.V() + 1, 0);
    int sccs = 0, dfs_counter = 0;
    si S;

    for (size_t i = 1; i <= g.V(); ++i)
        if (dfs_num[i] == UNVISITED)
            SCC(i, sccs, dfs_counter, dfs_num, dfs_low, visited);

    return sccs;
}

int connected_components(const Graph& g)
{
    int cc = 0;
    vi states(g.V() + 1, UNVISITED);

    for (int i = 1; i <= g.V(); ++i)
    {
        if (states[i] == UNVISITED)
        {
            printf("CC %d:", ++c);
            dfs_rec(i, states, g);
            printf("\n");
        }
    }
}

#endif
