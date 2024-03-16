#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long
using namespace std;

int dp[1001][1001];

signed main()
{
    fastIO
    string s,t;
    int i,j;
    while(cin >> s >> t)
    {
        for(i=0;i<1001;i++)
            memset(dp[i],0,sizeof(dp[i]));
        for(i=0;i<s.length();i++)
        {
            for(j=0;j<t.length();j++)
            {
                if(s[i]==t[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        cout << dp[s.length()][t.length()] << "\n";
    }
}