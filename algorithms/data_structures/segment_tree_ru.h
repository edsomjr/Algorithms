/**
 * Classe que representa uma árvore de segmentos.
 *
 * Esta versão suporta range updates (incrementar todos os elementos de um
 * intervalo específico com um valor v determinado).
 *
 * Autor: Edson Alves
 * Data: 30/09/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <climits>
#include <vector>

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
