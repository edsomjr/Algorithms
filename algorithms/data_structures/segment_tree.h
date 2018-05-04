/**
 * Classe que representa uma árvore de segmentos.
 *
 * Suporta range queries e point updates, com implementação recursiva.
 *
 * Autor: Edson Alves
 * Data: 06/05/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

using std::vector;


template<typename T>
class SegmentTree
{
    int n;
    vector<T> tree;

public:
    SegmentTree(int N)
        : n(N), tree(4*n, 0)      // 4N is a upper bound to the number of nodes
    {
    }


using namespace std;

typedef long long ll;

class SegmentTree
{
public:
    SegmentTree(const vector<ll>& a)
    {
        m_N = a.size();
        m_st.assign(4*m_N, 0);

        build(a, 1, 0, m_N - 1);
    }

    ll RMQ(int i, int j)
    {
        return RMQ(1, 0, m_N - 1, i, j);
    }

    void update(int a, int b, ll value)
    {
        update(1, 0, m_N - 1, a, b, value);
    }

private:
    vector<ll> m_st;
    int m_N;

    int left(int p)
    {
        return 2 * p;
    }

    int right(int p)
    {
        return 2 * p + 1;
    }

    ll merge(ll a, ll b)
    {
        return min(a, b);
    }

    ll inf() const
    {
        return LLONG_MAX;
    }

    void build(const vector<ll>& a, int p, int L, int R)
    {
        if (L == R)
        {
//cout << "defining st[" << p << "] as a[" << L << "] = " << a[L] << endl;
            m_st[p] = a[L];
            return;
        }

        build(a, left(p), L, (L + R)/2);
        build(a, right(p), (L + R)/2 + 1, R);

        m_st[p] = merge(m_st[left(p)], m_st[right(p)]);

//cout << "defining st[" << p << "] as merge = " << m_st[p] << endl;
    }

    ll RMQ(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L)
        {
            return inf();
        }

        if (L >= i and R <= j)
        {
            return m_st[p];
        }

        ll a = RMQ(left(p), L, (L + R)/2, i, j);
        ll b = RMQ(right(p), (L + R)/2 + 1, R, i, j);

        return merge(a, b);
    }

    void update(int p, int L, int R, int a, int b, ll value)
    {
        if (a > R || b < L)
            return;

        if (L == R)
        {
            m_st[p] += value;
            return;
        }

        update(left(p), L, (L+R)/2, a, b, value);
        update(right(p), (L+R)/2 + 1, R, a, b, value);

        
        m_st[p] = merge(m_st[left(p)], m_st[right(p)]);
    } 
};

#endif
