#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

ll dp[200001];

int main()
{
    int n,i;
    ll t,maxsum=LONG_LONG_MIN;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> t;
        dp[i]=max(t,dp[i-1]+t);
        maxsum=max(maxsum,dp[i]);
    }
    cout << maxsum << "\n";
}
