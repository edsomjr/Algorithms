/*
 * Classe para teste do metodo countInts().
 *
 * Autor: Edson Alves
 * Data: 18/02/2015
 * Licença: LGPL. Sem copyright.
 */
package tests.TestJavaIOCountInts;

import algorithms.io.javaio.IO;
import util.Test;

/** Classe que testa o metodo countInts(). */
public class TestCountInts extends Test {
    /** Variavel que registra o numero de inteiros lidos. */
    private int total = 0;
    /** Classe responsavel pela leitura e escrita em console. */
    private final IO jio = new IO();

    /** Rotina que executa o teste. */
    public final void execute() {
        total = jio.countInts();
    }

    /** Rotina executada ao final do teste. */
    public final void pos() {
        System.out.println(total);
    }

    /** Rotina principal do teste.
     * @param args  Nao utilizado
     */
    public static final void main(final String[] args) {
        TestCountInts test = new TestCountInts();
        test.run();
    }
}

