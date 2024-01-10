#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    fastIO
    int_fast16_t n;
    cin >> n;
    cout << n*(n+1)/2+1 << "\n";
}
