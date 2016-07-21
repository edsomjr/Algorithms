/**
 * Classe que representa um círculo no espaço bidimensional
 *
 * Autor: Edson Alves
 * Data: 18/07/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H

#include "point.h"

class Circle {
public:
    Point C;
    double r;

    typedef enum { IN, OUT, ON } PointPosition;

    Circle(const Point& Cv = Point(0, 0), double rv = 1.0) : C(Cv), r(rv) {}

    PointPosition position(const Point& P) const
    {
        auto d = P.distance(C);

        return equals(d, r) ? ON : (d < r ? IN : OUT);
    }

    double perimeter() const
    {
        return 2.0 * PI * r;
    }

    double area() const
    {
        return PI * r * r;
    }

    double arc(double a) const
    {
        return (a / (2*PI)) * perimeter();
    }

    double chord(double a) const
    {
        return 2 * r * sin(a/2);
    }
};

#endif
