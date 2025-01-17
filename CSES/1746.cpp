#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;31m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

const int MOD = 1e9 + 7;
int a[100001], dp[100001][102];

signed main()
{
    fastio;
    int n, m, i, j, ans = 0;
    cin >> n >> m;
    foo(i, 1, n)
        cin >> a[i];
    if(a[1] == 0)
        foo(i, 1, m)
            dp[1][i] = 1;
    else
        dp[1][a[1]] = 1;
    foo(i, 2, n)
    {
        if(a[i])
            dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
        else foo(j, 1, m)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
    }
    foo(i, 1, m)
        ans = (ans + dp[n][i]) % MOD;
    cout << ans << "\n";
}