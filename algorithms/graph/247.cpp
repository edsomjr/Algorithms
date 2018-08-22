#include <iostream>
#include <cstring>
#include <map>

using namespace std;

#define MAX 100

#include <stack>
#include <vector>

#define UNVISITED 0
#define VISITED   1

using si = stack<int>;
using vi = vector<int>;

int adj[MAX][MAX];
int edges[MAX];

void SCC(int u, int& sccs, int& dfs_counter, si& S, vi& dfs_num, vi& dfs_low, vi& visited, map<int, string>& names)
{
    dfs_low[u] = dfs_num[u] = ++dfs_counter;
    S.push(u);
    visited[u] = 1; 
//printf("u = %d, low = %d, num = %d, edges = %d\n", u, dfs_low[u], dfs_num[u], edges[u]);
    for (int i = 0; i < edges[u]; ++i)
    {
        int v = adj[u][i];

        if (dfs_num[v] == UNVISITED)
            SCC(v, sccs, dfs_counter, S, dfs_num, dfs_low, visited, names);

        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

//printf("fechando u = %u, low = %d, num = %d\n", u, dfs_low[u], dfs_num[u]);
    vi us;

    if (dfs_low[u] == dfs_num[u])
    {
        ++sccs;
        int v;

        do {
            v = S.top();
            S.pop();
            visited[v] = 0;

            us.push_back(v);
        } while (v != u);
    }

//printf("us.size() = %lu\n", us.size());

    if (us.size() == 0)
        return;

    printf("%s", names[us[0]].c_str());

    for (size_t i = 1; i < us.size(); ++i)
        printf(", %s", names[us[i]].c_str());
        
    printf("\n");
}

int tarjan(int V, map<int, string>& names)
{
    vi dfs_num(V + 1, UNVISITED);
    vi dfs_low(V + 1, 0);
    vi visited(V + 1, 0);
    int sccs = 0, dfs_counter = 0;
    si S;

    for (int i = 1; i <= V; ++i)
    {
//printf("Processing [%s]\n", names[i].c_str());
        if (dfs_num[i] == UNVISITED)
            SCC(i, sccs, dfs_counter, S, dfs_num, dfs_low, visited, names);
    }

    return sccs;
}

int main()
{
    int n, m, test = 0;

    while (scanf("%d %d", &n, &m), n | m)
    {
        memset(edges, 0, sizeof edges);

        map<string, int> ids;
        map<int, string> names;

        int id = 0;

        while (m--)
        {
            char a[MAX], b[MAX];
            scanf("%s %s", a, b);

            if (ids.find(a) == ids.end())
            {
                ids[a] = ++id;
                names[id] = a;
            }

            if (ids.find(b) == ids.end())
            {
                ids[b] = ++id;
                names[id] = b;
            }

            int u = ids[a];
            int v = ids[b];

            adj[u][edges[u]++] = v;
        }

        if (test)
            printf("\n");

        printf("Calling circles for data set %d:\n", ++test);
        tarjan(n, names);
    }

    return 0;
}

