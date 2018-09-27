#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "graph/bipartite.h"

SCENARIO("bipartite graph", "[graph]")
{
    GIVEN("An undirected graph")
    {
        for (int u = 0; u < MAX; ++u)
            adj[u].clear();

        visited.reset();

        WHEN("there is just one vertex")
        {
            THEN("the graph is bipartite")
            {
                REQUIRE(is_bipartite(1) == true);
            }
        }

        WHEN("the graph is 3-complete")
        {
            adj[1] = {2, 3};
            adj[2] = {1, 3};
            adj[3] = {1, 2};

            THEN("it is not bipartite")
            {
                REQUIRE(is_bipartite(1) == false);
            }
        }

        WHEN("the graph is bipartite")
        {
            vector<ii> edges { ii(1, 2), ii(1, 3), ii(1, 4), ii(1, 5), ii(2, 6), ii(3, 6), 
                ii(4, 8), ii(5, 7), ii(6, 9), ii(7, 9), ii(8, 9), ii(9, 10) };

            for (const auto& edge : edges)
            {
                int u, v;
                tie(u, v) = edge;

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            THEN("the function is_bipartite() must return true")
            {
                REQUIRE(is_bipartite(1) == true);
            }
        }
    }
}
