/*
 * Classe para teste de execução do método echo() da classe IO.
 *
 * Autor: Edson Alves
 * Data: 12/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <algorithms/io/async_io.h>

#include <chrono>

using namespace std;

int main()
{
    IO<int> io;

    auto start = chrono::system_clock::now();
    auto ns = io.read();
    auto end = chrono::system_clock::now();
    chrono::duration<double> rtime = end - start;
 
    start = chrono::system_clock::now();
    io.write(ns);
    end = chrono::system_clock::now();
    chrono::duration<double> wtime = end - start;

    cout.precision(6);
    cout << rtime.count() << "ms to read " << ns.size() << " integers\n";

    cout.precision(6);
    cout << wtime.count() << "ms to write " << ns.size() << " integers\n";

    return 0;
}
