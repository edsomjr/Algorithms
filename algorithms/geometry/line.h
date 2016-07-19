/**
 * Classe que representa retas no espaço bidimensional
 *
 * Autor: Edson Alves
 * Data: 19/07/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

#include "point.h"

class Line {
    void normalize()
    {
        auto k = a ? a : b;

        a /= k;
        b /= k;
        c /= k;
    }

public:
    double a;
    double b;
    double c;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) { normalize(); }

    Line(const Point& P, const Point& Q)
    {
        a = P.y - Q.y;
        b = Q.x - P.x;
        c = P.x * Q.y - P.y * Q.x;

        normalize();
   }

    bool operator==(const Line& r) const
    {
        return equals(a, r.a) and equals(b, r.b) and equals(c, r.c);
    } 

    bool operator!=(const Line& r) const
    {
        return not (*this == r);
    }

    bool parallel(const Line& r) const
    {
        return equals(a * r.b - b * r.a, 0) and not equals(c, r.c);
    }

    bool concurrent(const Line& r) const
    {
        return not equals(a * r.b - b * r.a, 0);
    }
};

#endif
