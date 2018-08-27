/**
 * Implementação do DFS em lista de adjacências.
 *
 * Autor: Edson Alves
 * Data: 12/02/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef DFS_H
#define DFS_H

#include <bitset>
#include <vector>
#include <functional>

using namespace std;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];

// a variável visited deve ser inicializada com falso (visited.reset()) antes da chamada
// desta função
void dfs(int u, function<void(int)> process)
{
    if (visited[u])
        return;

    visited[u] = true;
    process(u);

    for (const auto& v : adj[u])
        dfs(v, process);
}

#endif
