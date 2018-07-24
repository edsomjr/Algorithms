/*
 * Classe para teste de execução do método echo() da classe IO.
 *
 * Autor: Edson Alves
 * Data: 12/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <algorithms/io/cio.h>

#include <stdio.h>
#include <time.h>

#define CLOCKS (CLOCKS_PER_SEC*1.0)

int main()
{
    clock_t start, end;
    double rtime, wtime;
    int n;

    start = clock();
    n = read();
    end = clock();
    rtime = (end - start)/CLOCKS;
 

    start = clock();
    write(n);
    end = clock();
    wtime = (end - start)/CLOCKS;

    printf("%.6fms to read %d integers\n", rtime, n);
    printf("%.6fms to write %d integers\n", wtime, n);

    return 0;
}
