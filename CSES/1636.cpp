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

int c[101],dp[1000001];

signed main()
{
    fastIO
    int n,x,i,j;
    cin >> n >> x;
    for(i=0;i<n;i++)
        cin >> c[i];
    dp[0]=1;
    for(i=0;i<n;i++)
    {
        for(j=c[i];j<=x;j++)
            dp[j]=(dp[j]+dp[j-c[i]])%MOD;
    }
    cout << dp[x] << "\n";
}