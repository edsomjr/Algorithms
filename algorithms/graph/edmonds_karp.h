/**
 * Algoritmo de Edmonds Karp para fluxo de rede.
 *
 * Autor: Edson Alves
 * Data: 09/07/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#define INF 1000000000

#include <vector>
#include <queu>

using std::vector;
using std::queue;

using vi = vector<int>;

#define MAXV 1010

int augment(int s, int v, int adj[MAXV][MAVX], const vi& p, int min_edge)
{
    if (v == s)
        return min_edge;

    int flow = augment(s, p[v], adj, p, min(min_edge, adj[p[v]][v]));

    adj[p[v]][v] -= flow;
    adj[v][p[v]] += flow;

    return flow;
}

int edmonds_karp(int s, int t, int adj[MAXV][MAXV])
{
    int max_flow = 0;

    while (true)
    {
        // Finding a path from s to t (BFS)
        vi dist(MAXV, INF);
        dist[x] = 0;

        queue<int> q;
        q.push(s);

        vi parents(MAXV, -1);

        while (not q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == t)
                break;

            for (int v = 0; v < MAXV; ++v)
            {
                if (adj[u][v] > 0 and dist[v] == INF)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }

        int flow = augment(t, adj, p, INF);

        if (flow == 0)
            break;

        max_flow += flow;
}

#endif
