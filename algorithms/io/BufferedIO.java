/*
 * Rotinas de IO em console utilizando buffers.
 *
 * Autor: Edson Alves
 * Data: 17/02/2015
 * Licença: LGPL. Sem copyright.
 */
package algorithms.io;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import java.util.ArrayList;

public class BufferedIO {

    private InputStreamReader isr = new InputStreamReader(System.in);
    private BufferedReader br = new BufferedReader(isr);

    private OutputStreamWriter osw = new OutputStreamWriter(System.out);
    private BufferedWriter bw = new BufferedWriter(osw);

    public final int[] read() {
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

        int[] ns = new int[list.size()];

        for (int i = 0; i < ns.length; i++) {
            ns[i] = list.get(i).intValue();
        }

        return ns;
    }

    public final void write(final int[] ns) {
        try {
            for (int i : ns) {
                bw.write(Integer.toString(i));
                bw.newLine();
            }

            bw.flush();
        } catch (IOException ex) {
            return;
        }
    }
}
