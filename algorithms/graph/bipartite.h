/**
 * Implementação do algoritmo que verifica se um grafo é bipartido ou não.
 *
 * Autor: Edson Alves
 * Data: 27/09/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef BIPARTITE_H
#define BIPARTITE_H

#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 }, NONE = 0, BLUE = 1, RED = 2;
int color[MAX];
vector<int> adj[MAX];
bitset<MAX> visited;

bool bfs(int s)
{
    queue<int> q;
    q.push(s);
    color[s] = BLUE;
    
    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        for (const auto& v : adj[u])
            if (color[v] == NONE)
            {
                color[v] = 3 - color[u];
                q.push(v);
            } else if (color[v] == color[u])
                return false;
    }

    return true;
}

bool is_bipartite(int N)
{
    for (int u = 1; u <= N; ++u) 
        color[u] = NONE;

    for (int u = 1; u <= N; ++u) 
        if (color[u] == NONE and not bfs(u))
            return false;

    return true;
}

#endif
