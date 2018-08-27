#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "graph/has_cycle.h"

using ii = pair<int, int>;

SCENARIO("cycle detection", "[graph]")
{
    GIVEN("An undirected graph")
    {
        WHEN("there is just one vertex")
        {
            THEN("there is no cycle")
            {
                REQUIRE(has_cycle(1) == false);
            }
        }

        WHEN("there is just two connected vertices")
        {
            vector<ii> edges { ii(1, 2) };

            for (int u = 1; u <= 2; ++u)
                adj[u].clear();

            for (const auto& edge : edges)
            {
                auto u = edge.first;
                auto v = edge.second;

                adj[u].push_back(v);
                adj[v].push_back(u);
            }


            THEN("there is no cycle")
            {
                REQUIRE(has_cycle(2) == false);
            }
        }

        WHEN("the graph is 3-complete")
        {
            vector<ii> edges { ii(1, 2), ii(1, 3), ii(2, 3) };

            for (int u = 1; u <= 3; ++u)
                adj[u].clear();

            for (const auto& edge : edges)
            {
                auto u = edge.first;
                auto v = edge.second;

                adj[u].push_back(v);
                adj[v].push_back(u);
            }


            THEN("there is a cycle")
            {
                REQUIRE(has_cycle(3) == true);
            }
        }

        WHEN("the graph is connected with more edges than vertices")
        {
            vector<ii> edges { ii(1, 2), ii(1, 3), ii(2, 3), ii(2, 5), ii(2, 6),
                ii(3, 4), ii(3, 10), ii(5, 6), ii(5, 7), ii(6, 9), ii(6, 10),
                ii(7, 8), ii(7, 9), ii(8, 9) };

            for (int u = 1; u <= 10; ++u)
                adj[u].clear();

            for (const auto& edge : edges)
            {
                auto u = edge.first;
                auto v = edge.second;

                adj[u].push_back(v);
                adj[v].push_back(u);
            }


            THEN("there is a cycle")
            {
                REQUIRE(has_cycle(10) == true);
            }
        }


    }
}
