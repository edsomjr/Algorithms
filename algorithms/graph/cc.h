/**
 * Implementação do algoritmo de identificação de componentes conectados
 * através do DFS.
 *
 * Autor: Edson Alves
 * Data: 25/02/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef CC_H
#define CC_H

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

vector<vector<int>> connected_components(int N)
{
    visited.reset();
    vector<vector<int>> ans;

    for (int u = 1; u <= N; ++u) 
    {
        if (not visited[u])
        {
            vector<int> cs;
            dfs(u, [&](int u) { cs.push_back(u); });
            ans.push_back(vector<int>(cs));
        }
    }

    return ans;
}

#endif
