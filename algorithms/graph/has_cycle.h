/**
 * Rotinas de detecção de ciclos em grafos.
 *
 * Autor: Edson Alves
 * Data: 25/02/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef HAS_CYCLE_H
#define HAS_CYCLE_H

#include <iostream>
#include <functional>
#include <vector>
#include <bitset>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];

void dfs(int u, function<void(int)> process)
{
    if (visited[u]) return;
    visited[u] = true;

    process(u);

    for (const auto& v : adj[u])
        dfs(v, process);
}

bool has_cycle(int N)
{
    visited.reset();

    for (int u = 1; u <= N; ++u) 
    {
        if (not visited[u])
        {
            vector<int> cs;
            size_t edges = 0;

            dfs(u, [&](int u) {
                cs.push_back(u); 

                for (const auto& v : adj[u])
                    edges += (visited[v] ? 0 : 1);
            });

            // if edges == (cs.size() - 1) there is no cycle
            if (edges >= cs.size())
                return true;
        }
    }

    return false;
}

#endif
