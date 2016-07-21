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

#include <iostream>

using std::pair;

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

    typedef enum { ZERO, ONE, INF } Intersections;

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

    pair<Intersections, Point> intersections(const Line& r)
    {
        auto det = a * r.b - b * r.a;

        if (equals(det, 0))
        {
            // Coincidentes
            if (*this == r)
                return pair<Intersections, Point>(INF, Point());
            else    
                return pair<Intersections, Point>(ZERO, Point());  // Paralelas
        } else  // Concorrentes
        {
            double x = (-c * r.b + r.c * b) / det;
            double y = (-r.c * a + c * r.a) / det;

            return pair<Intersections, Point>(ONE, Point(x, y));
        }
    }
};

#endif
