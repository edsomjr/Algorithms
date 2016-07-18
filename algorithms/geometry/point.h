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

#define EPS 1e-9    // Delta de comparação entre doubles

// Compara duas variáveis do tipo double usando o delta EPS
bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point {
public:
    double x;
    double y;

    Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

    bool operator==(const Point& P) const
    {
        return equals(x, P.x) and equals(y, P.y);
    }

    bool operator!=(const Point& P) const
    {
        return not (*this == P);
    }

    double distance(const Point& P) const
    {
        return hypot(x - P.x, y - P.y);
    }
};

#endif
