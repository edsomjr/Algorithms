/*
 * Classe para teste do metodo echoInts().
 *
 * Autor: Edson Alves
 * Data: 18/02/2015
 * Licença: LGPL. Sem copyright.
 */
package tests.TestJavaIOEchoInts;

import algorithms.io.javaio.IO;
import util.Test;

/** Classe que testa o metodo echoInts(). */
public class TestEchoInts extends Test {
    /** Classe responsavel pela leitura e escrita em console. */
    private final IO jio = new IO();

    /** Rotina que executa o teste. */
    public final void execute() {
        jio.echoInts();
    }

    /** Rotina principal do teste.
     * @param args  Nao utilizado
     */
    public static void main(final String[] args) {
        TestEchoInts test = new TestEchoInts();
        test.run();
    }
}

