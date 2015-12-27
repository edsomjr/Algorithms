#include "lis.h"

using namespace std;

int main()
{
    vector<int> A { -7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4 };

    cout << LIS::greedy(A) << endl;

    return 0;
}
