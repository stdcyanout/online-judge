#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int main()
{
    quick
    ll n,i;
    cin >> n;
    for(i=1;i<=n;i++)
        cout << i*i*(i*i-1)/2-4*(i-1)*(i-2) << "\n";
}
