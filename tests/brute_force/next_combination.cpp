#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include <vector>
#include "brute_force/next_combination.h"

using namespace std;

SCENARIO("Next combination generation", "[brute force]")
{
    GIVEN("A number N of elements")
    {
        int N = 10;

        WHEN("We list all possible trio of these elements")
        {
            vector<string> a, b;
            string s(3, '1');
            s.resize(N, '0'); 

            do {
                a.push_back(s);
            } while (prev_permutation(s.begin(), s.end()));

            s = "";
            int x, y;

            while (next_combination(N, 3, s, x, y))
                b.push_back(s);

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            THEN("then we get 120 different trios")
            {
                REQUIRE(a == b);
            }
        }
    }
}
