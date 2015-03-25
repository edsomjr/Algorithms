/*
 * Classe para teste do método add() da classe Time
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
        m_size = m_times.size() / 6;
    }

    void execute()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            Time t(m_times[6*i], m_times[6*i + 1], m_times[6*i + 2]);
            Time d(m_times[6*i + 3], m_times[6*i + 4], m_times[6*i + 5]);

            t.add(d);

            m_res.push_back(t.hours());
            m_res.push_back(t.minutes());
            m_res.push_back(t.seconds());
        }
    }

    void pos()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            printf("%02d %02d %02d\n", m_res[3*i], m_res[3*i + 1],
                m_res[3*i + 2]);
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
