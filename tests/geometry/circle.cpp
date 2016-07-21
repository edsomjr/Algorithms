
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

SCENARIO( "circle perimeter and area", "[circle]" )
{
    GIVEN ( "A circle" )
    {
        Circle c(Point(0, 0));

        WHEN( "radius equals 1.0" )
        {
            c.r = 1.0;

            THEN( "perimeter equals 2*PI" )
            {
                REQUIRE( equals(c.perimeter(), 2.0 * PI) );
            }

            THEN( "area equals PI" )
            {
                REQUIRE( equals(c.area(), PI) );
            }
        }

        WHEN( "radius equals PI" )
        {
            c.r = PI;

            THEN( "perimeter equals 2*PI*PI" )
            {
                REQUIRE( equals(c.perimeter(), 2.0 * PI * PI) );
            }

            THEN( "area equals PI*PI*PI" )
            {
                REQUIRE( equals(c.area(), PI * PI * PI) );

            }
        }
    }
}

