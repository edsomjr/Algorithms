/**
 * Classe Fenwick (BIT) Tree para sinal do produto dos elementos.
 *
 * Os pares do vetor ft armazenam, respectivamente, o número de zeros e o
 * sinal do produto no intervalo correspondente ao índice i.
 *
 * Para modificar o valor do elemento na posição i, é preciso primeiro
 * apagar o elemento (método erase()) para depois chamar o update().
 *
 * Autor: Edson Alves
 * Data: 07/09/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef PRODUCT_FENWICK_TREE_H
#define PRODUCT_FENWICK_TREE_H

#include <vector>

using namespace std;

#define LSB(n) ((n) & (-n)) 

class ProductFenwickTree
{
private:
    int m_N;
    vector< pair<int, int> > ft;
    vector<int> ns;

public:
    ProductFenwickTree(int N)
        : m_N(N)
    {
        ft.assign(N + 1, make_pair(0, 1));
        ns.assign(N + 1, 1);
    }

    int RPQ(int a, int b)
    {
        auto A = (a == 1) ? make_pair(0, 1) : RPQ(a - 1);
        auto B = RPQ(b);

        return (B.first > A.first) ? 0 : B.second * A.second;
    }

    void erase(int i)
    {
        int n = i;

        while (n <= m_N)
        {
            switch (ns[i]) {
            case 0:
                --ft[n].first;
                break;

            case -1:
                ft[n].second *= -1;
                break;
            }

            n += LSB(n);
        }

        ns[i] = 1;
    }

    void update(int i, int v)
    {
        int n = i;

        while (n <= m_N)
        {
            switch (v) {
            case 0:
                ++ft[n].first;
                break;

            case -1:
                ft[n].second *= -1;
                break;
            }

            n += LSB(n);
        }

        ns[i] = v;
    }
    
private:

    pair<int, int> RPQ(int b)
    {
        auto p = make_pair(0, 1);

        while (b)
        {
            p.first += ft[b].first;
            p.second *= ft[b].second;
            b -= LSB(b);
        }

        return p;
    }
};

#endif
