/**
 * Algoritmo de Kruskall para árvore mínima geradora.
 *
 * Autor: Edson Alves
 * Data: 27/12/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef KRUSKALL_H
#define KRUSKALL_H

#define UDFS_MAX_N 1000005

#include <vector>

using std::vector;

int parent[UDFS_MAX_N];
int rank[UDFS_MAX_N];

typedef pair<int, int> ii;
vector< pair<int, ii> > edges;

class UnionFind
{
public:
    UnionFind(int N)
        : m_N(N), m_count(N)
    {
        for (int i = 1; i <= N; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    bool is_same_set(int i, int j)
    {
        return find_set(i) == find_set(j);        
    }

    void union_set(int i, int j)
    {
        if (is_same_set(i, j))
            return;

        int p = find_set(i);
        int q = find_set(j);

        if (rank[p] > rank[q])
            parent[q] = p;
        else if (rank[q] > rank[p])
            parent[p] = q;
        else 
        {
            parent[q] = p;
            ++rank[p];
        }

        --m_count;
    }

    int count() const { return m_count; }

    int find_set(int i)
    {
        int p = i;

        vector<int> ps;

        while (p != parent[p])
        {
            ps.push_back(p);
            p = parent[p];
        }

        for (auto x : ps)
        {
            parent[x] = p;
        }

        return p;
    }

private:
    int m_N;
    int m_count;
};

int kruskall(int V)
{
    sort(edges.begin(), edges.end());

    int cost = 0;
    UnionFind ufds(V);

    for (auto edge : edges)
    {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (not ufds.same_set(u, v))
        {
            cost += w;
            ufds.union_set(u, v);
        }
    }

    return cost;
}

#endif
