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

const int INF = 0x3F3F3F3F3F3F3F3F;
int a[1000001], b[1000001], c[1000001], d[1000001], dp[1000001][2];

signed main()
{
    fastio;
    int n, i, s1 = 0, s2 = 0;
    cin >> n;
    foo(i, 1, n) cin >> a[i], s1 += a[i];
    foo(i, 1, n) cin >> b[i], s2 += b[i];
    foo(i, 1, n)
    {
        c[i] = b[i] - a[i];
        d[i] = a[i] - b[i];
    }
    array<int, 3> r1 = {~INF, 0, 0}, r2 = {~INF, 0, 0};
    foo(i, 1, n)
    {
        if(dp[i - 1][0] + c[i] > c[i])
            dp[i][0] = dp[i - 1][0] + c[i], dp[i][1] = dp[i - 1][1];
        else
            dp[i][0] = c[i], dp[i][1] = i;
        if(dp[i][0] > r1[0])
            r1 = {dp[i][0], dp[i][1], i};
    }
    foo(i, 1, n)
    {
        if(dp[i - 1][0] + d[i] > d[i])
            dp[i][0] = dp[i - 1][0] + d[i], dp[i][1] = dp[i - 1][1];
        else
            dp[i][0] = d[i], dp[i][1] = i;
        if(dp[i][0] > r2[0])
            r2 = {dp[i][0], dp[i][1], i};
    }
    // orange(d + 1, d + n + 1);
    // orange(all(r1));
    // orange(all(r2));
    if(r1[0] > 0)
        r1[0] += s1;
    else
        r1 = {s1, -1, -1};
    if(r2[0] > 0)
        r2[0] += s2;
    else
        r2 = {s2, -1, -1};
    if(r1[0] > r2[0])
        cout << r1[0] << ' ' << r1[1] << ' ' << r1[2] << '\n';
    else
        cout << r2[0] << ' ' << r2[1] << ' ' << r2[2] << '\n';
}