/**
 * Classe que representa um triângulo no espaço bidimensional
 *
 * Autor: Edson Alves
 * Data: 30/07/2016
 * Licença: LGPL. Sem copyright.
 */
#ifndef GEOMETRY_TRIANGLE_H
#define GEOMETRY_TRIANGLE_H

#include "point.h"

class Triangle {
public:
	Point A, B, C;
	double a, b, c;
	
	Triangle(const Point& P, const Point& Q, const Point& R) : A(P), B(Q), C(R)
	{
		a = P.distance(Q);
		b = Q.distance(R);
		c = R.distance(P);
	}
	
	Triangle(double av, double bv, double cv) : 
        A(), B(), C(), a(av), b(bv), c(cv) {}
	
    typedef enum { EQUILATERAL, ISOSCELES, SCALENE } Sides;

    Sides classification_by_sides() const
    {
        if (a == b and b == c)
            return EQUILATERAL;

        if (a == b or a == c or b == c)
            return ISOSCELES;

        return SCALENE;
    }

    typedef enum { RIGHT, ACUTE, OBTUSE } Angles;

    Angles classification_by_angles() const
    {
        auto AB = acos((c*c - a*a - b*b)/(2*a*b));
        auto AC = acos((b*b - a*a - c*c)/(2*a*c));
        auto BC = acos((a*a - b*b - c*c)/(2*b*c));

        auto right = PI / 2.0;

        if (equals(AB, right) or equals(AC, right) or equals(BC, right))
            return RIGHT;

        if (AB > right or AC > right or BC > right)
            return OBTUSE;

        return ACUTE;
    }

    double perimeter() const
    {
        return a + b + c;
    }

    double area() const
    {
        auto s = perimetro() / 2.0;

        return sqrt(s*(s - a)*(s - b)*(s - c));
    }

    double area2() const
    {
        double det = (A.x*B.y + A.y*C.x + B.x*C.y) - (C.x*B.y + C.y*A.x + B.x*A.y);

        return 0.5 * fabs(det);
    }

    Point barycenter() const
    {
        auto x = (A.x + B.x + C.x) / 3.0;
        auto y = (A.y + B.y + C.y) / 3.0;

        return Point(x, y);
    }
 
    double inradius() const 
    {
        return (2 * area()) / perimeter();
    }

    // Centro do círculo inscrito
    Point incenter() const
    {
        auto p = perimeter();
        auto x = (a*A.x + b*B.x + c.C.x)/p;
        auto y = (a*A.y + b*B.y + c.C.y)/p;

        return Point(x, y);
    }

    double circumradius() const
    {
        return (a * b * c)/(4 * area());
    }

    Point circumcenter() const
    {
        auto d = 2*(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y));

        auto A2 = A.x*A.x + A.y*A.y;
        auto B2 = B.x*B.x + B.y*B.y;
        auto C2 = C.x*C.x + C.y*C.y;

        auto x = (A2*(B.y - C.y) + B2*(C.y - A.y) + C2*(A.y - B.y))/d;
        auto y = (A2*(C.x - B.x) + B2*(A.x - C.x) + C2*(B.x - A.x))/d;

        return Point(x, y);
    }
};


#endif

