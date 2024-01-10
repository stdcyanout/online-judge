#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int sum;

int main()
{
    quick
    int n,i;
    cin >> n;
    for(i=5;i<=n;i*=5)
    {
        sum+=n/i;
    }
    cout << sum << "\n";
}
