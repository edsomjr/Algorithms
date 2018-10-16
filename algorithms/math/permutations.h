/**
 * Funções para permutações de N elementos 1, 2, ..., N
 *
 * Autor: Edson Alves
 * Data: 16/10/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

using std::vector;

// Decompose p in disjoint cycles
vector<vector<int>> cycles(const int p[], int N)
{
    vector<vector<int>> cs;
    vector<char> found(N + 1, 0);

    for (int n = 1; n <= N; ++n)
    {
        if (found[n])
            continue;

        vector<int> c;

        int x = n;

        found[x] = 1;
        c.push_back(x);

        while (p[x] != c.front())
        {
            x = p[x];
            found[x] = 1;
            c.push_back(x);
        }

        cs.push_back(c);
    }

    return cs;
}

// Return a permutation from disjoint cycles
vector<int> from_cycles(const vector<vector<int>>& cs, int N)
{
    vector<int> p(N + 1, 0);

    for (const auto& c : cs)
    {
        for (size_t i = 0; i < c.size(); ++i)
            p[c[i]] = c[(i + 1) % c.size()];
    }

    return p;
}

// Return a permutation q such as q[q[i]] = p[i]
vector<int> square_root(const int p[], int N)
{
    auto cs = cycles(ps, N);

    // Sort cycles by size
    sort(cs.begin(), cs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size(); });

    vector<vector<int>> sr;
    vector<int> res;

    for (size_t i = 0; i < cs.size(); ++i)
    {
        auto c = cs[i];
        auto N = c.size();

        // Even cycles of same size must be merged in a cycle of size 2N
        if (N % 2 == 0)
        {
            if (i == cs.size() - 1 or cs[i + 1].size() != N)
                return res;

            auto d = cs[i + 1];
            vector<int> r;

            for (size_t i = 0; i < N; ++i)
            {
                r.push_back(c[i]);            
                r.push_back(d[i]);            
            }

            sr.push_back(r);
            ++i;
        } else
        {
            // Odd cycles must be interleaved
            vector<int> r(c.size());

            if (c.size() == 1)
                r = c;
            else {
                for (size_t i = 0; i < N; i++)
                    r[2*i % c.size()] = c[i];
            }

            sr.push_back(r);
        }
    }

    res = from_cycles(sr, N);
    return res;
}

#endif

