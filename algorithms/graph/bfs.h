/**
 * Implementação do BFS em lista de adjacências.
 *
 * Autor: Edson Alves
 * Data: 25/02/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <queue>

using std::queue;

#define INF -1

typedef vector<int> vi;

void bfs(int s, const Graph& g)
{
    vi dist(g.V() + 1, INF);
    dist[s] = 0; 

    queue<int> q;
    q.push(s);

    while (not q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : g.adj()[u])
        {
            if (dist[v.first] == INF)
            {
                dist[v.first] = dist[u] + 1;
                q.push(v.first);
            }
        }
    }
}

#endif
