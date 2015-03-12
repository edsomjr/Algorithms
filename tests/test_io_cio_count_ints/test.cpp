/*
 * Classe para teste de execução do método count() da classe IO.
 *
 * Autor: Edson Alves
 * Data: 12/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <util/test.h>
#include <algorithms/io/cio/io.h>

class TestIOCount : public Test
{
public:
    TestIOCount() : m_count(0), m_io() {}

    void execute()
    {
        m_count = m_io.countInts();
    }

    void pos()
    {
        printf("%d\n", m_count);
    }

private:
    int m_count;
    IO m_io;
};

int main()
{
    TestIOCount t;

    return t.run();
}
