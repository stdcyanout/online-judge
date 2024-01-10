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

int dp[100];

signed main()
{
    fastIO
    int i,n;
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<100;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    while(cin >> n)
    {
        cout << dp[n] << "\n";
    }
}