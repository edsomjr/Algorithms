/*
 * Classe para teste da classe Time (construtor e métodos de acesso).
 *
 * Autor: Edson Alves
 * Data: 24/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include <util/test.h>
#include <algorithms/io/buffered_cio/io.h>
#include <algorithms/adhoc/time/timest.h>

#include <iostream>

using namespace std;

class TestTime : public Test
{
public:
    void pre()
    {
        m_times = m_io.readInts();
        m_size = m_times.size() / 3;
    }

    void execute()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            Time t(m_times[3*i], m_times[3*i + 1], m_times[3*i + 2]);
            m_res.push_back(t.hours());
            m_res.push_back(t.minutes());
            m_res.push_back(t.seconds());
        }
    }

    void pos()
    {
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
    TestTime test;

    return test.run();
}
