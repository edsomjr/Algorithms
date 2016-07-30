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

#include <iostream>

using std::min;
using std::max;
using std::pair;

class Circle {
public:
    Point C;
    double r;

    typedef enum { IN, OUT, ON } PointPosition;
    typedef enum { ZERO = 0, TWO = 2, INF = -1 } Circles;

    Circle(const Point& Cv = Point(0, 0), double rv = 1.0) : C(Cv), r(rv) {}

    bool operator==(const Circle& c) const
    {
        return C == c.C and equals(r, c.r);
    }

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

    double sector(double a) const
    {
        return (a / (2*PI)) * area();
    }

    double segment(double a) const
    {
        auto c = chord(a);
        auto s = (r + r + c)/2.0;                   // Semiperímetro
        auto T = sqrt(s*(s - r)*(s - r)*(s - c));   // Área do triângulo

        return sector(a) - T;
    }

    static bool
    from2PointsAndRadius(const Point& P, const Point& Q, double r, Circle& c)
    {
        double d2 = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
        double det = r * r / d2 - 0.25;

        if (det < 0.0)
            return false;

        double h = sqrt(det);

        auto x = (P.x + Q.x) * 0.5 + (P.y - Q.y) * h;
        auto y = (P.y + Q.y) * 0.5 + (Q.x - P.x) * h;

        c = Circle(Point(x, y), r);

        return true;
    }
};

#endif
