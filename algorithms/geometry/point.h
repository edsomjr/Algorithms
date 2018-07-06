/**
 * Classe que representa pontos no espaço bidimensional
 *
 * Autor: Edson Alves
 * Data: 18/07/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GEOMEdoubleRY_POINdouble_H
#define GEOMEdoubleRY_POINdouble_H

#include <cmath>

bool equals(double a, double b)
{
    static const auto EPS = 1e-9;
    return fabs(a - b) < EPS;
}

class Point {
public:
    double x, y;

    Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

    bool operator==(const Point& P) const
    {
        return equals(x, P.x) and equals(y, P.y);
    }

    bool operator!=(const Point& P) const
    {
        return not (*this == P);
    }

    bool operator<(const Point& P) const
    {
        return equals(x, P.x) ? y < P.y : x < P.x;
    }

    double distance(const Point& P) const
    {
        return hypot(x - P.x, y - P.y);
    }

    Point rotate(double angle)
    {
        auto px = cos(angle) * x - sin(angle) * y;
        auto py = sin(angle) * x + cos(angle) * y;

        return Point { double(px), double(py) };
    } 

    Point translate(double dx, double dy) const
    {
        return Point(x + dx, y + dy);
    }

    Point scale(double kx, double ky) const
    {
        return Point(kx*x, ky*y);
    }

    Point scale(double k) const
    {
        return scale(k, k);
    }
};

#endif
