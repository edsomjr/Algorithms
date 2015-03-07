/*
 * Classe para teste de execução dos algoritmos.
 *
 * Autor: Edson Alves
 * Data: 06/03/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "stopwatch.h"

class Test
{
public:
    virtual void pre() {}
    virtual void pos() {}
    virtual void execute() {}

    int run()
    {
        pre();
        Stopwatch sw;
        execute();
        std::cerr << sw.elapsed();
        pos();
        return 0;
    }
};

#endif // TEST_H
