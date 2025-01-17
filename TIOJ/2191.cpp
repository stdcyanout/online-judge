#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
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

const int INF = int(1) << 60;
vector<array<int, 3>> v;
vector<int> res;
int dp[2][300005];

bool ud(pii p)
{
    if(p.Y == 0)
        return p.X > 0;
    return p.Y > 0;
}

bool cmp(const array<int, 3>& a, const array<int, 3>& b)
{
    return a[0] * b[1] - a[1] * b[0] > 0;
}

signed main()
{
    fastio;
    int n, x, y, w, i, ans = 0, tmp = INF, sum = 0;
    cin >> n;
    rep(i, n)
    {
        cin >> x >> y >> w;
        if(ud({x, y}))
            v.pb({x, y, w});
        else
            v.pb({-x, -y, w});
    }
    sort(all(v), cmp);
    rep(i, n)
    {
        if(i == 0 || (v[i - 1][0] * v[i][1] - v[i - 1][1] * v[i][0] > 0))
            res.pb(v[i][2]);
        else
            res.back() += v[i][2];
    }
    rep(i, res.size())
    {
        dp[0][i + 1] = max(dp[0][i] + res[i], res[i]);
        ans = max(ans, dp[0][i + 1]);
        dp[1][i + 1] = min(dp[1][i] + res[i], res[i]);
        tmp = min(tmp, dp[1][i + 1]);
        sum += res[i];
    }
    cout << max(ans, sum - tmp) << "\n";
}