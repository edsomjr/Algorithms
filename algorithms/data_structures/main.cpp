#include <iostream>
#include "segment_tree_pu.h"

using namespace std;

int main()
{
    int a[] { 0, 4, -1, 3, -2, 1, 8, 5 }; 
    
    for (int i = 0; i < 8; ++i)
        elements[i] = a[i];

    SegmentTree tree(8);

    printf("a[] =\n");
    for (int i = 0; i < 8; ++i)
        printf("%3d", i);
    printf("\n");

    for (int i = 0; i < 8; ++i)
        printf("%3lld", elements[i]);
    printf("\n");

    int is[] { 2, 0, 1, 5, 6, 7, 4 };
    int js[] { 5, 7, 3, 7, 7, 7, 6 };

    for (int i = 0; i < 7; ++i)
        printf("RMQ(%d, %d) = %lld\n", is[i], js[i], tree.RMQ(is[i], js[i]));

    tree.update(4, -6);

    printf("a[] =\n");
    for (int i = 0; i < 8; ++i)
        printf("%3d", i);
    printf("\n");

    for (int i = 0; i < 8; ++i)
        printf("%3lld", elements[i]);
    printf("\n");

    for (int i = 0; i < 7; ++i)
        printf("RMQ(%d, %d) = %lld\n", is[i], js[i], tree.RMQ(is[i], js[i]));
 
    return 0;
}
