/*
 * Classe para teste de execução do método count() da classe IO.
 *
 * Autor: Edson Alves
 * Data: 11/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <util/test.h>
#include <algorithms/io/cppio/io_naive.h>

#include <iostream>

using namespace std;

class TestCountInt : public Test
{
public:
    void execute()
    {
        m_count = m_io.count();
    }

    void pos()
    {
        cout << m_count << endl;
    }

private:
    int m_count;
    IO<int> m_io;
};

int main()
{
    TestCountInt test;

    return test.run();
}
