
#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "geometry/circle.h"

SCENARIO("circle initialization and point position", "[circle]")
{
    GIVEN ("A circle and a point P")
    {
        Circle c(Point(0.0, 0.0), 5.0);

        REQUIRE(c.C == Point(0.0, 0.0));
        REQUIRE(equals(c.r, 5.0));

        Point P(3.0, 4.0);

        WHEN("P are on the circle")
        {
            THEN("position must return ON")
            {
                REQUIRE(c.position(P) == Circle::ON);
            }
        }

        WHEN("P are inside the circle")
        {
            P = Point(2.0, 2.0);

            THEN("position must return IN")
            {
                REQUIRE(c.position(P) == Circle::IN);
            }
        }

        WHEN ("P are outside the circle")
        {
            P = Point(4.0, 4.0);

            THEN("position must return OUT")
            {
                REQUIRE(c.position(P) == Circle::OUT);
            }
        }
 
    }
}

SCENARIO("circle perimeter and area", "[circle]")
{
    GIVEN("A circle")
    {
        Circle c(Point(0.0, 0.0));

        WHEN("radius equals 1.0")
        {
            c.r = 1.0;

            THEN("perimeter equals 2*PI")
            {
                REQUIRE(equals(c.perimeter(), 2.0 * M_PI));
            }

            THEN("area equals PI")
            {
                REQUIRE( equals(c.area(), M_PI) );
            }
        }

        WHEN("radius equals PI")
        {
            c.r = M_PI;

            THEN("perimeter equals 2*PI*PI")
            {
                REQUIRE(equals(c.perimeter(), 2.0 * M_PI * M_PI));
            }

            THEN("area equals PI**3")
            {
                REQUIRE(equals(c.area(), M_PI * M_PI * M_PI));
            }
        }
    }
}

SCENARIO("circles with radius r that contains P and Q", "[circle]")
{
    GIVEN ("Two points P and Q and a radius r")
    {
        Point P, Q(8.0, 0.0);
        double r = 5.0;
        Circle c;

        WHEN("P equals Q")
        {
            Q = P;

            THEN("infinite number of circles with radius r that contains P")
            {
                auto cs = Circle::from_2_points_and_radius(P, Q, r);

                REQUIRE(cs.size() > 2);

                for (const auto& x : cs)
                    REQUIRE(x.position(P) == Circle::ON);
            }
        }

        WHEN("r is lesser or equals than half the distance dist(P, Q)")
        {
            r = 3.0;

            THEN("there no circle that passes through P and Q with radius r")
            {
                auto cs = Circle::from_2_points_and_radius(P, Q, r);

                REQUIRE(cs.empty());
            }
        }

        WHEN("r is greater than half the distance dist(P, Q)")
        {
            THEN( "there are two circles" )
            {
                auto cs = Circle::from_2_points_and_radius(P, Q, r);
                REQUIRE(cs.size() == 2);
                REQUIRE(cs.front() != cs.back());

                for (const auto& x : cs)
                {
                    REQUIRE(x.position(P) == Circle::ON);
                    REQUIRE(x.position(Q) == Circle::ON);
                }
            }
        }
    }
}

SCENARIO("circles from 3 points", "[circle]")
{
    GIVEN ("Three points P, Q and R")
    {
        Point P, Q, R;

        WHEN("P, Q and R are colinear")
        {
            THEN("there no circle that passes through P, Q and R")
            {
                auto cs = Circle::from_3_points(P, Q, R);

                REQUIRE(cs.empty());
            }
        }

        WHEN("P, Q and R are not colinear")
        {
            Q = Point(2.0, 3.0);
            R = Point(-1.0, 5.0);

            THEN("there is one circle that passes through P, Q and R")
            {
                auto cs = Circle::from_3_points(P, Q, R);

                REQUIRE(cs.size() == 1);

                auto c = cs.front();

                REQUIRE(c.position(P) == Circle::ON);
                REQUIRE(c.position(Q) == Circle::ON);
                REQUIRE(c.position(R) == Circle::ON);
            }
        }
    }
}
