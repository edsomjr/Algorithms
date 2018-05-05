#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include <cstdlib>
#include <ctime>
#include "data_structures/segment_tree_with_lazy_propagation.h"

using std::min;
using std::max;

SCENARIO("segment tree range update with lazy propagation", "[segtree]")
{
    GIVEN("a tree filled with a vector ns of integers")
    {
        // Generates N random numbers between [-1000000, 1000000]
        srand(time(NULL));

        int N = (rand() % 1000) + 1, s = 0;
        vector<int> ns(N, 0);

        for (int i = 0; i < N; ++i)
        {
            ns[i] = (rand() % 2000001) - 1000000;
            s += ns[i];
        }

        SegmentTree<int> tree(N);

        for (int i = 0; i < N; ++i)
            tree.add(i, i, ns[i]);

        REQUIRE(tree.sum(0, N - 1) == s);

        WHEN("a random segment [a,b] is updated with a random value v")
        {
            THEN("each segment [a,b] matches (ns[a] + ns[a+1] + ... + ns[b])")
            {
                for (int sample = 0; sample < 1000; ++sample)
                {
                    int i = rand() % N, j = rand() % N;
                    int a = min(i, j), b = max(i, j);
                    int v = (rand() % 2000001) - 1000000;

                    for (int k = a; k <= b; ++k)
                        ns[k] += v;

                    tree.add(a, b, v);

                    i = rand() % N, j = rand() % N;
                    a = min(i, j), b = max(i, j);
        
                    s = 0;

                    for (int k = a; k <= b; ++k)
                        s += ns[k];

                    REQUIRE(tree.sum(a, b) == s);
                }
            }
        }
    }
}

