/*
 * Classe para teste da classe Date (construtor e métodos de acesso).
 *
 * Autor: Edson Alves
 * Data: 25/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <util/test.h>
#include <algorithms/io/buffered_cio/io.h>
#include <algorithms/adhoc/time/date.h>

#include <iostream>

using namespace std;

class TestDate : public Test
{
public:
    void pre()
    {
        m_times = m_io.readInts();
        m_size = m_times.size() / 4;
    }

    void execute()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            Date d(m_times[4*i + 1], m_times[4*i + 2], m_times[4*i + 3]);
            m_res.push_back(d.day());
            m_res.push_back(d.month());
            m_res.push_back(d.year());
        }
    }

    void pos()
    {
        m_size = m_res.size() / 3;

        for (size_t i = 0; i < m_size; i++)
        {
            printf("%d %d %d\n", m_res[3*i], m_res[3*i + 1], m_res[3*i + 2]);
        }
    }

private:
    vector<int> m_times, m_res;
    size_t m_size;
    BufferedIO m_io;
};

int main()
{
    TestDate test;

    return test.run();
}
