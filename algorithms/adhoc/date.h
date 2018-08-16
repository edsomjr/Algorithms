/**
 * Classe para a representação de datas (em dias, meses e anos).
 *
 * Autor: Edson Alves
 * Data: 25/03/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef DATE_H
#define DATE_H

#include <iostream>

static const int days_in_month_regular[] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const int days_in_month_leap[] {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
public:
    Date(int d = 0, int m = 0, int y = 0) : m_d(d), m_m(m), m_y(y) { }

    void add(int days)
    {
        long long date_days = days_from_zero(m_d, m_m, m_y);
        date_days += days;
        date_from_days(date_days, m_d, m_m, m_y);
    }
    
    int day() const { return m_d; }
    int month() const { return m_m; }
    int year() const { return m_y; }

    std::string format() const
    {
        char buffer[32];
        sprintf(buffer, "%02d/%02d/%04d", m_d, m_m, m_y);

        return std::string(buffer);
    }

    long long operator-(const Date& d) const
    {
        return days_from_zero(m_d, m_m, m_y) - days_from_zero(d.day(), d.month(), d.year());
    }

    static bool is_leap(int year)
    {
        return (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0);
    }

    static Date from_days(long long days)
    {
        int d, m, y;
        date_from_days(days, d, m, y);
        return Date(d, m, y);
    } 

private:
    int m_d, m_m, m_y;

    static int leaps(int y)
    {
        int div4 = y / 4;
        int div100 = y / 100;
        int div400 = y / 400;
        
        return div4 - div100 + div400;
    }

    static long long days_from_zero(int d, int m, int y)
    {
        long long days = d;
        const int *days_in_month = Date::is_leap(y) ? days_in_month_leap : days_in_month_regular;

        for (int i = 1; i < m; i++)
            days += days_in_month[i];

        int leap_years = leaps(y - 1);
        days += 365*y + leap_years;

        return days;
    }

    static void date_from_days(int days, int& d, int &m, int& y)
    {
        y = days / 366;

        while (days_from_zero(0, 0, y + 1) < days)
            y++;

        days -= days_from_zero(0, 0, y);

        const int *days_in_month = Date::is_leap(y) ? days_in_month_leap : days_in_month_regular;

        m = 1;

        while (days > days_in_month[m])
        {
            days -= days_in_month[m];
            m++;
        }

        d = days;
    }
};

#endif
