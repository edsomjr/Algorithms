/*
 * Classe que simula um cronometro.
 *
 * Autor: Edson Alves
 * Data: 06/03/2015
 * Licença: LGPL. Sem copyright.
 */
package util;

public class Stopwatch 
{
    private long start = System.currentTimeMillis();

    public long elapsed() {
        long now = System.currentTimeMillis();
        return now - start;
    }
};

