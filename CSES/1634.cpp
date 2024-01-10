#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3F3F3F3F

using namespace std;

int coins[101],dp[1000001];

int main()
{
    fastIO
    memset(dp,0x3F,sizeof(dp));
    dp[0]=0;
    int n,x,i,j;
    cin >> n >> x;
    for(i=0;i<n;i++)
        cin >> coins[i];
    for(i=0;i<n;i++)
    {
        for(j=coins[i];j<=x;j++)
        {
            if(dp[j-coins[i]]!=INF)
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
        }
    }
    if(dp[x]!=INF)
        cout << dp[x] << "\n";
    else
        cout << -1 << "\n";
}
