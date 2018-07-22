/*
 * Classe para operações de I/O em console utilizando a classe Scanner para
 * a entrada.
 *
 * Autor: Edson Alves
 * Data: 18/02/2015
 * Licença: LGPL. Sem copyright.
 */
package algorithms.io;

import java.util.Scanner;
import java.util.ArrayList;

public class IO {

    private Scanner sc = new Scanner(System.in);

    public final int[] read() {
        ArrayList<Integer> list = new ArrayList<Integer>();

        while (sc.hasNext()) {
            int n = sc.nextInt();
            list.add(n);
        }

        int[] ns = new int[list.size()];

        for (int i = 0; i < ns.length; i++) {
            ns[i] = list.get(i).intValue();
        }

        return ns;
    }

    public final void write(final int[] ns) {
        for (int i : ns) {
            System.out.println("" + i);
        }
    }
}
