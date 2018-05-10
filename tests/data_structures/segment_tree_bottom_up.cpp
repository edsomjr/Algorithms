#define CATCH_CONFIG_MAIN
#include "tests/catch.hpp"

#include <cstdlib>
#include <ctime>
#include "data_structures/segment_tree_non_recursive.h"

SCENARIO("segment tree initialization", "[segtree]")
{
    GIVEN("a positive integer N")
    {
        int N = 1000;

        REQUIRE(N > 0);

        WHEN("a segment tree is initialized")
        {
            SegmentTree<int> tree(N);

            THEN("the segment tree has size equals to a power of 2")
            {
                int size = tree.size();

                REQUIRE(size > 0);
                REQUIRE(least_significant_bit(size) == size);
            }
        }
    }
}

SCENARIO("segment tree point update", "[segtree]")
{
    GIVEN("a random vector ns of integers")
    {
        // Generates N random numbers between [-1000000, 1000000]
        srand(time(NULL));

        int N = (rand() % 1000) + 1;
        vector<int> ns(N, 0);

        for (int i = 0; i < N; ++i)
            ns[i] = (rand() % 2000001) - 1000000;

        WHEN("a segment tree is filled with ns")
        {
            SegmentTree<int> tree(N);

            for (int i = 0; i < N; ++i)
                tree.add(i, ns[i]);

            THEN("each segment tree leaf i matches ns[i]")
            {
                for (int i = 0; i < N; ++i)
                    REQUIRE(tree.sum(i, i) == ns[i]);
            }
        }
    }
}

SCENARIO("segment tree range sum", "[segtree]")
{
    GIVEN("a random vector ns of integers")
    {
        // Generates N random numbers between [-1000000, 1000000]
        srand(time(NULL));

        int N = (rand() % 1000) + 1;
        vector<int> ns(N, 0);

        for (int i = 0; i < N; ++i)
            ns[i] = (rand() % 2000001) - 1000000;

        WHEN("a segment tree is filled with ns")
        {
            SegmentTree<int> tree(N);

            for (int i = 0; i < N; ++i)
                tree.add(i, ns[i]);

            THEN("each segment [i, j] sum matches the (ns[i] + ns[i+1] + ... + ns[j])")
            {
                for (int i = 0; i < N; ++i)
                    for (int j = i; j < N; ++j)
                    {
                        int s = 0;

                        for (int k = i; k <= j; ++k)
                            s += ns[k];

                        REQUIRE(tree.sum(i, j) == s);
                    }
            }
        }
    }

    GIVEN("a random vector ns of integers")
    {
        // Generates N random numbers between [-1000000, 1000000]
        srand(time(NULL));

        int N = (rand() % 1000) + 1;
        vector<int> ns(N, 0);

        for (int i = 0; i < N; ++i)
            ns[i] = (rand() % 2000001) - 1000000;

        WHEN("a segment tree is filled with ns and random values are added to random elements n[i]")
        {
            SegmentTree<int> tree(N);

            for (int i = 0; i < N; ++i)
                tree.add(i, ns[i]);

            int M = (rand() % 1000) + 1;

            while (M--)
            {
                int i = rand() % N;
                int v = (rand() % 2000001) - 1000000;

                ns[i] += v;
                tree.add(i, v);
            }

            THEN("each segment [i, j] sum matches the (ns[i] + ns[i+1] + ... + ns[j])")
            {
                for (int i = 0; i < N; ++i)
                    for (int j = i; j < N; ++j)
                    {
                        int s = 0;

                        for (int k = i; k <= j; ++k)
                            s += ns[k];

                        REQUIRE(tree.sum(i, j) == s);
                    }
            }
        }
    }
}
