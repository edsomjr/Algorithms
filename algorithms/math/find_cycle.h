// Algoritmo de Floyd (Tortoise and Hare) para detecção de ciclos.
#include <bits/stdc++.h>

using ii = pair<int, int>;

ii find_cycle(function<int(int)> f, int x0)
{
    // Encontra uma posição s tal que x_s == x_2s
    auto T = f(x0), H = f(T), s = 1;

    while (T != H)
    {
        T = f(T);
        H = f(f(T));
        ++s;
    }

    // Encontra o primeiro índice m tal que x_m = x_2m
    auto m = 0;
    T = x0;

    while (T != H)
    {
        T = f(T);
        H = f(H);
        ++m;
    }

    // Encontra o tamanho mínimo l do ciclo
    auto l = 1;
    H = f(T);

    while (T != H)
    {
        H = f(T);
        ++l;
    }

    return ii(l, m);
}
