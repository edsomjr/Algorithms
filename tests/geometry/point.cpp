#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "geometry/point.h"

SCENARIO("points initialization and distance", "[point]")
{
    GIVEN("Two points")
    {
        Point P, Q(3.0, 4.0);

        REQUIRE((P.x == 0 and P.y == 0));
        REQUIRE((Q.x == 3 and Q.y == 4));

        REQUIRE(P != Q);

        WHEN("points are different")
        {
            THEN("distance must positive")
            {
                auto d = P.distance(Q);

                REQUIRE(d > 0);
                REQUIRE(equals(d, 5.0) );
            }
        }

        WHEN("points are equals")
        {
            auto dP = P.distance(P);
            auto dQ = Q.distance(Q);

            THEN("distance must be zero")
            {
                REQUIRE(equals(dP, 0.0));
                REQUIRE(equals(dQ, 0.0));
            }
        }
    }
}

SCENARIO("translations, rotations and scale", "[point]")
{
    GIVEN("A point P and two deltas (dx and dy)")
    {
        Point P;

        auto dx = 4.0;
        auto dy = -3.0;

        WHEN("P is the origin")
        {
            REQUIRE(P == Point(0, 0));

            THEN("the translated point Q must have coordinates (dx, dy)")
            {
                auto Q = P.translate(dx, dy);

                REQUIRE(equals(Q.x, dx));
                REQUIRE(equals(Q.y, dy));
            }
        }

        WHEN("Q is P translated by (dx, dy)")
        {
            P = Point(-1.0, 2.0);
            auto Q = P.translate(dx, dy);
 
            THEN ("then P and Q must be different")
            {
                REQUIRE(equals(Q.x, 3.0));
                REQUIRE(equals(Q.y, -1.0));
                REQUIRE(P != Q);
            }
        }
    }
            
    GIVEN("A point P and two scalars kx and ky)")
    {
        Point P(-2.5, 3.8);

        auto kx = 4.0;
        auto ky = -3.0;

        WHEN("P is scaled by k = kx")
        {
            THEN("the result is a point Q = kP")
            {
                auto Q = P.scale(kx);

                REQUIRE(equals(Q.x, kx*P.x));
                REQUIRE(equals(Q.y, kx*P.y));
            }
        }

        WHEN("P is scaled on both coordinates by kx and ky")
        {
            THEN ("the result is a point Q = (kx * Px, ky * Py)")
            {
                auto Q = P.scale(kx, ky);

                REQUIRE(equals(Q.x, kx*P.x));
                REQUIRE(equals(Q.y, ky*P.y));
            }
        }
    }
 
    GIVEN("A point")
    {
        Point P(1.0, 0.0);
        
        WHEN("rotated counterclockwise by 90 degrees")
        {
            THEN("it must be on x ou y axis")
            {
                P = P.rotate(M_PI/2.0);
                REQUIRE(P == Point(0.0, 1.0));

                P = P.rotate(M_PI/2.0);
                REQUIRE(P == Point(-1.0, 0.0));

                P = P.rotate(M_PI/2.0);
                REQUIRE(P == Point(0.0, -1.0));

                P = P.rotate(M_PI/2.0);
                REQUIRE(P == Point(1.0, 0.0));
            }
        }

        WHEN("rotated counterclockwise by r degrees")
        {
            THEN("must lie in a point Q such the segments OP and OQ form a angle of r degrees")
            {
                double r = M_PI/4.0;
                double s = sqrt(2.0)/2.0;

                auto Q = P.rotate(r);
                
                REQUIRE(P == Point(1.0, 0.0));
                REQUIRE(Q == Point(s, s));

                r = M_PI/3.0;
                s = sqrt(3.0)/2.0;

                Q = P.rotate(r);

                REQUIRE(P == Point(1.0, 0));
                REQUIRE(Q == Point(0.5, s));

                r = M_PI/6;

                Q = P.rotate(r);

                REQUIRE(P == Point(1.0, 0));
                REQUIRE(Q == Point(s, 0.5));

                r = M_PI;

                Q = P.rotate(r);

                REQUIRE(P == Point(1.0, 0));
                REQUIRE(Q == Point(-1.0, 0));

                r = 2*M_PI;

                Q = P.rotate(r);

                REQUIRE(P == Point(1.0, 0));
                REQUIRE(Q == P);

                r = M_PI/7.0;

                double x = 0.9009688679024191;
                double y = 0.4338837391175581;

                Q = P.rotate(r);

                REQUIRE(P == Point(1.0, 0.0));
                REQUIRE(Q == Point(x, y));
            }
        }
    }
}
