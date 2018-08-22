/**
 * Algoritmo de Prim para árvore mínima geradora.
 *
 * Autor: Edson Alves
 * Data: 26/04/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef PRIM_H
#define PRIM_H

#define UDFS_MAX_N 1000005

#include <graph.h>
#include <queue>

using std::priority_queue;
using ii = pair<int, int>;
using std::greater;

int prim(const Graph& g)
{
    vi taken(g.V() + 1, 0);
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    int cost = 0;
    
    taken[1] = 1;

    for (auto v : g.adj()[u])
        if (not taken[v])
            pq.push(ii(v.second, v.first));

    while (not pq.empty())
    {
        ii edge = pq.top();
        pq.pop();

        int w = edge.first;
        int u = edge.second;
        
        if (not taken[u])
        {
            taken[u] = 1;
            cost += w;

            for (auto v : g.adj()[u])
                if (not taken[v])
                    pq.push(ii(v.second, v.first));
        }
    }

    return cost;
}

#endif
