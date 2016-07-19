
#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "geometry/circle.h"

SCENARIO( "circle initialization and point position", "[circle]" )
{
    GIVEN ( "A circle and a point P" )
    {
        Circle c(Point(0, 0), 5.0);

        REQUIRE( c.C == Point(0, 0) );
        REQUIRE( equals(c.r, 5.0) );

        Point P(3, 4);

        WHEN( "P are on the circle" )
        {
            THEN( "position must return ON" )
            {
                REQUIRE( c.position(P) == Circle::ON );
            }
        }

        WHEN ( "P are inside the circle" )
        {
            P = Point(2, 2);

            THEN( "position must return IN" )
            {
                REQUIRE( c.position(P) == Circle::IN );
            }
        }

        WHEN ( "P are outside the circle" )
        {
            P = Point(4, 4);

            THEN( "position must return OUT" )
            {
                REQUIRE( c.position(P) == Circle::OUT );
            }
        }
 
    }
}

