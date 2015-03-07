/*
 * Classe para teste de execução dos algoritmos.
 *
 * Autor: Edson Alves
 * Data: 06/03/2015
 * Licença: LGPL. Sem copyright.
 */
package util;

import util.Stopwatch;

public class Test
{
    public void pre() {}
    public void pos() {}
    public void execute() {}

    public int run() { 
        pre();
        Stopwatch sw = new Stopwatch();
        execute();
        System.err.println(sw.elapsed());
        pos();
        return 0;
    }
};
