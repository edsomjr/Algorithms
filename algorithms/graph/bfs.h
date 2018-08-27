/**
 * Implementação do BFS em lista de adjacências.
 *
 * Autor: Edson Alves
 * Data: 25/02/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef BFS_H
#define BFS_H

#include <queue>
#include <bitset>
#include <vector>
#include <functional>

using namespace std;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];
int dist[MAX];

void bfs(int s, function<void(int)> process)
{
    queue<int> q;

    dist[s] = 0; 
    visited[s] = true;
    q.push(s);

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        process(u);

        for (const auto& v : adj[u])
        {
            if (not visited[v])
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

#endif
