/*
 * Classe para teste dos métodos de IO do Java
 *
 * Autor: Edson Alves
 * Data: 18/02/2015
 * Licença: LGPL. Sem copyright.
 */
import algorithms.io.IO;
import util.Test;

public class TestIO {

    public static final void main(final String[] args) {

        IO io = new IO();

        long start = System.currentTimeMillis();
        int [] ns = io.read();
        long end = System.currentTimeMillis();

        long rtime = end - start;

        start = System.currentTimeMillis();
        io.write(ns);
        end = System.currentTimeMillis();

        long wtime = end - start;

        System.out.println("" + rtime + " ms to read " + ns.length + " integers");
        System.out.println("" + wtime + " ms to write " + ns.length + " integers");
    }
}
