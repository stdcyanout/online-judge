#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int x[150001],dp[21][150001];

signed main()
{
    fastIO
    int n,k,i,j;
    cin >> n >> k;
    for(j=1;j<=n;j++)
    {
        cin >> x[j];
        dp[0][j]=max(dp[0][j-1]+x[j],0ll);
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],dp[i][j-1]+x[j]);
        }
    }
    cout << *max_element(dp[k]+1,dp[k]+n+1) << "\n";
}