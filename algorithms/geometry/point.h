/**
 * Classe que representa pontos no espaço bidimensional
 *
 * Autor: Edson Alves
 * Data: 18/07/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include <cmath>

template<typename T>
bool equals(const T& a, const T& b)
{
    return a == b;
}

bool equals(double a, double b)
{
    static const auto EPS = 1e-9;
    return fabs(a - b) < EPS;
}

template<typename T>
class Point {
public:
    T x, y;

    Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}

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

    T squared_distance(const Point& P) const
    {
        return (x - P.x) * (x - P.x) + (y - P.y) * (y - P.y);
    }

    Point rotate(double angle)
    {
        auto px = cos(angle) * x - sin(angle) * y;
        auto py = sin(angle) * x + cos(angle) * y;

        return Point { T(px), T(py) };
    } 

    Point translate(T dx, T dy) const
    {
        return Point(x + dx, y + dy);
    }

    Point scale(T kx, T ky) const
    {
        return Point(kx*x, ky*y);
    }

    Point scale(T k) const
    {
        return scale(k, k);
    }
};

#endif
