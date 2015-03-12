/*
 * Rotinas de IO em console utilizando buffers.
 *
 * Autor: Edson Alves
 * Data: 17/02/2015
 * Licença: LGPL. Sem copyright.
 */
package algorithms.io.bufferedjavaio;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import java.util.ArrayList;

/** Classe leitura e escrita no console. */
public class BufferedIO {
    /** Fluxo de entrada de dados. */
    private InputStreamReader isr = new InputStreamReader(System.in);
    /** Leitor bufferizado. */
    private BufferedReader br = new BufferedReader(isr);

    /** Fluxo de saida de dados. */
    private OutputStreamWriter isw = new OutputStreamWriter(System.out);
    /** Escritor bufferizado. */
    private BufferedWriter bw = new BufferedWriter(isw);

    /** Le inteiros do console.
     * @return  Vetor com os inteiros lidos
     */
    public final int[] readInts() {
        ArrayList<Integer> list = new ArrayList<Integer>();
        String line;

        try {
            while ((line = br.readLine()) != null) {
                line = line.trim();

                if (line.length() < 1) {
                    continue;
                }

                String[] tokens = line.split(" ");

                for (String token : tokens) {
                    if (token.length() < 1) {
                        continue;
                    }

                    int n = Integer.parseInt(token);
                    list.add(n);
                }
            }
        } catch (IOException ex) {
            return null;
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
        try {
            for (int i : ints) {
                bw.write(Integer.toString(i));
                bw.newLine();
            }

            bw.flush();
        } catch (IOException ex) {
            return;
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
