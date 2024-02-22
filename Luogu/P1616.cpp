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

int a[10001],b[10001],dp[10000001];

signed main()
{
    fastIO
    int t,m,i,j;
    cin >> t >> m;
    for(i=1;i<=m;i++)
        cin >> a[i] >> b[i];
    for(i=1;i<=t;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[j]<=i)
                dp[i]=max(dp[i],dp[i-a[j]]+b[j]);
        }
    }
    cout << dp[t] << "\n";
}