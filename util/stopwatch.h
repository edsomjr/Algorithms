/*
 * Classe que simula um cronometro.
 *
 * Autor: Edson Alves
 * Data: 06/03/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>

#define CLOCKS_PER_MILI (CLOCKS_PER_SEC/1000)

class Stopwatch
{
public:
    Stopwatch() : m_start(clock()) {}

    int elapsed()
    {
        clock_t now = clock();
        return (now - m_start)/CLOCKS_PER_MILI;
    }

private:
    clock_t m_start;
};

#endif // STOPWATCH_H
