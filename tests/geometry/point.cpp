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
