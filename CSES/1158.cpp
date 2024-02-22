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

int h[1001],s[1001],dp[100001];

signed main()
{
    fastIO
    int n,x,i,j;
    cin >> n >> x;
    for(i=1;i<=n;i++)
        cin >> h[i];
    for(i=1;i<=n;i++)
        cin >> s[i];
    for(i=1;i<=n;i++)
    {
        for(j=x;j>=h[i];j--)
        {
            dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
    cout << dp[x] << "\n";
}