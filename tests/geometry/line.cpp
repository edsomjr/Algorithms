#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "geometry/line.h"

SCENARIO( "line initialization and comparison", "[line]" )
{
    GIVEN ( "Two lines" )
    {
        Line r(1, 2, 3), s(2, 4, 6);

        WHEN ( "they have the same coefficients" )
        {
            THEN ( "they are equals" )
            {
                REQUIRE( r == s );
            }
        }

        WHEN ( "they have the same inclination, but aren't the same" )
        {
            THEN ( "they are parallel" )
            {
                REQUIRE( not r.parallel(s) );

                s.c = 5;

                REQUIRE( r.parallel(s) );
            }
        }

        WHEN ( "they don't have the same inclination" )
        {
            THEN ( "they are concurrent" );

            r = Line(1, 0, 1);
            s = Line(0, 1, 1);

            REQUIRE( r.concurrent(s) );

            r = Line(1, 0, 1);
            s = Line(1, 1, 1);

            REQUIRE( r.concurrent(s) );

            r = Line(1, 1, 1);
            s = Line(1, 0, 1);

            REQUIRE( r.concurrent(s) );

            r = Line(1, 1, 1);
            s = Line(1, 1, 1);

            REQUIRE( not r.concurrent(s) );

            r = Line(1, 2, 1);
            s = Line(3, 4, 1);

            REQUIRE( r.concurrent(s) );

            r = Line(1, 0, 1);
            s = Line(1, 1, 1);

            REQUIRE( r.concurrent(s) );
        }
    }
}
