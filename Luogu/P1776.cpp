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

int dp[40001];

signed main()
{
    fastIO
    int n,W,v,w,m,i,j,tmp;
    cin >> n >> W;
    for(i=1;i<=n;i++)
    {
        cin >> v >> w >> m;
        for(tmp=1;tmp<=m;tmp<<=1)
        {
            m-=tmp;
            for(j=W;j>=tmp*w;j--)
            {
                dp[j]=max(dp[j],dp[j-tmp*w]+tmp*v);
            }
        }
        if(m)
        {
            for(j=W;j>=m*w;j--)
            {
                dp[j]=max(dp[j],dp[j-m*w]+m*v);
            }
        }
    }
    cout << dp[W] << "\n";
}