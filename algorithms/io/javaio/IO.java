/*
 * Classe para operações de I/O em console utilizando a classe Scanner para
 * a entrada.
 *
 * Autor: Edson Alves
 * Data: 18/02/2015
 * Licença: LGPL. Sem copyright.
 */
package algorithms.io.javaio;

import java.util.Scanner;
import java.util.ArrayList;

/** Classe leitura e escrita no console. */
public class IO {
    /** Classe para leitura de dados do console. */
    private Scanner sc = new Scanner(System.in);

    /** Le inteiros do console.
     * @return  Vetor com os inteiros lidos
     */
    public final int[] readInts() {
        ArrayList<Integer> list = new ArrayList<Integer>();

        while (sc.hasNext()) {
            int n = sc.nextInt();
            list.add(n);
        }

        int[] ints = new int[list.size()];

        for (int i = 0; i < ints.length; i++) {
            ints[i] = list.get(i).intValue();
        }

        return ints;
    }

    /** Escreve o vetor de inteiros no console.
     * @param ints  Vetor a ser escrito
     */
    public final void writeInts(final int[] ints) {
        for (int i : ints) {
            System.out.println("" + i);
        }
    }

    /** Conta o numero de inteiros lidos.
     * @return  O número de inteiros lidos
     */
    public final int countInts() {
        int[] ints = readInts();
        return ints.length;
    }

    /** Escreve os inteiros lidos no console. */
    public final void echoInts() {
        int[] ints = readInts();
        writeInts(ints);
    }
}

