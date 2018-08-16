#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "adhoc/timest.h"

SCENARIO("Time construction", "[time]")
{
    GIVEN("Hours, minutes and seconds")
    {
        int h = 7, m = 53, s = 21;

        WHEN("A time is constructed")
        {
            Time time(h, m, s);

            THEN("then the formatted time is in hh:mm:ss format")
            {
                REQUIRE(time.format() == "07:53:21");
            }
        }
    }
}

SCENARIO("Time operations", "[time]")
{
    GIVEN("The time 23:59:59")
    {
        Time time(23, 59, 59);

        WHEN("We add two seconds to it") 
        {
            time.add(Time(0, 0, 2));

            THEN("we get the time 00:00:01")
            {
                REQUIRE(time.format() == "00:00:01");
            }
        }
    }
}
