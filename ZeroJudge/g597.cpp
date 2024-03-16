#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[200001],t[200001];
signed main()
{
    //ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,l,r,w,i;
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> l >> r >> w;
        dp[l]+=w;
        dp[r+1]-=w;
    }
    for(i=0;i<=n;i++)
    {
        dp[i]+=dp[i-1];
    }
    for(i=0;i<n;i++)
    {
        cin >> t[i];
    }
    
    sort(dp+1,dp+n+1,greater<int>());
    sort(t,t+n);
    
    int ans=0;
    for(i=0;i<n;i++)
    {
        ans+=dp[i+1]*t[i];
    }
    
    cout << ans << "\n";
}