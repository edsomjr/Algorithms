/**
 * Classe que representa um círculo no espaço bidimensional
 *
 * Autor: Edson Alves
 * Data: 18/07/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H

#include <vector>

#include "point.h"

class Circle {
public:
    Point C;
    double r;

    typedef enum { IN, OUT, ON } PointPosition;

    Circle(const Point& Cv = Point(0.0, 0.0), double rv = 1.0) : C(Cv), r(rv) {}

    bool operator==(const Circle& c) const
    {
        return C == c.C and equals(r, c.r);
    }

    bool operator!=(const Circle& c) const
    {
        return not (*this == c);
    }

    PointPosition position(const Point& P) const
    {
        auto d = P.distance(C);

        return equals(d, r) ? ON : (d < r ? IN : OUT);
    }

    double perimeter() const
    {
        return 2.0 * M_PI * r;
    }

    double area() const
    {
        return M_PI * r * r;
    }

    double arc(double a) const
    {
        return (a / (2*M_PI)) * perimeter();
    }

    double chord(double a) const
    {
        return 2 * r * sin(a/2);
    }

    double sector(double a) const
    {
        return (a / (2*M_PI)) * area();
    }

    double segment(double a) const
    {
        auto c = chord(a);
        auto s = (r + r + c)/2.0;                   // Semiperímetro
        auto T = sqrt(s*(s - r)*(s - r)*(s - c));   // Área do triângulo

        return sector(a) - T;
    }

    static std::vector<Circle>
    from_2_points_and_radius(const Point& P, const Point& Q, double r)
    {
        std::vector<Circle> cs;

        if (P == Q)
        {
            cs.push_back(Circle(P.translate(r, 0), r));
            cs.push_back(Circle(P.translate(0, r), r));
            cs.push_back(Circle(P.translate(-r, 0), r));
            cs.push_back(Circle(P.translate(0, -r), r));

            return cs;
        }

        double d2 = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
        double det = r * r / d2 - 0.25;

        if (det < 0.0)
            return cs;

        double h = sqrt(det);

        auto x = (P.x + Q.x) * 0.5 + (P.y - Q.y) * h;
        auto y = (P.y + Q.y) * 0.5 + (Q.x - P.x) * h;

        cs.push_back(Circle(Point(x, y), r));

        x = (Q.x + P.x) * 0.5 + (Q.y - P.y) * h;
        y = (Q.y + P.y) * 0.5 + (P.x - Q.x) * h;

        cs.push_back(Circle(Point(x, y), r));

        return cs;
    }

    static std::vector<Circle>
    from_3_points(const Point& P, const Point& Q, const Point& R)
    {
        std::vector<Circle> cs;

        auto a = 2*(Q.x - P.x);
        auto b = 2*(Q.y - P.y);
        auto c = 2*(R.x - P.x);
        auto d = 2*(R.y - P.y);

        auto det = a*d - b*c;

        // Colinear points
        if (equals(det, 0))
            return cs;

        auto k1 = (Q.x*Q.x + Q.y*Q.y) - (P.x*P.x + P.y*P.y);
        auto k2 = (R.x*R.x + R.y*R.y) - (P.x*P.x + P.y*P.y);

        auto cx = (k1*d - k2*b)/det;
        auto cy = (a*k2 - c*k1)/det;

        Point C(cx, cy);
        auto r = C.distance(P);

        cs.push_back(Circle(C, r));

        return cs;
    }
};

#endif
