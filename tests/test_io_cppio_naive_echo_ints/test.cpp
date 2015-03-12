/*
 * Classe para teste de execução do método echo() da classe IO.
 *
 * Autor: Edson Alves
 * Data: 06/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <util/test.h>
#include <algorithms/io/cppio/io_naive.h>

class TestEchoInts : public Test
{
public:
    void execute()
    {
        m_io.echo();
    }

private:
    IO<int> m_io;
};

int main()
{
    TestEchoInts test;

    return test.run();
}
