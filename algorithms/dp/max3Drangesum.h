#include <iostream>

using namespace std;

#define MAX 22

long long M[MAX][MAX][MAX];

int main()
{
    int T;
    scanf("%d", &T);

    for (int test = 0; test < T; ++test)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);

        for (int x = 0; x < A; ++x)
        for (int y = 0; y < B; ++y)
        for (int z = 0; z < C; ++z)
        {
            scanf("%lld", &M[x][y][z]);

            if (x > 0) M[x][y][z] += M[x - 1][y][z];
            if (y > 0) M[x][y][z] += M[x][y - 1][z];
            if (z > 0) M[x][y][z] += M[x][y][z - 1];

            if (x > 0 and y > 0) M[x][y][z] -= M[x - 1][y - 1][z];
            if (x > 0 and z > 0) M[x][y][z] -= M[x - 1][y][z - 1];
            if (y > 0 and y > 0) M[x][y][z] -= M[x][y - 1][z - 1];
        
            if (x > 0 and y > 0 and z > 0) M[x][y][z] += M[x-1][y-1][z-1];
        }

        long long max_sum = -(1LL << 60);

        for (int x = 0; x < A; ++x)
        for (int y = 0; y < B; ++y)
        for (int z = 0; z < C; ++z)
        for (int a = x; a < A; ++a)
        for (int b = y; b < B; ++b)
        for (int c = z; c < C; ++c)
        {
            long long sum = M[a][b][c];

            if (x > 0) sum -= M[x - 1][b][c];
            if (y > 0) sum -= M[a][y - 1][c];
            if (z > 0) sum -= M[a][b][z - 1];

            if (x > 0 and y > 0) sum += M[x - 1][y - 1][c];
            if (x > 0 and z > 0) sum += M[x - 1][b][z - 1];
            if (y > 0 and y > 0) sum += M[a][y - 1][z - 1];
        
            if (x > 0 and y > 0 and z > 0) sum -= M[x-1][y-1][z-1];

            max_sum = max(sum, max_sum);
        }

        if (test) printf("\n");

        printf("%lld\n", max_sum);
    }

    return 0;
}
