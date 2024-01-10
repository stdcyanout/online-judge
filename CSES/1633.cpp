#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define MOD 1000000007

using namespace std;

ll dp[1000001];

inline ll sum(int l,int r)
{
    if(l<0)
        l=0;
    ll s=0;
    int i;
    for(i=l;i<=r;i++)
    {
        s=(s+dp[i])%MOD;
    }
    return s;
}

int main()
{
    quick
    int n,i;
    cin >> n;
    dp[0]=1;
    for(i=1;i<=n;i++)
    {
        dp[i]=sum(i-6,i-1);
    }
    cout << dp[n] << "\n";
}
