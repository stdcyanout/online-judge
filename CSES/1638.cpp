#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define MOD 1000000007

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

char c[1001][1001];
int dp[1001][1001];


signed main()
{
    fastIO
    int n,i,j;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> c[i][j];
        }
    }
    dp[1][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(c[i][j]!='*')
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    cout << dp[n][n] << "\n";
}