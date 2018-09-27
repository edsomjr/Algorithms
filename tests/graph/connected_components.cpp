#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "graph/connected_components.h"

using ii = pair<int, int>;

SCENARIO("dfs traversal", "[graph]")
{
    GIVEN("An unconnected undirected graph")
    {
        vector<ii> edges { ii(1, 2), ii(1, 8), ii(2, 10), ii(3, 7), ii(4, 5),
            ii(4, 9), ii(5, 9) };

        for (const auto& edge : edges)
        {
            auto u = edge.first;
            auto v = edge.second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        WHEN("there is more then one component")
        {
            THEN("the algorithm mustmust return all of them")
            {
                vector<vector<int>> res { {1, 2, 10, 8}, {3, 7}, {4, 5, 9}, {6}};
                auto ans = connected_components(10);
 
                REQUIRE(ans.size() == res.size());
                REQUIRE(ans == res);
            }
        }
    }
}
