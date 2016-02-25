/**
 * Implementação de um grafo por lista de adjacências
 *
 * Autor: Edson Alves
 * Data: 12/02/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

typedef pair<int, int> ii;  // (v, w) - vértice/peso
typedef vector<ii> vii;
typedef vector<vii> vvii;

class Graph
{
    int m_V;       // número de vértices
    vvii m_adj;    // lista de adjacências

public:
    Graph(int V) : m_V(V)
    {
        m_adj.assign(V + 1, vii());
    }

    void add_edge(int u, int v, int w = 1, bool bidirecional = false)
    {
        m_adj[u].push_back(ii(v, w));

        if (bidirecional)
            m_adj[v].push_back(ii(u, w));
    }

    int V() const { return m_V; }

    int E(bool bidirecional = false)
    {
        int sum = 0;

        for (auto v : m_adj)
            sum += v.size();

        if (bidirecional) sum /= 2;

        return sum;
    }

    const vvii& adj() const { return m_adj; }
};

#endif
