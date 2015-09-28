/**
 * Classe UDFS (Union-Find Disjoint Sets)
 *
 * Autor: Edson Alves
 * Data: 31/08/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef UNION_FIND_H
#define UNION_FIND_H

#define UDFS_MAX_N 1000005

int parent[UDFS_MAX_N];
int rank[UDFS_MAX_N];

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

#endif
