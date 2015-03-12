/*
 * Classe para teste de execução do método echo() da classe IO.
 *
 * Autor: Edson Alves
 * Data: 12/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <util/test.h>
#include <algorithms/io/buffered_cio/io.h>

class TestIOEcho : public Test
{
public:
    void execute()
    {
        m_io.echoInts();
    }

private:
    BufferedIO m_io;
};

int main()
{
    TestIOEcho t;

    return t.run();
}
