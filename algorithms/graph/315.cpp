#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

#define MAX 110
#define MAXL 4096
#define INF -1

#define UNVISITED  0

int adj[MAX][MAX];
int edges[MAX], dfs_num[MAX], dfs_low[MAX], parents[MAX], articulations[MAX];
int num_counter, root_children;
char line[MAXL];

void dfs(int u)
{
    dfs_low[u] = dfs_num[u] = ++num_counter;

    for (int i = 0; i < edges[u]; ++i)
    {
        int v = adj[u][i];

        if (dfs_num[v] == UNVISITED)
        {
            parents[v] = u;

            if (u == 1) ++root_children;

            dfs(v);

            if (dfs_low[v] >= dfs_num[u])
                articulations[u] = 1;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != parents[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    while (fgets(line, MAXL, stdin))
    {
        int N = atoi(line);

        if (N == 0)
            break;

        memset(edges, 0, sizeof edges);

        while (true)
        {
            fgets(line, MAXL, stdin);
            istringstream is(line);

            int u;
            is >> u;

            if (u == 0)
                break;

            int v;

            while (is >> v)
            {
                adj[u][edges[u]++] = v;
                adj[v][edges[v]++] = u;
            }
        } 

        memset(dfs_num, UNVISITED, sizeof dfs_num);
        memset(dfs_low, UNVISITED, sizeof dfs_low);
        memset(parents, 0, sizeof parents);
        memset(articulations, 0, sizeof articulations);
        num_counter = root_children = 0;

        dfs(1);

        articulations[1] = (root_children > 1 ? 1 : 0);

        int points = 0;

        for (int i = 1; i <= N; ++i)
            points += articulations[i];

        printf("%d\n", points);
    }

    return 0;
}
