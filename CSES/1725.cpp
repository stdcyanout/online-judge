#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

double dp[101][601];

int main()
{
    int n,a,b,i,j,k;
    double ans=0;
    cin >> n >> a >> b;
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=i*6;j++)
        {
            for(k=max(0,j-6);k<=j-1;k++)
                dp[i][j]+=dp[i-1][k];
            dp[i][j]/=6;
        }
    }

    for(;a<=b;a++)
    {
        ans+=dp[n][a];
    }

    cout << fixed << setprecision(6) << ans << "\n";
}
