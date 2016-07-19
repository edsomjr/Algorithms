#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "geometry/point.h"

SCENARIO( "points initialization and distance", "[point]" )
{
    GIVEN ( "Two points" )
    {
        Point P, Q(3, 4);

        REQUIRE( (P.x == 0 and P.y == 0) );
        REQUIRE( (Q.x == 3 and Q.y == 4) );

        REQUIRE( P != Q );

        WHEN( "points are different" )
        {
            THEN( "distance must be nonzero" )
            {
                double d = P.distance(Q);

                REQUIRE( d > 0 );
                REQUIRE( equals(d, 5.0) );
            }
        }

        WHEN ( "points are equals" )
        {
            double dP = P.distance(P);
            double dQ = Q.distance(Q);

            THEN( "distance must be zero")
            {
                REQUIRE( equals(dP, 0.0) );
                REQUIRE( equals(dQ, 0.0) );
            }
        }
    }
}

SCENARIO( "rotations", "[point]" )
{
    GIVEN ( "A point" )
    {
        Point P(1, 0);
        
        WHEN ( "rotated counterclockwise by 90 degrees" )
        {
            THEN ( "it must be on x ou y axis" )
            {
                P = P.rotate(PI/2);
                REQUIRE( P == Point(0, 1) );

                P = P.rotate(PI/2);
                REQUIRE( P == Point(-1, 0) );

                P = P.rotate(PI/2);
                REQUIRE( P == Point(0, -1) );

                P = P.rotate(PI/2);
                REQUIRE( P == Point(1, 0) );
            }
        }

        WHEN ( "rotated counterclockwise by r degrees" )
        {
            THEN ( "must return a point Q rotated by r degrees" );

            double r = PI/4;
            double s = sqrt(2.0)/2.0;

            auto Q = P.rotate(r);
            
            REQUIRE( P == Point(1.0, 0) );
            REQUIRE( Q == Point(s, s) );

            r = PI/3;
            s = sqrt(3.0) / 2;

            Q = P.rotate(r);

            REQUIRE( P == Point(1.0, 0) );
            REQUIRE( Q == Point(0.5, s) );

            r = PI/6;

            Q = P.rotate(r);

            REQUIRE( P == Point(1.0, 0) );
            REQUIRE( Q == Point(s, 0.5) );

            r = PI;

            Q = P.rotate(r);

            REQUIRE( P == Point(1.0, 0) );
            REQUIRE( Q == Point(-1.0, 0) );

            r = 2*PI;

            Q = P.rotate(r);

            REQUIRE( P == Point(1.0, 0) );
            REQUIRE( Q == P );

            r = PI / 7;
            double x = 0.9009688679024191;
            double y = 0.4338837391175581;

            Q = P.rotate(r);

            REQUIRE( P == Point(1.0, 0) );
            REQUIRE( Q == Point(x, y) );
        }
    }
}

