#pragma GCC optimize("Ofast,unroll-loops")
#include <stdio.h>
signed main()
{
    int k;
    scanf("%d", &k);
    k = k / 7 + (k % 7 != 0);
    printf("%d\n", k * 5);
}