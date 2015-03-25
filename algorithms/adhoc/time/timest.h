/**
 * Classe para a representação de tempo (em horas, minutos e segundos).
 *
 * Autor: Edson Alves
 * Data: 24/03/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef TIMEST_H
#define TIMEST_H

#define SECS_IN_A_DAY   86400
#define SECS_IN_A_HOUR  3600
#define SECS_IN_A_MIN   60

class Time
{
public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        m_secs = SECS_IN_A_HOUR*h + SECS_IN_A_MIN*m + s;
    }

    int hours() const
    {
        int h = m_secs / SECS_IN_A_HOUR;
        return h;
    }

    int minutes() const
    {
        int m = (m_secs % SECS_IN_A_HOUR) / SECS_IN_A_MIN;
        return m;
    }

    int seconds() const
    {
        int s = m_secs % SECS_IN_A_MIN;
        return s;
    }

    void add(const Time& t)
    {
        m_secs += t.m_secs;
        m_secs %= SECS_IN_A_DAY;
    }
    
private:
    int m_secs;
};

#endif
