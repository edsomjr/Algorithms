#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include "graph/dfs.h"

vector<int> ans;

void process(int u)
{
    ans.push_back(u);
}

SCENARIO("dfs traversal", "[graph]")
{
    GIVEN("A undirected graph")
    {
        for (int u = 0; u < MAX; ++u)
            adj[u].clear();

        visited.reset();
        ans.clear();


        WHEN("there is just one vertex")
        {
            THEN("the DFS must return [1]")
            {
                vector<int> res { 1 };
                dfs(1, process);
 
                REQUIRE(ans == res);
            }
        }

        WHEN("there is 4 connected vertices")
        {
            adj[1].push_back(3);
            adj[3].push_back(1);
            adj[1].push_back(4);
            adj[4].push_back(1);
            adj[3].push_back(4);
            adj[4].push_back(3);
            adj[2].push_back(4);
            adj[4].push_back(2);

            THEN("the DFS must return [1, 3, 4, 2]")
            {
                vector<int> res { 1, 3, 4, 2 };
                dfs(1, process);

                REQUIRE(ans == res);
            }
        }

        WHEN("there is 4 unconnected vertices")
        {
            adj[1].push_back(3);
            adj[3].push_back(1);
            adj[2].push_back(4);
            adj[4].push_back(2);

            THEN("the DFS must return [1, 3]")
            {
                vector<int> res { 1, 3 };
                dfs(1, process);

                REQUIRE(ans == res);
            }
        }
    }
}
