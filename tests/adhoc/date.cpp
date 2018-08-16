#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "adhoc/date.h"

SCENARIO("Date construction", "[date]")
{
    GIVEN("A day, a month and an year")
    {
        int day = 5, month = 3, year = 945;

        WHEN("A date is constructed")
        {
            Date date(day, month, year);

            THEN("then the formatted date is in dd/mm/aaaa format")
            {
                REQUIRE(date.format() == "05/03/0945");
            }
        }
    }

    GIVEN("A number N of days from the zero")
    {
        WHEN("N is equals to one")
        {
            int days = 1;

            THEN("the corresponding date is 01/01/0000")
            {
                Date date = Date::from_days(days);

                REQUIRE(date.format() == "01/01/0000");
            }
        }
    }
}

SCENARIO("Date operations", "[date]")
{
    GIVEN("The date 28/02/2000")
    {
        Date date(28, 2, 2000);

        WHEN("We add two days to it") 
        {
            date.add(2);

            THEN("we get the date 01/03/2000, because 2000 is a leap year")
            {
                REQUIRE(date.format() == "01/03/2000");
            }
        }
    }

    GIVEN("The date 28/02/1900")
    {
        Date date(28, 2, 1900);
 
        WHEN("We add two days to it")
        {
            date.add(2);

            THEN("we get the date 02/03/1999, because 1900 is not a leap year")
            {
                REQUIRE(date.format() == "02/03/1900");
            }
        }
    }

    GIVEN("Two dates: a = 01/06/1999 and b = 01/06/2000")
    {
        Date a(1, 6, 1999), b(1, 6, 2000);

        WHEN("We compute the date difference between b and a")
        {
            auto days = b - a;

            THEN("the difference is equals to 366 days, because 2000 is a leap year")
            {
                REQUIRE(days == 366);
            }
        }
    }
}
