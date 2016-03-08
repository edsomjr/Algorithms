/**
 * Implementação do algoritmo de verificação das propriedades das arestas de um
 * grafo através do DFS.
 *
 * Autor: Edson Alves
 * Data: 08/03/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GRAPH_CHECK_H
#define GRAPH_CHECK_H

#include "graph.h"

typedef vector<int> vi;

#define UNVISITED   0
#define VISITED     1
#define EXPLORED    2

void check(const Graph& g, vi& states, vi& parents, int u)
{
    states[u] = EXPLORED;

    for (auto v : g.adj()[u])
    {
        switch (states[v.first]) {
        case UNVISITED: // Tree edge
            parents[v.first] = u;
            check(g, states, parents, v.first);
            break;

        case VISITED: // Forward edge
            printf("Forward: (%d, %d)\n", u, v.first);
            break;

        case EXPLORED: // Back edge
            if (v.first == parents[u])
                printf("Bidirecional edge (%d, %d)\n", u, v.first);
            else
                printf("Back edge/cycle (%d, %d)\n", u, v.first);
            break;
        }
    }

    states[u] = VISITED;
}

void check(const Graph& g, int u)
{
    vi states;
    states.assign(g.V() + 1, UNVISITED);

    vi parents;
    parents.reserve(g.V() + 1);

    for (int i = 0; i <= g.V(); ++i)
        parents[i] = i;

    check(g, states, parents, u);
}

#endif
