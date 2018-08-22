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

#include "dfs.h"

int connected_components(const Graph& g)
{
    int cc = 0;
    vi states(g.V() + 1, UNVISITED);

    for (int i = 1; i <= g.V(); ++i)
    {
        if (states[i] == UNVISITED)
        {
            printf("CC %d:", ++c);
            dfs_rec(i, states, g);
            printf("\n");
        }
    }
}

#endif
